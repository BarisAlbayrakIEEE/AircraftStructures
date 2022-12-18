# AircraftStructures
The class definitions and creational patterns for aircraft structures like panel, stiffener, rib, spar etc.

Libraries included:
1. ComponentLibrary:
- Defines the components used in an aircraft: Panel, HorizontalStiffener and VerticalStiffener
- Defines the classes for the fundamental paraameters: Material, Section etc.

2. GSPLibrary:
- Defines the Grid Stiffened Panel (GSP) family classes: Rib, Spar and Frame

3. ComponentFactory:
- Defines a Simple implementaton for factory method for ComponentLibrary

4. GSPBuilder:
- Defines a simple builder pattern for GSPLibrary that relies on delegation.

5. MathLibrary:
- Defines simple math functions: equal, greaterThan, etc.

6. ExceptionLibrary:
- Defines the exception classes for the repository

7. Sample:
- A sample usage of the libraries in the repository.
