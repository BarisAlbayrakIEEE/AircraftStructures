/// <summary>
/// The abstract base class for all structural elements (panel and stiffener currently).
/// 
/// CAUTION:
///     See AircraftStructuresSample repository for sample usage of the library.
/// 
/// INVARIANT:
///   Length must be positive real
/// 
/// The copy/move ctors and operators are private to prevent slicing.
/// 
/// There exist two subclasses of Component: Panel and Stiffener
/// 
/// author: baris.albayrak.ieee@gmail.com
/// github: https://github.com/BarisAlbayrakIEEE?tab=repositories
/// </summary>

#pragma warning(disable : 4250) // disable diamond inheritance with dominance
#pragma warning(disable : 4290) // disable throw(SomeException)

#ifndef _Component_h
#define _Component_h

#include <memory>
#include <AircraftException.h>
#include <AircraftMath.h>
#include "Material.h"
#include "Section.h"
#include "Load.h"

namespace AircraftStructures {
	class Component {
		friend class GSP;
		friend class Rib;
		friend class Spar;
		friend class Frame;
		friend class Panel;
		friend class Stiffener;
		friend class Material;
		friend class Section;
		friend class SectionBox;
		friend class SectionI;
		friend class SectionJ;
		friend class Segment;

	protected:
		shared_ptr<Material> c_material;
		shared_ptr<Section> c_section;
		shared_ptr<Load> c_load;
		double c_length;

	public:
		Component(
			shared_ptr<Material> theMaterial,
			shared_ptr<Section> theSection,
			shared_ptr<Load> theLoad,
			double theLength);
		virtual ~Component();
		bool operator==(const Component& rhs);
		bool operator!=(const Component& rhs) { return !operator==(rhs); }

	private:
		Component(const Component& rhs) = default;
		Component& operator=(const Component& rhs) = default;
		Component(Component&& rhs) = default;
		Component& operator=(Component&& rhs) = default;

	public:
		shared_ptr<Material> getMaterial() const { return c_material; }
		shared_ptr<Section> getSection() const { return c_section; }
		shared_ptr<Load> getLoad() const { return c_load; }
		double getLength() const { return c_length; }
		double getWeight() const {
			return c_material->getDensity() * c_section->getArea() * c_length;
		}
		void setMaterial(shared_ptr<Material> theMaterial) { c_material = theMaterial; }
		void setSection(shared_ptr<Section> theSection) { c_section = theSection; }
		void setLoad(shared_ptr<Load> theLoad) { c_load = theLoad; }
		void setLength(double theLength) { c_length = theLength; }

	public:
		virtual void calculateRFs() = 0;
	};
}

#endif
