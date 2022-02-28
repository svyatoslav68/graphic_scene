#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>

class MyGraphicsScene;
class QPushButton;
class QWidget;

class MainWindow : public QGraphicsView
{
   Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
private:
	QGraphicsView *view;
	//QWidget *mainWidget;
	//QPushButton *pushButtonMessage;
	MyGraphicsScene *scene;
	//void drawNextFigure();
protected:
private slots:

};

#endif // MAINWINDOW_H

