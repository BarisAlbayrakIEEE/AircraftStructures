/// <summary>
/// Defines 2D cross-sectional shape
/// 
/// CAUTION:
///     See AircraftStructuresSample repository for sample usage of the library.
/// 
/// INVARIANT:
///   Segments must not crash but share edges (TODO: not implemented yet)
/// 
/// ASSUMPTION:
///   The segments/sections are assumed to be symmetrical about y-axis for simplicity
/// 
/// The copy/move ctors and operators of Section class are private to prevent slicing.
/// 
/// author: baris.albayrak.ieee@gmail.com
/// github: https://github.com/BarisAlbayrakIEEE?tab=repositories
/// </summary>

#pragma warning(disable : 4250) // disable diamond inheritance with dominance
#pragma warning(disable : 4290) // disable throw(SomeException)

#ifndef _Section_h
#define _Section_h

#include <vector>
#include <algorithm>
#include "Segment.h"

namespace AircraftStructures {
	class Section {
		friend class GSP;
		friend class Rib;
		friend class Spar;
		friend class Frame;
		friend class Component;
		friend class Panel;
		friend class Stiffener;
		friend class Material;
		friend class SectionBox;
		friend class SectionI;
		friend class SectionJ;
		friend class Segment;

	protected:
		std::vector<shared_ptr<Segment>> c_segments;
		double c_centroid; // Centroid wrt x-axis. See assumption in header docstring
		double c_Area;
		double c_FMA; // First moment of area wrt x-axis at the section centroid
		double c_SMA; // Second moment of area, inertia wrt x-axis at the section centroid

	public:
		Section();
		Section(std::vector<std::shared_ptr<Segment>>& theSegments);
		bool operator==(const Section& rhs);
		bool operator!=(const Section& rhs);

		Section(const Section&) = default; // Shallow copy
		Section& operator=(const Section&) = default; // Shallow copy
		Section(Section&&) = default;
		Section& operator=(Section&&) = default;

		virtual ~Section();

	public:
		std::vector<shared_ptr<Segment>> getSegments() const { return c_segments; }
		double getCentroid() const { return c_centroid; }
		double getArea() const { return c_Area; }
		double getFMA() const { return c_FMA; }
		double getSMA() const { return c_SMA; }

	protected:
		void setSegments(std::vector<shared_ptr<Segment>>& theSegments);
		void setProperties(std::vector<shared_ptr<Segment>>& theSegments);
	};



	class SectionBox : public Section {
		friend class GSP;
		friend class Rib;
		friend class Spar;
		friend class Frame;
		friend class Component;
		friend class Panel;
		friend class Stiffener;
		friend class Material;
		friend class Section;
		friend class SectionI;
		friend class SectionJ;
		friend class Segment;

	public:
		SectionBox(double theWidth, double theHeight);
		SectionBox(const SectionBox&) = default;
		SectionBox& operator=(const SectionBox&) = default;
		SectionBox(SectionBox&&) = default;
		SectionBox& operator=(SectionBox&&) = default;
		bool operator==(const SectionBox& rhs) { return Section::operator==(rhs); }
		bool operator!=(const SectionBox& rhs) { return Section::operator!=(rhs); }

		~SectionBox() {};
	};



	class SectionI : public Section {
		friend class GSP;
		friend class Rib;
		friend class Spar;
		friend class Frame;
		friend class Component;
		friend class Panel;
		friend class Stiffener;
		friend class Material;
		friend class Section;
		friend class SectionBox;
		friend class SectionJ;
		friend class Segment;

	public:
		SectionI(
			double wl1,
			double tl1,
			double wl2,
			double tl2,
			double tweb,
			double hweb,
			double wf1,
			double tf1,
			double wf2,
			double tf2);
		SectionI(const SectionI&) = default;
		SectionI& operator=(const SectionI&) = default;
		SectionI(SectionI&&) = default;
		SectionI& operator=(SectionI&&) = default;
		bool operator==(const SectionI& rhs) { return Section::operator==(rhs); }
		bool operator!=(const SectionI& rhs) { return Section::operator!=(rhs); }

		~SectionI() {};
	};



	class SectionJ : public Section {
		friend class GSP;
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
		friend class Segment;

	public:
		SectionJ(
			double wl1,
			double tl1,
			double wl2,
			double tl2,
			double tweb,
			double hweb,
			double wf,
			double tf);
		SectionJ(const SectionJ&) = default;
		SectionJ& operator=(const SectionJ&) = default;
		SectionJ(SectionJ&&) = default;
		SectionJ& operator=(SectionJ&&) = default;
		bool operator==(const SectionJ& rhs) { return Section::operator==(rhs); }
		bool operator!=(const SectionJ& rhs) { return Section::operator!=(rhs); }

		~SectionJ() {};
	};
}

#endif
