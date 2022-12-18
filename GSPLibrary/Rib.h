/// <summary>
/// Rib is a GSP used to maintain the shape of the wing.
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

#ifndef _Rib_h
#define _Rib_h

#include "GSP.h"

namespace AircraftStructures {
	class Rib : public GSP {
		friend class GSP;
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

	public:
		Rib() : GSP() {}
		Rib(const int theRowCount, const int theClmCount) : GSP(theRowCount, theClmCount) {}
		Rib(
			GRID(Panel)& thePanels,
			GRID(HorizontalStiffener)& theHSs,
			GRID(VerticalStiffener)& theVSs)
			: GSP(thePanels, theHSs, theVSs) {}
		Rib(const Rib&) = default; // Shallow copy
		Rib& operator=(const Rib&) = default; // Shallow copy
		Rib(Rib&&) = default;
		Rib& operator=(Rib&&) = default;
		bool operator==(const Rib& rhs) { return GSP::operator==(rhs); }
		bool operator!=(const Rib& rhs) { return GSP::operator!=(rhs); }
		~Rib() {};
	};
}

#endif
