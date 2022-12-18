/// <summary>
/// A simple builder pattern implementation for GSP library in https://github.com/BarisAlbayrakIEEE/GSPLibrary
/// The implementation relies on the delegation.
/// The product is stored in the dynamic memory with a smart pointer.
/// 
/// CAUTION:
///     See AircraftStructuresSample repository for sample usage of the library.
/// 
/// An abstract base class (AbstractGSPBuilder) defines the interface.
/// RibBuilder, SparBuilder and FrameBuilder define concrete builders respectively.
/// 
/// author: baris.albayrak.ieee@gmail.com
/// github: https://github.com/BarisAlbayrakIEEE?tab=repositories
/// </summary>

#pragma warning(disable : 4250) // disable diamond inheritance with dominance
#pragma warning(disable : 4290) // disable throw(SomeException)

#ifndef _Builder_h
#define _Builder_h

#include <GSP.h>
#include <Rib.h>
#include <Spar.h>
#include <Frame.h>

namespace AircraftStructures {
     /// <summary>
     /// The pure virtual base class for all builders (Rib, Spar and Frame)
     /// </summary>
    class AbstractGSPBuilder {
    public:
        ~AbstractGSPBuilder() {}
        virtual void setGrid(const int theRowCount, const int theClmCount) = 0;
        virtual void BuildPanel(
            const int iRow, // [0, row count)
            const int iClm, // [0, clm count)
            shared_ptr<Material> theMaterial,
            shared_ptr<Section> theSection,
            shared_ptr<Load> theLoad,
            double theLength) const = 0;
        virtual void BuildHorizontalStiffener(
            const int iRow, // [0, row count]
            const int iClm, // [0, clm count)
            shared_ptr<Material> theMaterial,
            shared_ptr<Section> theSection,
            shared_ptr<Load> theLoad,
            double theLength) const = 0;
        virtual void BuildVerticalStiffener(
            const int iRow, // [0, row count)
            const int iClm, // [0, clm count]
            shared_ptr<Material> theMaterial,
            shared_ptr<Section> theSection,
            shared_ptr<Load> theLoad,
            double theLength) const = 0;
    };

    /// <summary>
    /// Rib builder
    /// </summary>
    class RibBuilder : public AbstractGSPBuilder {
    private:
        shared_ptr<Rib> c_Rib;

    public:
        RibBuilder() { Reset(); }
        ~RibBuilder() { c_Rib = nullptr; }
        void Reset() { c_Rib = make_shared<Rib>(); }
        shared_ptr<Rib> GetRib();

        virtual void setGrid(const int theRowCount, const int theClmCount) { c_Rib->setGrid(theRowCount, theClmCount); }

        void BuildPanel(
            const int iRow, // [0, row count)
            const int iClm, // [0, clm count)
            shared_ptr<Material> theMaterial,
            shared_ptr<Section> theSection,
            shared_ptr<Load> theLoad,
            double theLength) const override;
        void BuildHorizontalStiffener(
            const int iRow, // [0, row count]
            const int iClm, // [0, clm count)
            shared_ptr<Material> theMaterial,
            shared_ptr<Section> theSection,
            shared_ptr<Load> theLoad,
            double theLength) const override;
        void BuildVerticalStiffener(
            const int iRow, // [0, row count)
            const int iClm, // [0, clm count]
            shared_ptr<Material> theMaterial,
            shared_ptr<Section> theSection,
            shared_ptr<Load> theLoad,
            double theLength) const override;
    };

    /// <summary>
    /// Spar builder
    /// </summary>
    class SparBuilder : public AbstractGSPBuilder {
    private:
        shared_ptr<Spar> c_Spar;

    public:
        SparBuilder() { Reset(); }
        ~SparBuilder() { c_Spar = nullptr; }
        void Reset() { c_Spar = make_shared<Spar>(); }
        shared_ptr<Spar> GetSpar();

        virtual void setGrid(const int theRowCount, const int theClmCount) { c_Spar->setGrid(theRowCount, theClmCount); }

        void BuildPanel(
            const int iRow, // [0, row count)
            const int iClm, // [0, clm count)
            shared_ptr<Material> theMaterial,
            shared_ptr<Section> theSection,
            shared_ptr<Load> theLoad,
            double theLength) const override;
        void BuildHorizontalStiffener(
            const int iRow, // [0, row count]
            const int iClm, // [0, clm count)
            shared_ptr<Material> theMaterial,
            shared_ptr<Section> theSection,
            shared_ptr<Load> theLoad,
            double theLength) const override;
        void BuildVerticalStiffener(
            const int iRow, // [0, row count)
            const int iClm, // [0, clm count]
            shared_ptr<Material> theMaterial,
            shared_ptr<Section> theSection,
            shared_ptr<Load> theLoad,
            double theLength) const override;
    };

    /// <summary>
    /// Frame builder
    /// </summary>
    class FrameBuilder : public AbstractGSPBuilder {
    private:
        shared_ptr<Frame> c_Frame;

    public:
        FrameBuilder() { Reset(); }
        ~FrameBuilder() { c_Frame = nullptr; }
        void Reset() { c_Frame = make_shared<Frame>(); }
        shared_ptr<Frame> GetFrame();

        virtual void setGrid(const int theRowCount, const int theClmCount) { c_Frame->setGrid(theRowCount, theClmCount); }

        void BuildPanel(
            const int iRow, // [0, row count)
            const int iClm, // [0, clm count)
            shared_ptr<Material> theMaterial,
            shared_ptr<Section> theSection,
            shared_ptr<Load> theLoad,
            double theLength) const override;
        void BuildHorizontalStiffener(
            const int iRow, // [0, row count]
            const int iClm, // [0, clm count)
            shared_ptr<Material> theMaterial,
            shared_ptr<Section> theSection,
            shared_ptr<Load> theLoad,
            double theLength) const override;
        void BuildVerticalStiffener(
            const int iRow, // [0, row count)
            const int iClm, // [0, clm count]
            shared_ptr<Material> theMaterial,
            shared_ptr<Section> theSection,
            shared_ptr<Load> theLoad,
            double theLength) const override;
    };
}

#endif
