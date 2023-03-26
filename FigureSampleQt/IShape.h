#pragma once

#include <QtPlugin>
#include <QGraphicsItem>

namespace FigureCommon
{
	//************************************
	// Interface for all shapes objects
	//************************************
	class IShape
	{
	public:

		virtual ~IShape() = default;

		//************************************
		// Method:    name - returns shape name, also serves as identifier for object factory
		// Returns:   QString - shape name
		//************************************
		virtual QString name() const = 0;

		//************************************
		// Method:    createFigure - create graphics item for QGraphicScene
		// Returns:   QGraphicsItem * - graphics item
		// Parameter: double size - shape size in QGraphicsScene
		//************************************
		virtual QGraphicsItem *createFigure(double size) const = 0;

	};
}

#define IShape_iid "4226938C-7BE1-4C39-85AB-B03623C56B8A"

Q_DECLARE_INTERFACE(FigureCommon::IShape, IShape_iid)