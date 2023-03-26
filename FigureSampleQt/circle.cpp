#include <QPainter>
#include "circle.h"


QGraphicsItem * Circle::createFigure(double size) const
{
	return new QGraphicsEllipseItem(-0.5*size, -0.5*size, size, size);
}
