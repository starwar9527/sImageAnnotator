#include <iostream>
using namespace std;


#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QMenuBar>
#include "MainWindow.hpp"

#include <kImageAnnotator/KImageAnnotator.h>

using kImageAnnotator::KImageAnnotator;
using namespace ImageAnnotator;


int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	QPixmap pixmap(QSize(500, 500));
	pixmap.fill(QColor(Qt::darkGreen));
	auto kImageAnnotator = new KImageAnnotator();
	kImageAnnotator->addTab(pixmap, QStringLiteral("image1"), QStringLiteral("image1"));
	kImageAnnotator->addTab(pixmap, QStringLiteral("image2"), QStringLiteral("image2"));
	kImageAnnotator->adjustSize();

	//QMainWindow mainWindow;
	MainWindow mainWindow(kImageAnnotator);
	mainWindow.setCentralWidget(kImageAnnotator);
	auto menuBar = mainWindow.menuBar();
	auto menu = new QMenu(QStringLiteral("Edit"));
	auto annotationAction = new QAction(QStringLiteral("Annotation"), &mainWindow);
	auto cropAction = new QAction(QStringLiteral("Crop"), &mainWindow);
	auto scaleAction = new QAction(QStringLiteral("Scale"), &mainWindow);
	auto modifyCanvasAction = new QAction(QStringLiteral("Modify Canvas"), &mainWindow);
	mainWindow.connect(annotationAction, &QAction::triggered, kImageAnnotator, &KImageAnnotator::showAnnotator);
	mainWindow.connect(cropAction, &QAction::triggered, kImageAnnotator, &KImageAnnotator::showCropper);
	mainWindow.connect(scaleAction, &QAction::triggered, kImageAnnotator, &KImageAnnotator::showScaler);
	mainWindow.connect(modifyCanvasAction, &QAction::triggered, kImageAnnotator, &KImageAnnotator::showCanvasModifier);
	menu->addAction(annotationAction);
	menu->addAction(cropAction);
	menu->addAction(scaleAction);
	menu->addAction(modifyCanvasAction);
	menuBar->addMenu(menu);
	mainWindow.show();
	mainWindow.setMinimumSize(kImageAnnotator->sizeHint());

	QPixmap imageItem(QSize(100, 100));
	imageItem.fill(QColor(Qt::yellow));
	kImageAnnotator->insertImageItem(QPointF(100,100), imageItem);

	return app.exec();
}
