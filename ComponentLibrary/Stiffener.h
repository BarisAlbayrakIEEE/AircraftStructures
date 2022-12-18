/// <summary>
/// Stiffener is the structural component that is a plate surrounded by stiffeners.
/// 
/// CAUTION:
///     See AircraftStructuresSample repository for sample usage of the library.
/// 
/// INVARIANT:
///   No invariant
/// 
/// The copy/move ctors and operators of Stiffener class are private to prevent slicing.
/// There exist two subclasses of Stiffener: HorizontalStiffener and VerticalStiffener.
/// These form a Grid Stiffened Panel (GSP) together with Panel instances
/// 
/// author: baris.albayrak.ieee@gmail.com
/// github: https://github.com/BarisAlbayrakIEEE?tab=repositories
/// </summary>

#pragma warning(disable : 4250) // disable diamond inheritance with dominance
#pragma warning(disable : 4290) // disable throw(SomeException)

#ifndef _Stiffener_h
#define _Stiffener_h

#include "Component.h"

namespace AircraftStructures {
	class Stiffener : public Component {
		friend class GSP;
		friend class Rib;
		friend class Spar;
		friend class Frame;
		friend class Component;
		friend class Panel;
		friend class Material;
		friend class Section;
		friend class SectionBox;
		friend class SectionI;
		friend class SectionJ;
		friend class Segment;

	protected:
		double c_RFStrength;
		double c_RFCrippling;

	public:
		Stiffener(
			shared_ptr<Material> theMaterial,
			shared_ptr<Section> theSection,
			shared_ptr<Load> theLoad,
			double theLength);
		Stiffener(const Stiffener&) = default;
		Stiffener& operator=(const Stiffener&) = default;
		Stiffener(Stiffener&&) = default;
		Stiffener& operator=(Stiffener&&) = default;
		bool operator==(const Stiffener& rhs);
		bool operator!=(const Stiffener& rhs);

		~Stiffener();

		double getRFStrength() const;
		double getRFCrippling() const;
		void calculateRFs() override;

	private:
		double calculateStrength() const { return 1.; } // TODO
		double calculateCrippling() const { return 1.; } // TODO
	};



	class HorizontalStiffener : public Stiffener {
	public:
		HorizontalStiffener(
			shared_ptr<Material> theMaterial,
			shared_ptr<Section> theSection,
			shared_ptr<Load> theLoad,
			double theLength)
			: Stiffener(theMaterial, theSection, theLoad, theLength) {}
		HorizontalStiffener(const HorizontalStiffener&) = default;
		HorizontalStiffener& operator=(const HorizontalStiffener&) = default;
		HorizontalStiffener(HorizontalStiffener&&) = default;
		HorizontalStiffener& operator=(HorizontalStiffener&&) = default;
		bool operator==(const HorizontalStiffener& rhs) { return Stiffener::operator==(rhs); }

		~HorizontalStiffener() {};
	};



	class VerticalStiffener : public Stiffener {
	public:
		VerticalStiffener() = default;
		VerticalStiffener(
			shared_ptr<Material> theMaterial,
			shared_ptr<Section> theSection,
			shared_ptr<Load> theLoad,
			double theLength)
			: Stiffener(theMaterial, theSection, theLoad, theLength) {}
		VerticalStiffener(const VerticalStiffener&) = default;
		VerticalStiffener& operator=(const VerticalStiffener&) = default;
		VerticalStiffener(VerticalStiffener&&) = default;
		VerticalStiffener& operator=(VerticalStiffener&&) = default;
		bool operator==(const VerticalStiffener& rhs) { return Stiffener::operator==(rhs); }

		~VerticalStiffener() {};
	};
}

#endif
