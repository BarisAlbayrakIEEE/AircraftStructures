/// <summary>
/// Frame is a GSP used to maintain the shape of the fuselage.
/// The additional members will be imlemented later.
/// Currently an empty class
/// 
/// CAUTION:
///     See AircraftStructuresSample repository for sample usage of the library.
/// 
/// INVARIANT:
///   Currently no invariant
/// 
/// author: baris.albayrak.ieee@gmail.com
/// github: https://github.com/BarisAlbayrakIEEE?tab=repositories
/// </summary>

#pragma warning(disable : 4250) // disable diamond inheritance with dominance
#pragma warning(disable : 4290) // disable throw(SomeException)

#ifndef _Frame_h
#define _Frame_h

#include "GSP.h"

namespace AircraftStructures {
	class Frame : public GSP {
		friend class GSP;
		friend class Rib;
		friend class Spar;
		friend class Component;
		friend class Panel;
		friend class Stiffener;
		friend class Material;
		friend class Section;
		friend class SectionBox;
		friend class SectionI;
		friend class SectionJ;
		friend class Segment;

	public:
		Frame() : GSP() {}
		Frame(const int theRowCount, const int theClmCount) : GSP(theRowCount, theClmCount) {}
		Frame(
			GRID(Panel)& thePanels,
			GRID(HorizontalStiffener)& theHSs,
			GRID(VerticalStiffener)& theVSs)
			: GSP(thePanels, theHSs, theVSs) {}
		Frame(const Frame&) = default; // Shallow copy
		Frame& operator=(const Frame&) = default; // Shallow copy
		Frame(Frame&&) = default;
		Frame& operator=(Frame&&) = default;
		bool operator==(const Frame& rhs) { return GSP::operator==(rhs); }
		bool operator!=(const Frame& rhs) { return GSP::operator!=(rhs); }
		~Frame() {};
	};
}

#endif
