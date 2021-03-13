#include <iostream>
using namespace std;


#include <QApplication>
//#include <QMainWindow>
//#include <QVBoxLayout>
//#include <QMenuBar>
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

	return app.exec();
}
