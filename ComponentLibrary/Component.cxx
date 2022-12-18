#include <algorithm>
#include "Component.h"
using namespace std;

namespace AircraftStructures {
	Component::Component(
		shared_ptr<Material> theMaterial,
		shared_ptr<Section> theSection,
		shared_ptr<Load> theLoad,
		double theLength)
	{
		if (theMaterial == nullptr) throw AircraftException();
		if (theSection == nullptr) throw AircraftException();
		if (theLoad == nullptr) throw AircraftException();
		if (AircraftMath::lessThanZero(theLength)) throw AircraftException();

		c_material = theMaterial;
		c_section = theSection;
		c_load = theLoad;
		c_length = theLength;
	}

	Component::~Component() {
		c_material = nullptr;
		c_section = nullptr;
		c_load = nullptr;
		c_length = 0.;
	}

	bool Component::operator==(const Component& rhs)
	{
		if (c_material != rhs.c_material) return false;
		if (c_section != rhs.c_section) return false;
		if (c_load != rhs.c_load) return false;
		return c_length == rhs.c_length;
	}
}
