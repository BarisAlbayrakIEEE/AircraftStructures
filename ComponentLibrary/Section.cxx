#include "Section.h"

namespace AircraftStructures {
	Section::Section()
		:
		c_centroid{ },
		c_Area{ },
		c_FMA{ },
		c_SMA{ } {}

	Section::Section(std::vector<std::shared_ptr<Segment>>& theSegments)
	{
		if (theSegments.size() == 0) throw AircraftException();

		c_segments = theSegments;
		setProperties(theSegments);
	}

	Section::~Section() {
		c_segments.clear();
		c_centroid = 0.;
		c_Area = 0.;
		c_FMA = 0.;
		c_SMA = 0.;
	}

	bool Section::operator==(const Section& rhs) {
		if (c_segments.size() != rhs.c_segments.size()) return false;
		for (int i = 0; i < c_segments.size(); ++i) {
			if (c_segments[i] != rhs.c_segments[i]) return false;
		}
		return true;
	}

	bool Section::operator!=(const Section& rhs)
	{
		return !operator==(rhs);
	}

	void Section::setSegments(std::vector<shared_ptr<Segment>>& theSegments)
	{
		if (theSegments.size() == 0) throw AircraftException();

		c_segments = theSegments;
		setProperties(theSegments);
	}

	void Section::setProperties(std::vector<shared_ptr<Segment>>& theSegments)
	{
		c_Area = 0.;
		double FMA{};
		double SMA{};
		for (auto segment : theSegments) {
			c_Area += segment->getArea();
			FMA += segment->getFMA();
			SMA += segment->getSMA();
		}
		c_centroid = FMA / c_Area;
		c_SMA = SMA - c_Area * std::pow(c_centroid, 2.);
		c_FMA = 0.;
		for (auto segment : theSegments) {
			c_FMA += segment->getArea() * (segment->getCentroid() - c_centroid);
		}
	}
}
