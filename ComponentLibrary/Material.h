/// <summary>
/// Material class.
/// 
/// CAUTION:
///     See AircraftStructuresSample repository for sample usage of the library.
/// 
/// INVARIANT:
///   All material properties (density, E, nu, Ftu, Fty, Fcu, Fcy, Fsu) must be positive real
///   Invariant are not implemented currently for simplicity
/// 
/// author: baris.albayrak.ieee@gmail.com
/// github: https://github.com/BarisAlbayrakIEEE?tab=repositories
/// </summary>

#pragma warning(disable : 4250) // disable diamond inheritance with dominance
#pragma warning(disable : 4290) // disable throw(SomeException)

#ifndef _Material_h
#define _Material_h

#include <array>

namespace AircraftStructures {
	class Material {
		friend class GSP;
		friend class Rib;
		friend class Spar;
		friend class Frame;
		friend class Component;
		friend class Panel;
		friend class Stiffener;
		friend class Section;
		friend class SectionBox;
		friend class SectionI;
		friend class SectionJ;
		friend class Segment;

	private:
		double c_density;
		double c_E;
		double c_Nu;
		double c_Ftu;
		double c_Fty;
		double c_Fcu;
		double c_Fcy;
		double c_Fsu;

	public:
		Material();
		Material(
			double theDensity,
			double theE,
			double theNu,
			double theFtu,
			double theFty,
			double theFcu,
			double theFcy,
			double theFsu);
		Material(std::array<double, 7> theProperties); // Order of above constructor
		Material(const Material&) = default;
		Material& operator=(const Material&) = default;
		Material(Material&&) = default;
		Material& operator=(Material&&) = default;
		bool operator==(const Material& rhs);
		bool operator!=(const Material& rhs);

		~Material();
		void Destroy();

	public:
		std::array<double,7> getProperties() const;
		double getDensity() const { return c_density; }
		double getE() const { return c_E; }
		double getNu() const { return c_Nu; }
		double getFtu() const { return c_Ftu; }
		double getFty() const { return c_Fty; }
		double getFcu() const { return c_Fcu; }
		double getFcy() const { return c_Fcy; }
		double getFsu() const { return c_Fsu; }
		void setDensity(double theDensity) { c_density = theDensity; }
		void setE(double theE) { c_E = theE; }
		void setNu(double theNu) { c_Nu = theNu; }
		void setFtu(double theFtu) { c_Ftu = theFtu; }
		void setFty(double theFty) { c_Fty = theFty; }
		void setFcu(double theFcu) { c_Fcu = theFcu; }
		void setFcy(double theFcy) { c_Fcy = theFcy; }
		void setFsu(double theFsu) { c_Fsu = theFsu; }
	};
}

#endif
