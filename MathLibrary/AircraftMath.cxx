#include "AircraftMath.h"

namespace AircraftStructures {
	extern const double TOLERANCE = 0.001;

	bool AircraftMath::equals(double theValue0, double theValue1)
	{
		if (std::fabs(theValue0 - theValue1) < TOLERANCE) return true;
		return false;
	}

	bool AircraftMath::lessThan(double theValue0, double theValue1)
	{
		if (theValue0 - theValue1 < TOLERANCE) return true;
		return false;
	}

	bool AircraftMath::greaterThan(double theValue0, double theValue1)
	{
		if (theValue0 - theValue1 > TOLERANCE) return true;
		return false;
	}

	bool AircraftMath::equalsZero(double theValue)
	{
		if (std::fabs(theValue) < TOLERANCE) return true;
		return false;
	}

	bool AircraftMath::lessThanZero(double theValue)
	{
		if (theValue < TOLERANCE) return true;
		return false;
	}

	bool AircraftMath::greaterThanZero(double theValue)
	{
		if (theValue > TOLERANCE) return true;
		return false;
	}
}
