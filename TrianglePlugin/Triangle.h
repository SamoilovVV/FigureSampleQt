#pragma once

#include "triangleplugin_global.h"

#include <QObject>
#include <QtPlugin>

#include "../FigureSampleQt/IShape.h"

//************************************
// Equilateral triangle shape 
//************************************
class TRIANGLEPLUGIN_EXPORT Triangle : public QObject, public FigureCommon::IShape
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID IShape_iid )
	Q_INTERFACES(FigureCommon::IShape)
public:
    Triangle() = default;
	virtual ~Triangle() = default;

	virtual QString name() const override { return "Triangle"; }

	//************************************
	// Method:    createFigure - create triangle  for QGraphicScene
	// Returns:   QGraphicsItem * - graphics item
	// Parameter: double size - diameter of circumscribed circle of triangle
	//************************************
	virtual QGraphicsItem *createFigure(double size) const override;

private:

	//************************************
	// Method:    boundingRect - returns bounding rect of item for correct placement
	// Returns:   QRectF - shape's bounding rect
	// Parameter: double Radius - radius of circumscribed circle of triangle
	//************************************
	QRectF boundingRect(double Radius) const;
};

