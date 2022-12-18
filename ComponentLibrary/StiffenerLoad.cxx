#include "Load.h"

namespace AircraftStructures {
	StiffenerLoad::StiffenerLoad(std::vector<double>& theSectionLoads)
	{
		if (theSectionLoads.size() != STIFF_SECTION_LOAD_COUNT) throw AircraftException();
		c_sectionLoads = make_shared<std::vector<double>>(theSectionLoads);
	}

	bool StiffenerLoad::operator==(const StiffenerLoad& rhs) {
		if (Load::operator!=(rhs)) return false;

		int nullCount{};
		if (c_sectionLoads == nullptr) ++nullCount;
		if (rhs.c_sectionLoads == nullptr) ++nullCount;
		if (nullCount == 1) return false;

		if (rhs.c_sectionLoads != nullptr) {
			std::vector<double> fluxes1 = *c_sectionLoads.get();
			std::vector<double> fluxes2 = *rhs.c_sectionLoads.get();
			if (fluxes1.size() != fluxes2.size()) return false;
			for (int i = 0; i < fluxes1.size(); ++i) {
				if (fluxes1[i] != fluxes2[i]) return false;
			}
		}
		return true;
	}
}
