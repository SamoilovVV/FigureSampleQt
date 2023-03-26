#pragma once

#include "ObjectFactory.h"
#include "IShape.h"

//************************************
// Concrete factory for FigureSampleQt project
//************************************
 class ShapeFactory : public StaticObjectFactory<ShapeFactory, FigureCommon::IShape, QString> { };