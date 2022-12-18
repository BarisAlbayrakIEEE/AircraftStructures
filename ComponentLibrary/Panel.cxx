#include "Panel.h"

namespace AircraftStructures {
	Panel::Panel(
		shared_ptr<Material> theMaterial,
		shared_ptr<Section> theSectionParallelToX,
		shared_ptr<Load> theLoad,
		double theLengthParallelToY)
		: Component(theMaterial, theSectionParallelToX, theLoad, theLengthParallelToY),
		c_thickness{ c_section->getSegments()[0]->getHeight() },
		c_width{ c_section->getSegments()[0]->getWidth() },
		c_RFBuckling{ 1. },
		c_RFPostBuckling{ 1. },
		c_RFPressurePanel{ 1. } { }

	Panel::~Panel() {
		c_RFBuckling = 0.;
		c_RFPostBuckling = 0.;
		c_RFPressurePanel = 0.;
	}

	bool Panel::operator==(const Panel& rhs)
	{
		if (!Component::operator==(rhs)) return false;
		if (c_RFBuckling != rhs.c_RFBuckling) return false;
		if (c_RFPostBuckling != rhs.c_RFPostBuckling) return false;
		return c_RFPressurePanel == rhs.c_RFPressurePanel;
	}

	bool Panel::operator!=(const Panel& rhs)
	{
		return !operator==(rhs);
	}

	void Panel::setThickness(double theThickness) {
		c_thickness = theThickness;
		c_section->getSegments()[0]->setHeight(theThickness);
	}

	void Panel::setWidth(double theWidth) {
		c_width = theWidth;
		c_section->getSegments()[1]->setWidth(theWidth);
	}

	void Panel::calculateRFs() {
		c_RFBuckling = calculateBuckling();
		c_RFPostBuckling = calculatePostBuckling();
		c_RFPressurePanel = calculatePressurePanel();
	}

}