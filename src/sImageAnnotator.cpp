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

	//QMainWindow mainWindow;
	MainWindow mainWindow;
	mainWindow.setWindowState(Qt::WindowMaximized);
	mainWindow.show();

	return app.exec();
}
