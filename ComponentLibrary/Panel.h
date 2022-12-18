/// <summary>
/// Panel is the structural component that is a plate surrounded by stiffeners.
/// 
/// CAUTION:
///     See AircraftStructuresSample repository for sample usage of the library.
/// 
/// INVARIANT:
///   All geometric properties (width, height and thickness) must be positive real
/// 
/// author: baris.albayrak.ieee@gmail.com
/// github: https://github.com/BarisAlbayrakIEEE?tab=repositories
/// </summary>

#pragma warning(disable : 4250) // disable diamond inheritance with dominance
#pragma warning(disable : 4290) // disable throw(SomeException)

#ifndef _Panel_h
#define _Panel_h

#include "Component.h"

namespace AircraftStructures {
	class Panel : public Component {
		friend class GSP;
		friend class Rib;
		friend class Spar;
		friend class Frame;
		friend class Component;
		friend class Stiffener;
		friend class Material;
		friend class Section;
		friend class SectionBox;
		friend class SectionI;
		friend class SectionJ;
		friend class Segment;

	private:
		double c_thickness;
		double c_width;
		double c_RFBuckling;
		double c_RFPostBuckling;
		double c_RFPressurePanel;

	public:
		Panel(
			shared_ptr<Material> theMaterial,
			shared_ptr<Section> theSectionParallelToX,
			shared_ptr<Load> theLoad,
			double theLengthParallelToY);
		Panel(const Panel&) = default;
		Panel& operator=(const Panel&) = default;
		Panel(Panel&&) = default;
		Panel& operator=(Panel&&) = default;
		bool operator==(const Panel& rhs);
		bool operator!=(const Panel& rhs);

		~Panel();

		double getThickness() { return c_thickness; }
		double getWidth() { return c_width; }
		double getRFBuckling() { return c_RFBuckling; }
		double getRFPostBuckling() { return c_RFPostBuckling; }
		double getRFPressurePanel() { return c_RFPressurePanel; }
		void setThickness(double theThickness);
		void setWidth(double theWidth);

		void calculateRFs() override;

	private:
		double calculateBuckling() const { return 1.; } // TODO
		double calculatePostBuckling() const { return 1.; } // TODO
		double calculatePressurePanel() const { return 1.; } // TODO
	};
}

#endif
