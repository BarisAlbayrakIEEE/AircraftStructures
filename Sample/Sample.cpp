#include <iostream>
#include <Material.h>
#include <Section.h>
#include <Load.h>
#include <Panel.h>
#include <Stiffener.h>
#include <Rib.h>
#include <Spar.h>
#include <Frame.h>
#include <ComponentFactory.h>
#include <Builder.h>

using namespace AircraftStructures;

/// <summary>
/// Client code
/// </summary>
void Client()
{
    PanelFactory* panelFactory = new PanelFactory();

    std::vector<double> fluxes{ 1., 1., 1., 1., 1., 1. };
    shared_ptr<Material> panelMaterial = make_shared<Material>(1., 1., 1., 1., 1., 1., 1., 1.);
    shared_ptr<SectionBox> panelSection = make_shared<SectionBox>(1., 1.);
    shared_ptr<PanelLoad> panelLoad = make_shared<PanelLoad>(0.1, fluxes);
    Panel* panel = static_cast<Panel*>(
        panelFactory->FactoryMethod(
            panelMaterial,
            panelSection,
            panelLoad,
            100.));
    delete panel;
    delete panelFactory;

    RibBuilder* ribBuilder = new RibBuilder();

    std::vector<double> stiffenerLoads{ 1., 1., 1., 1., 1., 1. };
    shared_ptr<Material> HSMaterial = make_shared<Material>(1., 1., 1., 1., 1., 1., 1., 1.);
    shared_ptr<SectionI> HSSection = make_shared<SectionI>(1., 1., 1., 1., 1., 1., 1., 1., 1., 1.);
    shared_ptr<StiffenerLoad> HSLoad = make_shared<StiffenerLoad>(stiffenerLoads);
    shared_ptr<Material> VSMaterial = make_shared<Material>(1., 1., 1., 1., 1., 1., 1., 1.);
    shared_ptr<SectionJ> VSSection = make_shared<SectionJ>(1., 1., 1., 1., 1., 1., 1., 1.);
    shared_ptr<StiffenerLoad> VSLoad = make_shared<StiffenerLoad>(stiffenerLoads);
    ribBuilder->setGrid(3, 4);
    ribBuilder->BuildPanel(0, 0, panelMaterial, panelSection, panelLoad, 100.);
    ribBuilder->BuildHorizontalStiffener(0, 0, HSMaterial, HSSection, HSLoad, 100.);
    ribBuilder->BuildVerticalStiffener(0, 0, VSMaterial, VSSection, VSLoad, 100.);
    delete ribBuilder;
}

int main()
{
    Client();
}
