#include <iostream>
#include <QGraphicsItem>
#include <QPolygonF>
#include <QPointF>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include "my_graphics_scene.hpp"

MyGraphicsScene::MyGraphicsScene(QObject *parent):QGraphicsScene(parent)
{
}


MyGraphicsScene::MyGraphicsScene(QRectF &rect, QObject *parent):QGraphicsScene(rect, parent)
{

}

void MyGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
	//qDebug() << "posX = " << mouseEvent->pos().x() << "; posY = " << mouseEvent->pos().y();
	if (mouseEvent->buttons() & Qt::LeftButton) {
		drawNextFigure(QPoint(mouseEvent->scenePos().x(), mouseEvent->scenePos().y()));
		std::cout << "scenePosX = " << mouseEvent->scenePos().x() << "; scenePosY = " << mouseEvent->scenePos().y() << std::endl;
	}
	if (mouseEvent->buttons() & Qt::RightButton) {
		if (items().last())
			delete items().first();
	}
	QGraphicsScene::mousePressEvent(mouseEvent);
}


void MyGraphicsScene::drawNextFigure(const QPoint &coordinates)
{
	static figures currentFigure = Rectangle;
	QRectF rect(coordinates.x(), coordinates.y(), 20, 20);
	QPolygonF polygon;
	polygon << QPointF(coordinates.x()+4, coordinates.y()+0) << QPointF(coordinates.x()+8, coordinates.y()+8) << 
		QPointF(coordinates.x()+0, coordinates.y()+12) << QPointF(coordinates.x()+8, coordinates.y()+12) 
		<< QPointF(coordinates.x()+12, coordinates.y()+20) << QPointF(coordinates.x()+16, coordinates.y()+12) 
		<< QPointF(coordinates.x()+24, coordinates.y()+12) << QPointF(coordinates.x()+16, coordinates.y()+8)
		<< QPointF(coordinates.x()+20, coordinates.y()+0) << QPointF(coordinates.x()+12, coordinates.y()+4);
	switch (currentFigure) {
		case Rectangle:
			currentFigure = Ellipse;
			addRect(rect);
			break;
		case Ellipse:
			currentFigure = Asterisk;
			addEllipse(rect);
			break;
		case Asterisk:
			addPolygon(polygon);
			currentFigure = Rectangle;
			break;
		default:
			;
	}
}

