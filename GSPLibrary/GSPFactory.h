#pragma warning(disable : 4250) // disable diamond inheritance with dominance
#pragma warning(disable : 4290) // disable throw(SomeException)

#ifndef _GSPFactory_h
#define _GSPFactory_h

#include "GSP.h"
#include "Rib.h"
#include "Spar.h"
#include "Frame.h"
#include "Panel.h"
#include "Stiffener.h"

/**
 * FactoryName: The name of the factory class to be created
 * GSPName: The name of the GSP class to be created (e.g. Panel or HorizontalStiffener)
 */
#define CREATE_GSP_FACTORY(FactoryName, GSPName) class FactoryName : public GSPFactory { \
    public: \
        GSP* FactoryMethod( \
            GRID(Panel)& thePanels, \
            GRID(HorizontalStiffener)& theHSs, \
            GRID(VerticalStiffener)& theVSs) const override \
        { \
            return new GSPName(thePanels, theHSs, theVSs); \
        } \
    };

namespace AircraftStructures {
    /**
     * The pure virtual base class for the factory method of GSP.
     */
    class GSPFactory {
    public:
        /**
         * The factory method
         * Keep this signature for the family of GSP factory methods
         */
        virtual GSP* FactoryMethod(
            GRID(Panel)& thePanels,
            GRID(HorizontalStiffener)& theHSs,
            GRID(VerticalStiffener)& theVSs) const = 0;
    };

    /**
     * Use the CREATE_GSP_FACTORY macro for each factory
     */
    CREATE_GSP_FACTORY(RibFactory, Rib)
    CREATE_GSP_FACTORY(SparFactory, Spar)
    CREATE_GSP_FACTORY(FrameFactory, Frame)
}

#endif
