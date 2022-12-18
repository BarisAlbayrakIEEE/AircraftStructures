#include "Load.h"

namespace AircraftStructures {
	PanelLoad::PanelLoad(double thePressure, std::vector<double>& theFlues)
	{
		if (theFlues.size() != PANEL_FLUX_COUNT) throw AircraftException();
		c_pressure = make_shared<double>(thePressure);
		c_fluxes = make_shared<std::vector<double>>(theFlues);
	}

	bool PanelLoad::operator==(const PanelLoad& rhs) {
		if (Load::operator!=(rhs)) return false;

		int nullCount{};
		if (c_pressure == nullptr) ++nullCount;
		if (rhs.c_pressure == nullptr) ++nullCount;
		if (nullCount == 1) return false;

		nullCount = 0;
		if (c_fluxes == nullptr) ++nullCount;
		if (rhs.c_fluxes == nullptr) ++nullCount;
		if (nullCount == 1) return false;

		if (rhs.c_pressure != nullptr) {
			if (*c_pressure.get() != *rhs.c_pressure.get()) return false;
		}

		if (rhs.c_fluxes != nullptr) {
			std::vector<double> fluxes1 = *c_fluxes.get();
			std::vector<double> fluxes2 = *rhs.c_fluxes.get();
			if (fluxes1.size() != fluxes2.size()) return false;
			for (int i = 0; i < fluxes1.size(); ++i) {
				if (fluxes1[i] != fluxes2[i]) return false;
			}
		}
		return true;
	}
}
