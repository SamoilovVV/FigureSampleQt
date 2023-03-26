#pragma once

#include <QGraphicsScene>

#include "IShape.h"

class FigureScene : public QGraphicsScene
{
	Q_OBJECT
public:
	explicit FigureScene(QObject *parent = nullptr);
	


public:
	//************************************
	// Method:    setCurrentShape - sets current shape mode
	// Parameter: FigureCommon::IShape * newShape - pointer to shape
	//************************************
	void setCurrentShape(FigureCommon::IShape *newShape) { m_currentShape = newShape; }

protected:
	//************************************
	// Method:    mouseReleaseEvent - mouse release event handler
	// Parameter: QGraphicsSceneMouseEvent * mouseEvent - event
	//************************************
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent) override;

private:
	FigureCommon::IShape *m_currentShape = nullptr;// current shape creator

	//************************************
	// Method:    createItem - create graphics item at given position
	// Returns:   QGraphicsItem * - newly created QGraphicsItem, nullptr if creation failed
	// Parameter: QPointF pos
	//************************************
	QGraphicsItem * createItem(QPointF pos) const;
};


