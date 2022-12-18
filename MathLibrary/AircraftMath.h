/// <summary>
/// Contains simple math functions
/// 
/// author: baris.albayrak.ieee@gmail.com
/// github: https://github.com/BarisAlbayrakIEEE?tab=repositories
/// </summary>

#pragma warning(disable : 4250) // disable diamond inheritance with dominance
#pragma warning(disable : 4290) // disable throw(SomeException)

#ifndef _AircraftMath_h
#define _AircraftMath_h

#include <iostream>

namespace AircraftStructures {
	class AircraftMath {
	public:
		static bool equals(double theValue0, double theValue1);
		static bool lessThan(double theValue0, double theValue1);
		static bool greaterThan(double theValue0, double theValue1);
		static bool equalsZero(double theValue);
		static bool lessThanZero(double theValue);
		static bool greaterThanZero(double theValue);
	};
	extern const double TOLERANCE;
}

#endif
