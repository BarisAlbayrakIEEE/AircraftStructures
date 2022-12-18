#include "Builder.h"

namespace AircraftStructures {
    /// <summary>
    /// Panel builder
    /// </summary>
    void SparBuilder::BuildPanel(
        const int iRow, // [0, row count)
        const int iClm, // [0, clm count)
        shared_ptr<Material> theMaterial,
        shared_ptr<Section> theSection,
        shared_ptr<Load> theLoad,
        double theLength) const
    {
        GRID(Panel) panels = c_Spar->getPanels();
        if (panels.size() == 0) {
            LINEAR(Panel) row;
            for (int i = 0; i < c_Spar->getRowCount(); ++i) panels.push_back(row);
        }
        shared_ptr<Panel> panel = make_shared<Panel>(theMaterial, theSection, theLoad, theLength);
        while (panels[iRow].size() < iClm) {
            panels[iRow].push_back(nullptr);
        }
        if (panels[iRow].size() == iClm) {
            panels[iRow].push_back(panel);
        }
        else {
            panels[iRow][iClm] = panel;
        }
        c_Spar->setPanels(panels);
    }

    /// <summary>
    /// HorizontalStiffener builder
    /// </summary>
    void SparBuilder::BuildHorizontalStiffener(
        const int iRow, // [0, row count]
        const int iClm, // [0, clm count)
        shared_ptr<Material> theMaterial,
        shared_ptr<Section> theSection,
        shared_ptr<Load> theLoad,
        double theLength) const
    {
        GRID(HorizontalStiffener) HSs = c_Spar->getHorizontalStiffeners();
        if (HSs.size() == 0) {
            LINEAR(HorizontalStiffener) row;
            for (int i = 0; i < c_Spar->getRowCount(); ++i) HSs.push_back(row);
        }
        shared_ptr<HorizontalStiffener> HS = make_shared<HorizontalStiffener>(theMaterial, theSection, theLoad, theLength);
        while (HSs[iRow].size() < iClm) {
            HSs[iRow].push_back(nullptr);
        }
        if (HSs[iRow].size() == iClm) {
            HSs[iRow].push_back(HS);
        }
        else {
            HSs[iRow][iClm] = HS;
        }
        c_Spar->setHorizontalStiffeners(HSs);
    }

    /// <summary>
    /// VerticalStiffener builder
    /// </summary>
    void SparBuilder::BuildVerticalStiffener(
        const int iRow, // [0, row count)
        const int iClm, // [0, clm count]
        shared_ptr<Material> theMaterial,
        shared_ptr<Section> theSection,
        shared_ptr<Load> theLoad,
        double theLength) const
    {
        GRID(VerticalStiffener) VSs = c_Spar->getVerticalStiffeners();
        if (VSs.size() == 0) {
            LINEAR(VerticalStiffener) row;
            for (int i = 0; i < c_Spar->getRowCount(); ++i) VSs.push_back(row);
        }
        shared_ptr<VerticalStiffener> VS = make_shared<VerticalStiffener>(theMaterial, theSection, theLoad, theLength);
        while (VSs[iRow].size() < iClm) {
            VSs[iRow].push_back(nullptr);
        }
        if (VSs[iRow].size() == iClm) {
            VSs[iRow].push_back(VS);
        }
        else {
            VSs[iRow][iClm] = VS;
        }
        c_Spar->setVerticalStiffeners(VSs);
    }

    /// <summary>
    /// Returns the current Frame and creates a new one to be ready for production.
    /// Throws an exception if the current Frame is not constructed yet.
    /// A panel or a HS or a VS can be null meaning that no component exists at that location in reality.
    /// </summary>
    shared_ptr<Spar> SparBuilder::GetSpar() {
        GRID(Panel) panels = c_Spar->getPanels();
        GRID(HorizontalStiffener) HSs = c_Spar->getHorizontalStiffeners();
        GRID(VerticalStiffener) VSs = c_Spar->getVerticalStiffeners();
        if (panels.size() < c_Spar->getRowCount()) throw AircraftException();
        if (HSs.size() < c_Spar->getRowCount() + 1) throw AircraftException();
        if (VSs.size() < c_Spar->getRowCount()) throw AircraftException();
        for (int iRow = 0; iRow < c_Spar->getRowCount(); ++iRow) {
            if (panels[iRow].size() < c_Spar->getClmCount()) throw AircraftException();
            if (HSs[iRow].size() < c_Spar->getClmCount()) throw AircraftException();
            if (VSs[iRow].size() < c_Spar->getClmCount() + 1) throw AircraftException();
        }
        if (HSs[c_Spar->getRowCount()].size() < c_Spar->getClmCount()) throw AircraftException();

        shared_ptr<Spar> result = c_Spar;
        Reset();
        return result;
    }
}
