/// <summary>
/// Implementation base class for loading
/// Not an abstract class.
/// 
/// CAUTION:
///     See AircraftStructuresSample repository for sample usage of the library.
/// 
/// INVARIANT:
///   No invariant
/// 
/// The copy/move ctors and operators of Loaad class are private to prevent slicing.
/// 
/// There exist two subclasses of Load: PanelLoad and StiffenerLoad
/// 
/// author: baris.albayrak.ieee@gmail.com
/// github: https://github.com/BarisAlbayrakIEEE?tab=repositories
/// </summary>

#pragma warning(disable : 4250) // disable diamond inheritance with dominance
#pragma warning(disable : 4290) // disable throw(SomeException)

#ifndef _Load_h
#define _Load_h

#include <vector>
#include <memory>
#include <AircraftException.h>
#include <AircraftMath.h>

namespace AircraftStructures {
	class Load {
		friend class Rib;
		friend class Spar;
		friend class Frame;
		friend class Component;
		friend class Panel;
		friend class Stiffener;
		friend class Material;
		friend class Section;
		friend class SectionBox;
		friend class SectionI;
		friend class SectionJ;
		friend class Segment;

	public:
		Load() {}
		virtual ~Load() {}

	private:
		Load(const Load& rhs) = default;
		Load& operator=(const Load& rhs) = default;
		Load(Load&& rhs) = default;
		Load& operator=(Load&& rhs) = default;

	public:
		bool operator==(const Load& rhs) { return true; }
		bool operator!=(const Load& rhs) { return !operator==(rhs); }
	};




	class PanelLoad : public Load {
		friend class GSP;
		friend class Rib;
		friend class Spar;
		friend class Frame;
		friend class Component;
		friend class Panel;
		friend class Stiffener;
		friend class Material;
		friend class Section;
		friend class SectionI;
		friend class SectionJ;
		friend class Segment;

	private:
		static const int PANEL_FLUX_COUNT = 6;
		shared_ptr<double> c_pressure;
		shared_ptr<std::vector<double>> c_fluxes;

	public:
		PanelLoad(double thePressure, std::vector<double>& theFluxes);
		PanelLoad(const PanelLoad&) = default;
		PanelLoad& operator=(const PanelLoad&) = default;
		PanelLoad(PanelLoad&&) = default;
		PanelLoad& operator=(PanelLoad&&) = default;
		bool operator==(const PanelLoad& rhs);
		bool operator!=(const PanelLoad& rhs) { return !operator==(rhs); }

		~PanelLoad() = default;

	public:
		double getPressure() const { return *c_pressure.get(); }
		std::vector<double>& getFluxes() const { return *c_fluxes.get(); }
		void setPressure(double thePressure) { c_pressure = make_shared<double>(thePressure); }
		void setPressure(std::vector<double>& theFluxes) { c_fluxes = make_shared<std::vector<double>>(theFluxes); }
	};




	class StiffenerLoad : public Load {
		friend class GSP;
		friend class Rib;
		friend class Spar;
		friend class Frame;
		friend class Component;
		friend class Panel;
		friend class Stiffener;
		friend class Material;
		friend class Section;
		friend class SectionI;
		friend class SectionJ;
		friend class Segment;

	private:
		static const int STIFF_SECTION_LOAD_COUNT = 6;
		shared_ptr<std::vector<double>> c_sectionLoads;

	public:
		StiffenerLoad(std::vector<double>& theSectionLoads);
		StiffenerLoad(const StiffenerLoad&) = default;
		StiffenerLoad& operator=(const StiffenerLoad&) = default;
		StiffenerLoad(StiffenerLoad&&) = default;
		StiffenerLoad& operator=(StiffenerLoad&&) = default;
		bool operator==(const StiffenerLoad& rhs);
		bool operator!=(const StiffenerLoad& rhs) { return !operator==(rhs); }

		~StiffenerLoad() = default;

	public:
		std::vector<double>& getSectionLoads() const { return *c_sectionLoads.get(); }
		void setSectionLoads(std::vector<double>& theSectionLoads) {
			c_sectionLoads = make_shared<std::vector<double>>(theSectionLoads);
		}
	};
}

#endif
