#include "Material.h"

namespace AircraftStructures {
	Material::Material()
		:
		c_density{ },
		c_E{ },
		c_Nu{ },
		c_Ftu{ },
		c_Fty{ },
		c_Fcu{ },
		c_Fcy{ },
		c_Fsu{ } {}

	Material::Material(
		double theDensity,
		double theE,
		double theNu,
		double theFtu,
		double theFty,
		double theFcu,
		double theFcy,
		double theFsu)
		:
		c_density{ theDensity },
		c_E{ theE },
		c_Nu{ theNu },
		c_Ftu{ theFtu },
		c_Fty{ theFty },
		c_Fcu{ theFcu },
		c_Fcy{ theFcy },
		c_Fsu{ theFsu } {}

	Material::Material(std::array<double, 7> theProperties)
		:
		c_density{ theProperties[0] },
		c_E{ theProperties[1] },
		c_Nu{ theProperties[2] },
		c_Ftu{ theProperties[3] },
		c_Fty{ theProperties[4] },
		c_Fcu{ theProperties[5] },
		c_Fcy{ theProperties[6] },
		c_Fsu{ theProperties[7] } {}

	void Material::Destroy() {
		c_density = 0.;
		c_E = 0.;
		c_Nu = 0.;
		c_Ftu = 0.;
		c_Fty = 0.;
		c_Fcu = 0.;
		c_Fcy = 0.;
		c_Fsu = 0.;
	}

	Material::~Material() {
		Destroy();
	}

	bool Material::operator==(const Material& rhs)
	{
		if (c_density != rhs.c_density) return false;
		if (c_E != rhs.c_E) return false;
		if (c_Nu != rhs.c_Nu) return false;
		if (c_Ftu != rhs.c_Ftu) return false;
		if (c_Fty != rhs.c_Fty) return false;
		if (c_Fcu != rhs.c_Fcu) return false;
		if (c_Fcy != rhs.c_Fcy) return false;
		return c_Fsu == rhs.c_Fsu;
	}

	bool Material::operator!=(const Material& rhs)
	{
		return !operator==(rhs);
	}

	std::array<double, 7> Material::getProperties() const
	{
		std::array<double, 7> properties;
		properties[0] = c_density;
		properties[1] = c_E;
		properties[2] = c_Nu;
		properties[3] = c_Ftu;
		properties[4] = c_Fty;
		properties[5] = c_Fcu;
		properties[6] = c_Fcy;
		properties[7] = c_Fsu;
		return properties;
	}
}