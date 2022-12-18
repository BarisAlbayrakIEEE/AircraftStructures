#include <algorithm>
#include "GSP.h"
using namespace std;

namespace AircraftStructures {
	GSP::GSP(const int theRowCount, const int theClmCount)
	{
		setGrid(theRowCount, theClmCount);
	}

	GSP::GSP(
		GRID(Panel)& thePanels,
		GRID(HorizontalStiffener)& theHSs,
		GRID(VerticalStiffener)& theVSs)
	{
		std::array<int, 2> rowClmCounts = getRowClmCounts(
			thePanels,
			theHSs,
			theVSs);
		c_rowCount = rowClmCounts[0];
		c_clmCount = rowClmCounts[1];
		c_panels = thePanels;
		c_HSs = theHSs;
		c_VSs = theVSs;
	}

	GSP::~GSP() {
		c_rowCount = 0;
		c_clmCount = 0;
		c_panels.clear();
		c_HSs.clear();
		c_VSs.clear();
	}

	bool GSP::operator==(const GSP& rhs)
	{
		if (c_rowCount != rhs.c_rowCount) return false;
		if (c_clmCount != rhs.c_clmCount) return false;

		for (int iRow = 1; iRow < c_rowCount; ++iRow) {
			for (int iClm = 1; iClm < c_clmCount; ++iClm) {
				Panel* p1 = c_panels[iRow][iClm].get();
				Panel* p2 = rhs.c_panels[iRow][iClm].get();
				if (p1 == nullptr) {
					if (p2 != nullptr) return false;
					continue;
				}
				else if (p2 == nullptr) return false;
				if (*p1 != *p2) return false;
			}
		}

		for (int iRow = 1; iRow < c_rowCount + 1; ++iRow) {
			for (int iClm = 1; iClm < c_clmCount; ++iClm) {
				HorizontalStiffener* p1 = c_HSs[iRow][iClm].get();
				HorizontalStiffener* p2 = rhs.c_HSs[iRow][iClm].get();
				if (p1 == nullptr) {
					if (p2 != nullptr) return false;
					continue;
				}
				else if (p2 == nullptr) return false;
				if (*p1 != *p2) return false;
			}
		}

		for (int iRow = 1; iRow < c_rowCount; ++iRow) {
			for (int iClm = 1; iClm < c_clmCount + 1; ++iClm) {
				VerticalStiffener* p1 = c_VSs[iRow][iClm].get();
				VerticalStiffener* p2 = rhs.c_VSs[iRow][iClm].get();
				if (p1 == nullptr) {
					if (p2 != nullptr) return false;
					continue;
				}
				else if (p2 == nullptr) return false;
				if (*p1 != *p2) return false;
			}
		}
		return true;
	}

	bool GSP::operator!=(const GSP& rhs)
	{
		return !operator==(rhs);
	}

	std::array<int, 2> GSP::getRowClmCounts(
		GRID(Panel)& thePanels,
		GRID(HorizontalStiffener)& theHSs,
		GRID(VerticalStiffener)& theVSs) const
	{
		if (thePanels.size() == 0) throw AircraftException();
		if (thePanels.size() + 1 != theHSs.size()) throw AircraftException();
		if (thePanels.size() != theVSs.size()) throw AircraftException();

		int rowCount = thePanels.size();
		int clmCount = thePanels[0].size();
		for (int iRow = 1; iRow < thePanels.size(); ++iRow) {
			if (thePanels[iRow].size() != clmCount) throw AircraftException();
			if (theHSs[iRow].size() != clmCount) throw AircraftException();
			if (theVSs[iRow].size() != clmCount + 1) throw AircraftException();
		}

		std::array<int, 2> rowClmCount{ {rowCount, clmCount} };
		return rowClmCount;
	}

