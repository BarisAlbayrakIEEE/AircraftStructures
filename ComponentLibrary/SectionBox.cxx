#include "Section.h"

namespace AircraftStructures {
	SectionBox::SectionBox(double theWidth, double theHeight) {
		c_segments.push_back(std::make_shared<Segment>(theWidth, theHeight, theHeight / 2.));
		setProperties(c_segments);
	}
}
