#include "Segment.h"

namespace AircraftStructures {
	Segment::Segment()
		:
		c_width { },
		c_height{ },
		c_location{ },
		c_centroid{ },
		c_Area{ },
		c_FMA{ },
		c_SMA{ } { }

	Segment::Segment(double theWidth, double theHeight, double theLocation)
	{
		if (AircraftMath::lessThanZero(theWidth)) throw AircraftException();
		if (AircraftMath::lessThanZero(theHeight)) throw AircraftException();

		c_width = theWidth;
		c_height = theHeight;
		c_location = theLocation;
		setProperties(theWidth, theHeight, theLocation);
	}

	Segment::~Segment() {
		c_width = 0.;
		c_height = 0.;
		c_location = 0.;
		c_centroid = 0.;
		c_Area = 0.;
		c_FMA = 0.;
		c_SMA = 0.;
	}

	bool Segment::operator==(const Segment& rhs) {
		if (c_width != rhs.c_width) return false;
		if (c_height != rhs.c_height) return false;
		return c_location == rhs.c_location;
	}

	void Segment::setWidth(double theWidth)
	{
		if (AircraftMath::lessThanZero(theWidth)) throw AircraftException();

		c_width = theWidth;
		setProperties(theWidth, c_height, c_location);
	}

	void Segment::setHeight(double theHeight)
	{
		if (AircraftMath::lessThanZero(theHeight)) throw AircraftException();

		c_height = theHeight;
		setProperties(c_width, theHeight, c_location);
	}

	void Segment::setLocation(double theLocation)
	{
		if (AircraftMath::lessThanZero(theLocation)) throw AircraftException();

		c_location = theLocation;
		setProperties(c_width, c_height, theLocation);
	}

	void Segment::setProperties(double theWidth, double theHeight, double theLocation) {
		c_centroid = theLocation + theHeight / 2.;
		c_Area = theWidth * theHeight;
		c_FMA = c_Area * c_centroid;
		c_SMA = c_Area * std::pow(c_centroid, 2.);
	}
}