	void GSP::setGrid(const int theRowCount, const int theClmCount)
	{
		if (theRowCount < 1) throw AircraftException();
		if (theClmCount < 1) throw AircraftException();

		c_rowCount = theRowCount;
		c_clmCount = theClmCount;
		c_panels.clear();
		c_HSs.clear();
		c_VSs.clear();
		for (int iRow = 0; iRow < theRowCount; ++iRow)
		{
			LINEAR(Panel) panels;
			LINEAR(HorizontalStiffener) HSs;
			LINEAR(VerticalStiffener) VSs;
			for (int iClm = 0; iClm < theClmCount; ++iClm)
			{
				std::shared_ptr<Panel> panel;
				std::shared_ptr<HorizontalStiffener> HS;
				std::shared_ptr<VerticalStiffener> VS;
				panels.push_back(panel);
				HSs.push_back(HS);
				VSs.push_back(VS);
			}
			std::shared_ptr<VerticalStiffener> VS;
			VSs.push_back(VS);
			c_panels.push_back(panels);
			c_HSs.push_back(HSs);
			c_VSs.push_back(VSs);
		}
		LINEAR(HorizontalStiffener) HSs;
		for (int iClm = 0; iClm < theClmCount; ++iClm)
		{
			std::shared_ptr<HorizontalStiffener> HS;
			HSs.push_back(HS);
		}
		c_HSs.push_back(HSs);
	}

	shared_ptr<HorizontalStiffener> GSP::getPanelHorizontalStiffener(int iRow, int iClm, int iStiffener) const
	{
		inspectRowClmPanel(iRow, iClm, iStiffener);

		if (iStiffener == 0) {
			return c_HSs[iRow][iClm];
		}
		return c_HSs[iRow + 1][iClm];
	}

	shared_ptr<VerticalStiffener> GSP::getPanelVerticalStiffener(int iRow, int iClm, int iStiffener) const
	{
		inspectRowClmPanel(iRow, iClm, iStiffener);

		if (iStiffener == 0) {
			return c_VSs[iRow][iClm];
		}
		return c_VSs[iRow][iClm + 1];
	}

	shared_ptr<Panel> GSP::getHorizontalStiffenerPanel(int iRow, int iClm, int iPanel) const
	{
		inspectRowClmHorizontalStiffener(iRow, iClm, iPanel);

		if (iPanel == 0) {
			return c_panels[iRow - 1][iClm];
		}
		return c_panels[iRow][iClm];
	}

	shared_ptr<Panel> GSP::getVerticalStiffenerPanel(int iRow, int iClm, int iPanel) const
	{
		inspectRowClmVerticalStiffener(iRow, iClm, iPanel);

		if (iPanel == 0) {
			return c_panels[iRow][iClm - 1];
		}
		return c_panels[iRow][iClm];
	}

	void GSP::inspectRowClmPanel(int iRow, int iClm, int iStiffener) const
	{
		if (iRow < 0) throw AircraftException();
		if (iRow >= c_rowCount) throw AircraftException();
		if (iClm < 0) throw AircraftException();
		if (iClm >= c_clmCount) throw AircraftException();
		if (iStiffener < 0) throw AircraftException();
		if (iStiffener > 1) throw AircraftException();
	}

	void GSP::inspectRowClmHorizontalStiffener(int iRow, int iClm, int iPanel) const
	{
		if (iRow < 0) throw AircraftException();
		if (iRow > c_rowCount) throw AircraftException();
		if (iClm < 0) throw AircraftException();
		if (iClm >= c_clmCount) throw AircraftException();
		if (iPanel < 0) throw AircraftException();
		if (iPanel > 1) throw AircraftException();
		if (iRow == 0 && iPanel == 0) throw AircraftException();
		if (iRow == c_rowCount && iPanel == 1) throw AircraftException();
	}

	void GSP::inspectRowClmVerticalStiffener(int iRow, int iClm, int iPanel) const
	{
		if (iRow < 0) throw AircraftException();
		if (iRow >= c_rowCount) throw AircraftException();
		if (iClm < 0) throw AircraftException();
		if (iClm > c_clmCount) throw AircraftException();
		if (iPanel < 0) throw AircraftException();
		if (iPanel > 1) throw AircraftException();
		if (iClm == 0 && iPanel == 0) throw AircraftException();
		if (iClm == c_clmCount && iPanel == 1) throw AircraftException();
	}

	void GSP::calculateRFs() const
	{
		for (auto panels : c_panels) {
			for (auto panel : panels) {
				panel->calculateRFs();
			}
		}
		for (auto HSs : c_HSs) {
			for (auto HS : HSs) {
				HS->calculateRFs();
			}
		}
		for (auto VSs : c_VSs) {
			for (auto VS : VSs) {
				VS->calculateRFs();
			}
		}
	}
}
