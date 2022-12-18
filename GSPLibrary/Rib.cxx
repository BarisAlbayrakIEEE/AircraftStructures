#include "Rib.h"

namespace AircraftStructures {
	void Rib::copyBase(const Rib& rhs)
	{
		c_rowCount = rhs.c_rowCount;
		c_clmCount = rhs.c_clmCount;

		GRID(Panel) panels;
		GRID(HorizontalStiffener) HSs;
		GRID(VerticalStiffener) VSs;
		for (int iRow = 0; iRow < rhs.c_rowCount; ++iRow)
		{
			LINEAR(Panel) panelRow;
			LINEAR(HorizontalStiffener) HSRow;
			LINEAR(VerticalStiffener) VSRow;
			for (int iClm = 0; iClm < rhs.c_clmCount; ++iClm)
			{
				shared_ptr<Panel> panel = make_shared<Panel>(
					rhs.c_panels[iRow][iClm]->getMaterial(),
					rhs.c_panels[iRow][iClm]->getSection(),
					rhs.c_panels[iRow][iClm]->getLoad(),
					rhs.c_panels[iRow][iClm]->getLength());
				shared_ptr<HorizontalStiffener> HS = make_shared<HorizontalStiffener>(
					rhs.c_HSs[iRow][iClm]->getMaterial(),
					rhs.c_HSs[iRow][iClm]->getSection(),
					rhs.c_HSs[iRow][iClm]->getLoad(),
					rhs.c_HSs[iRow][iClm]->getLength());
				shared_ptr<VerticalStiffener> VS = make_shared<VerticalStiffener>(
					rhs.c_VSs[iRow][iClm]->getMaterial(),
					rhs.c_VSs[iRow][iClm]->getSection(),
					rhs.c_VSs[iRow][iClm]->getLoad(),
					rhs.c_VSs[iRow][iClm]->getLength());
				panelRow.push_back(panel);
				HSRow.push_back(HS);
				VSRow.push_back(VS);

				/*
				* TTODO: DELETE
				panelRow.push_back(rhs.c_panels[iRow][iClm]);
				HSRow.push_back(rhs.c_HSs[iRow][iClm]);
				VSRow.push_back(rhs.c_VSs[iRow][iClm]);
				*/
			}
			panels.push_back(panelRow);
			HSs.push_back(HSRow);
			VSs.push_back(VSRow);
		}
		c_panels = panels;
		c_HSs = HSs;
		c_VSs = VSs;
	}

	void Rib::copyBase(Rib&& rhs)
	{
		c_rowCount = rhs.c_rowCount;
		c_clmCount = rhs.c_clmCount;

		GRID(Panel) panels;
		GRID(HorizontalStiffener) HSs;
		GRID(VerticalStiffener) VSs;
		for (int iRow = 0; iRow < rhs.c_rowCount; ++iRow)
		{
			LINEAR(Panel) panelRow;
			LINEAR(HorizontalStiffener) HSRow;
			LINEAR(VerticalStiffener) VSRow;
			for (int iClm = 0; iClm < rhs.c_clmCount; ++iClm)
			{
				panelRow.push_back(rhs.c_panels[iRow][iClm]);
				HSRow.push_back(rhs.c_HSs[iRow][iClm]);
				VSRow.push_back(rhs.c_VSs[iRow][iClm]);
			}
			panels.push_back(panelRow);
			HSs.push_back(HSRow);
			VSs.push_back(VSRow);
		}
		c_panels = panels;
		c_HSs = HSs;
		c_VSs = VSs;
	}

	Rib::Rib(const Rib& rhs)
	{
		/*
		* TODO: DELETE
		c_rowCount = rhs.c_rowCount;
		c_clmCount = rhs.c_clmCount;
		std::copy(rhs.c_panels.begin(), rhs.c_panels.end(), c_panels);
		std::copy(rhs.c_HSs.begin(), rhs.c_HSs.end(), c_HSs);
		std::copy(rhs.c_VSs.begin(), rhs.c_VSs.end(), c_VSs);
		*/
		copyBase(rhs);
	}

	Rib& Rib::operator=(const Rib& rhs)
	{
		copyBase(rhs);
		return *this;
	}

	Rib::Rib(Rib&& rhs)
	{
		copyBase(rhs);

		rhs.c_rowCount = 0;
		rhs.c_clmCount = 0;
		rhs.c_panels.clear();
		rhs.c_HSs.clear();
		rhs.c_VSs.clear();
	}

	Rib& Rib::operator=(Rib&& rhs)
	{
		copyBase(rhs);

		rhs.c_rowCount = 0;
		rhs.c_clmCount = 0;
		rhs.c_panels.clear();
		rhs.c_HSs.clear();
		rhs.c_VSs.clear();

		return *this;
	}
}