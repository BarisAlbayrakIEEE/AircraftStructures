#include "Section.h"

namespace AircraftStructures {
	SectionJ::SectionJ(
		double wl1,
		double tl1,
		double wl2,
		double tl2,
		double tweb,
		double hweb,
		double wf,
		double tf)
	{
		c_segments.push_back(std::make_shared<Segment>(wl1, tl1, tl1 / 2.));
		c_segments.push_back(std::make_shared<Segment>(wl2, tl2, tl2 / 2.));
		c_segments.push_back(std::make_shared<Segment>(tweb, hweb, hweb / 2.));
		c_segments.push_back(std::make_shared<Segment>(wf, tf, hweb - tf / 2.));
		setProperties(c_segments);
	}
}
