#pragma once
#include <QGraphicsItem>

#include "IShape.h"

#include "RegisterShape.h"

namespace {
	const QString squareName = "Square";
}

//************************************
// Square shape with sides parallel to X and Y axis
//************************************
class Square : public FigureCommon::IShape
{
public:
	Square() = default;
	virtual ~Square() = default;

	//IShape overrides
	virtual QString name() const override { return squareName; }

	//************************************
	// Method:    createFigure - create square  for QGraphicScene
	// Returns:   QGraphicsItem * - graphics item
	// Parameter: double size - square side size
	//************************************
	virtual QGraphicsItem *createFigure(double size) const override;

};

namespace {
	// register shape
	RegisterShape<Square> RegisterElementSquare(squareName);
}

