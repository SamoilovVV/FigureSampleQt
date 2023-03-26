#include "FigureScene.h"
#include <QGraphicsSceneMouseEvent>

#include "circle.h"
#include "Square.h"

#include "IShape.h"

#include <memory>

const int minSize = 20;
const int maxSize = 200;


FigureScene::FigureScene(QObject *parent /*= 0*/) : QGraphicsScene(parent)
{
	this->setSceneRect(0, 0, 2000, 2000);
}

void FigureScene::mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
	QGraphicsItem * item = createItem(mouseEvent->scenePos());
	if (item != nullptr) {
		this->addItem(createItem(mouseEvent->scenePos()));
	}		
}

QGraphicsItem * FigureScene::createItem(QPointF pos) const
{
	if (nullptr == m_currentShape)
		return nullptr;

	int sz = rand() % (maxSize-minSize) + minSize;
	
	auto retItem = m_currentShape->createFigure(sz);
	retItem->setPos(pos);
	return retItem;
}
