#include <QPainter>

#include "Square.h"

QGraphicsItem * Square::createFigure(double size) const
{
	return new QGraphicsRectItem(-0.5*size, -0.5*size, size, size);
}
