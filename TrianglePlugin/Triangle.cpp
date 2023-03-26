#include "Triangle.h"

#include <QPainterPath>

QGraphicsItem * Triangle::createFigure(double size) const
{
	QRectF br = boundingRect(0.5*size);
	QPainterPath path;
	QPointF ptStart(br.x() + br.width()*0.5, br.y());
	path.moveTo(ptStart);
	path.lineTo(br.bottomRight());
	path.lineTo(br.bottomLeft());
	path.lineTo(ptStart);

	return new QGraphicsPathItem(path);
}

QRectF Triangle::boundingRect(double Radius) const
{
	double h = 1.5 *Radius;// height

	double a = 2 * h / sqrt(3.0);// side

	double x = -0.5*a;// x offset from center
	double y = -Radius;// y offset from center

	return QRectF(x, y, a, h);
}
