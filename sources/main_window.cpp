#include "main_window.hpp"
#include <QMessageBox>
#include <QPushButton>
#include <QRectF>
#include <QPointF>
#include "my_graphics_scene.hpp"

MainWindow::MainWindow(QWidget *parent)
   : QGraphicsView(parent)
{   
	/*mainWidget = new QWidget(this);
	setCentralWidget(mainWidget);*/
	//pushButtonMessage = new QPushButton("What", this);
	QRectF rect(QPointF(0, 0), QPointF(400, 300));
   scene = new MyGraphicsScene(rect, this);                      // Новая сцена
   setScene(scene);
}

MainWindow::~MainWindow()
{

}
