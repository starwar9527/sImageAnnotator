/*
 * MainWindow.cpp
 *
 *  Created on: Mar 7, 2021
 *      Author: Allen
 */

#ifndef SRC_MAINWINDOW_CPP_
#define SRC_MAINWINDOW_CPP_

#include "MainWindow.hpp"

using namespace ImageAnnotator;

MainWindow::MainWindow():
		QMainWindow()
{
	connect(m_ImageAnnotator,
			&KImageAnnotator::tabCloseRequested,
			this,
			&MainWindow::tabCloseRequested);
}

MainWindow::~MainWindow()
{

}

void MainWindow::tabCloseRequested(int index)
{
	//removeTab(index);
}



#endif /* SRC_MAINWINDOW_CPP_ */
