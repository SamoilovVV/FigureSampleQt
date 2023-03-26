#pragma once

#include <QGraphicsItem>


#include "IShape.h"

#include "RegisterShape.h"

namespace {
	const QString circleName = "Circle";
}

//************************************
// Circle shape
//************************************
class Circle : public FigureCommon::IShape
{
public:
	Circle() = default;
	virtual ~Circle() = default;

	//IShape overrides
	virtual QString name() const override { return circleName; }

	//************************************
	// Method:    createFigure - create circle for QGraphicScene
	// Returns:   QGraphicsItem * - graphics item
	// Parameter: double size - circle diameter
	//************************************
	virtual QGraphicsItem *createFigure(double size) const override;

};

namespace {
	// register shape
	RegisterShape<Circle> RegisterElementCircle(circleName);
}

