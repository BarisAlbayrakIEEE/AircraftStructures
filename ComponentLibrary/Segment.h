/// <summary>
/// A segment is a rectangular piece which is used to create 2D sections.
/// 
/// CAUTION:
///     See AircraftStructuresSample repository for sample usage of the library.
/// 
/// INVARIANT:
///   Width and height must be positive real
/// 
/// author: baris.albayrak.ieee@gmail.com
/// github: https://github.com/BarisAlbayrakIEEE?tab=repositories
/// </summary>

#pragma warning(disable : 4250) // disable diamond inheritance with dominance
#pragma warning(disable : 4290) // disable throw(SomeException)

#ifndef _Segment_h
#define _Segment_h

#include <vector>
#include <AircraftException.h>
#include <AircraftMath.h>

namespace AircraftStructures {
	class Segment {
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
		friend class SectionJ;

	private:
		double c_width;
		double c_height;
		double c_location; // wrt the x-axis. See assumption in header docstring
		double c_centroid; // wrt the x-axis. See assumption in header docstring
		double c_Area;
		double c_FMA; // First moment of area wrt the axis moved from centroid by c_location: Qc + A * location
		double c_SMA; // Second moment of area (inertia) wrt the axis moved from centroid by c_location: Ic + A * location ** 2

	public:
		Segment();
		Segment(double theWidth, double theHeight, double theLocation);
		bool operator==(const Segment& rhs);
		bool operator!=(const Segment& rhs) { return !operator==(rhs); }

	public:
		Segment(const Segment&) = default;
		Segment& operator=(const Segment&) = default;
		Segment(Segment&&) = default;
		Segment& operator=(Segment&&) = default;

		~Segment();

	public:
		double getWidth() const { return c_width; }
		double getHeight() const { return c_height; }
		double getLocation() const { return c_location; }
		double getCentroid() const { return c_centroid; }
		double getArea() const { return c_Area; }
		double getFMA() const { return c_FMA; }
		double getSMA() const { return c_SMA; }
		void setWidth(double theWidth);
		void setHeight(double theHeight);
		void setLocation(double theLocation);

	private:
		void setProperties(double theWidth, double theHeight, double theLocation);
	};
}
#endif
