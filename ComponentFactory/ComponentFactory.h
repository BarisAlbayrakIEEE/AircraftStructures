/// <summary>
/// A simple factory method implementation for Component library in https://github.com/BarisAlbayrakIEEE/ComponentLibrary
/// The aim is to decouple constructors from the class implementation for a higher level of encapsulation.
/// 
/// CAUTION:
///     See AircraftStructuresSample repository for sample usage of the library.
/// 
/// An abstract base class (ComponentFactory) defines the interface.
/// PanelFactory, HorizontalStiffenerFactory and VerticalStiffenerFactory define concrete factories respectively.
/// 
/// author: baris.albayrak.ieee@gmail.com
/// github: https://github.com/BarisAlbayrakIEEE?tab=repositories
/// </summary>

#pragma warning(disable : 4250) // disable diamond inheritance with dominance
#pragma warning(disable : 4290) // disable throw(SomeException)

#ifndef _ComponentFactory_h
#define _ComponentFactory_h

#include <memory>
#include <Component.h>
#include <Material.h>
#include <Section.h>
#include <Panel.h>
#include <Stiffener.h>

using namespace std;

/**
 * FactoryName: The name of the factory class to be created
 * ComponentName: The name of the Component class to be created (e.g. Panel or HorizontalStiffener)
 */
#define CREATE_COMPONENT_FACTORY(FactoryName, ComponentName) class FactoryName : public ComponentFactory { \
    public: \
        Component* FactoryMethod( \
            shared_ptr<Material> theMaterial, \
            shared_ptr<Section> theSection, \
            shared_ptr<Load> theLoad, \
            double theLength) const override \
        { \
            return new ComponentName(theMaterial, theSection, theLoad, theLength); \
        } \
    };

namespace AircraftStructures {
    /**
     * The pure virtual base class for the factory method of Component.
     */
    class ComponentFactory {
    public:
        /**
         * The factory method
         * Keep this signature for the family of Component factory methods
         */
        virtual Component* FactoryMethod(
            shared_ptr<Material> theMaterial,
            shared_ptr<Section> theSection,
            shared_ptr<Load> theLoad,
            double theLength) const = 0;
    };

    /**
     * Use the CREATE_COMPONENT_FACTORY macro for each factory
     */
    CREATE_COMPONENT_FACTORY(PanelFactory, Panel)
    CREATE_COMPONENT_FACTORY(HorizontalStiffenerFactory, HorizontalStiffener)
    CREATE_COMPONENT_FACTORY(VerticalStiffenerFactory, VerticalStiffener)
}

#endif
