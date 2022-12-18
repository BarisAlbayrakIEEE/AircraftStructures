/// <summary>
/// Spar is a GSP used to support the wing against the bending loads.
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

#ifndef _Spar_h
#define _Spar_h

#include "GSP.h"

namespace AircraftStructures {
	class Spar : public GSP {
		friend class GSP;
		friend class Rib;
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
		Spar() : GSP() {}
		Spar(const int theRowCount, const int theClmCount) : GSP(theRowCount, theClmCount) {}
		Spar(
			GRID(Panel)& thePanels,
			GRID(HorizontalStiffener)& theHSs,
			GRID(VerticalStiffener)& theVSs)
			: GSP(thePanels, theHSs, theVSs) {}
		Spar(const Spar&) = default; // Shallow copy
		Spar& operator=(const Spar&) = default; // Shallow copy
		Spar(Spar&&) = default;
		Spar& operator=(Spar&&) = default;
		bool operator==(const Spar& rhs) { return GSP::operator==(rhs); }
		bool operator!=(const Spar& rhs) { return GSP::operator!=(rhs); }
		~Spar() {};
	};
}

#endif
