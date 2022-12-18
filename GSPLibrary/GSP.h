/// <summary>
/// Implementation base class for all Grid Stiffened Panels, GSPs (Rib, Spar and Framee currently).
/// Not an abstract class.
/// 
/// CAUTION:
///     See AircraftStructuresSample repository for sample usage of the library.
/// 
/// INVARIANT:
///   nRow > 1
///   nColumn > 1
/// 
/// Row and column counts for panels, HSs and VSs are as follows (subscript 0 stands for the GSP):
///     Panels:
///         nRow = nRow0
///         nClm = nClm0
///     HSs:
///         nRow = nRow0 + 1
///         nClm = nClm0
///     VSs:
///         nRow = nRow0
///         nClm = nClm0 + 1
/// 
/// The copy/move ctors and operators are private to prevent slicing.
/// 
/// author: baris.albayrak.ieee@gmail.com
/// github: https://github.com/BarisAlbayrakIEEE?tab=repositories
/// </summary>

#pragma warning(disable : 4250) // disable diamond inheritance with dominance
#pragma warning(disable : 4290) // disable throw(SomeException)

#ifndef _GSP_h
#define _GSP_h

#include <memory>
#include <vector>
#include <Panel.h>
#include <Stiffener.h>
#include "Macros.h"

namespace AircraftStructures {
	class GSP {
		friend class Rib;
		friend class Spar;
		friend class Frame;
		friend class Component;
		friend class Panel;
		friend class Stiffener;
		friend class Material;
		friend class Section;
		friend class SectionBox;
		friend class SectionI;
		friend class SectionJ;
		friend class Segment;

	protected:
		int c_rowCount;
		int c_clmCount;
		GRID(Panel) c_panels; // [iRow][iClm]
		GRID(HorizontalStiffener) c_HSs; // [iRow][iClm]
		GRID(VerticalStiffener) c_VSs; // [iRow][iClm]

	public:
		GSP() : c_rowCount{}, c_clmCount{} {}
		GSP(const int theRowCount, const int theClmCount);
		GSP(
			GRID(Panel)& thePanels,
			GRID(HorizontalStiffener)& theHSs,
			GRID(VerticalStiffener)& theVSs);
		virtual ~GSP();
		bool operator==(const GSP& rhs);
		bool operator!=(const GSP& rhs);

	private:
		GSP(const GSP& rhs) = default; // Shallow copy
		GSP& operator=(const GSP& rhs) = default; // Shallow copy
		GSP(GSP&& rhs) = default;
		GSP& operator=(GSP&& rhs) = default;

	public:
		int getRowCount() const { return c_rowCount; }
		int getClmCount() const { return c_clmCount; }
		void setGrid(const int theRowCount, const int theClmCount);
		GRID(Panel) getPanels() const { return c_panels; }
		GRID(HorizontalStiffener) getHorizontalStiffeners() const { return c_HSs; }
		GRID(VerticalStiffener) getVerticalStiffeners() const { return c_VSs; }
		void setPanels(GRID(Panel) thePanels) { c_panels = thePanels; }
		void setHorizontalStiffeners(GRID(HorizontalStiffener) theHSs) { c_HSs = theHSs; }
		void setVerticalStiffeners(GRID(VerticalStiffener) theVSs) { c_VSs = theVSs; }

	public:
		shared_ptr<HorizontalStiffener> getPanelHorizontalStiffener(int iRow, int iClm, int iStiffener) const;
		shared_ptr<VerticalStiffener> getPanelVerticalStiffener(int iRow, int iClm, int iStiffener) const;
		shared_ptr<Panel> getHorizontalStiffenerPanel(int iRow, int iClm, int iPanel) const;
		shared_ptr<Panel> getVerticalStiffenerPanel(int iRow, int iClm, int iPanel) const;

	private:
		std::array<int, 2> getRowClmCounts(
			GRID(Panel)& thePanels,
			GRID(HorizontalStiffener)& theHSs,
			GRID(VerticalStiffener)& theVSs) const;
		void inspectRowClmPanel(int iRow, int iClm, int iStiffener) const;
		void inspectRowClmHorizontalStiffener(int iRow, int iClm, int iPanel) const;
		void inspectRowClmVerticalStiffener(int iRow, int iClm, int iPanel) const;

	public:
		void calculateRFs() const;
	};
}

#endif
