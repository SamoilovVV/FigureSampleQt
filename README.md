# FigureSampleQt
This solution is a simple Qt application sample to demonstrate following:
1. Basic OOP principles with geometry figures (
2. Templated object factory implementation (Factory method pattern)
3. Qt plugin system usage example (see TrianglePlugin project)

Application allow to place selected geometric figures on scene. 
Figure size is random number between 20 and 200 pixels.

*Circle* and *Square* are "built-in" figures, *Triangle* figure adds via Qt plug-in system.

Adding new built-in figure requires only h- and cpp- files (providing they are properly registred via RegisterShape class like existing figure classes).

Adding new plug-in is also possible via Qt plugin system (see TrianglePlugin project). Plugin dll should be located in "plugins" subdirectory of executable directory.

# Requirments
MSVC2017 + Qt Vs Tools extension

Qt 5 (tested on Qt 5.12.8) 
