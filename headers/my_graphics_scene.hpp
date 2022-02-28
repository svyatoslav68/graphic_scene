#ifndef MYGRAPHICSCENE_HPP
#define MYGRAPHICSCENE_HPP

#include <QGraphicsScene>

class QGraphicsSceneMouseEvent;
class QRectF;

class MyGraphicsScene:public QGraphicsScene
{
public:
	enum figures{Rectangle, Ellipse, Asterisk};
	MyGraphicsScene(QObject *parent = nullptr);
	MyGraphicsScene(QRectF &rect, QObject *parent = nullptr);
	~MyGraphicsScene() {}
private:
	void drawNextFigure(const QPoint &coordinates);
protected:
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);

};

#endif //MYGRAPHICSCENE_HPP
