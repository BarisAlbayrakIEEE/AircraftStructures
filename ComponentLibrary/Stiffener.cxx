#include "Stiffener.h"

namespace AircraftStructures {
	Stiffener::Stiffener(
		shared_ptr<Material> theMaterial,
		shared_ptr<Section> theSection,
		shared_ptr<Load> theLoad,
		double theLength)
		:
		Component(theMaterial, theSection, theLoad, theLength),
		c_RFStrength{ 1. },
		c_RFCrippling{ 1. } { }

	Stiffener::~Stiffener() {
		c_RFStrength = 0.;
		c_RFCrippling = 0.;
	}

	bool Stiffener::operator==(const Stiffener& rhs)
	{
		if (!Component::operator==(rhs)) return false;
		if (c_RFStrength != rhs.c_RFStrength) return false;
		return c_RFCrippling == rhs.c_RFCrippling;
	}

	bool Stiffener::operator!=(const Stiffener& rhs)
	{
		return !operator==(rhs);
	}

	double Stiffener::getRFStrength() const { return c_RFStrength; }
	double Stiffener::getRFCrippling() const { return c_RFCrippling; }

	void Stiffener::calculateRFs() {
		c_RFStrength = calculateStrength();
		c_RFCrippling = calculateCrippling();
	}
}