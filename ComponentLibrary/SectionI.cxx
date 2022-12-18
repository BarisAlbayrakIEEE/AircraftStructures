#include "Section.h"

namespace AircraftStructures {
	SectionI::SectionI(
		double wl1,
		double tl1,
		double wl2,
		double tl2,
		double tweb,
		double hweb,
		double wf1,
		double tf1,
		double wf2,
		double tf2)
	{
		c_segments.push_back(std::make_shared<Segment>(wl1, tl1, tl1 / 2.));
		c_segments.push_back(std::make_shared<Segment>(wl2, tl2, tl2 / 2.));
		c_segments.push_back(std::make_shared<Segment>(tweb, hweb, hweb / 2.));
		c_segments.push_back(std::make_shared<Segment>(wf1, tf1, hweb - tf1 / 2.));
		c_segments.push_back(std::make_shared<Segment>(wf2, tf2, hweb - tf2 / 2.));
		setProperties(c_segments);
	}
}
