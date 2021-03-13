/*
 * MainWindow.cpp
 *
 *  Created on: Mar 7, 2021
 *      Author: Allen
 */

#ifndef SRC_MAINWINDOW_CPP_
#define SRC_MAINWINDOW_CPP_

#include <QApplication>
#include "MainWindow.hpp"
#include <iostream>
#include <stdexcept>

using namespace ImageAnnotator;

MainWindow::MainWindow(KImageAnnotator* imageAnnotator):
		QMainWindow(),
		m_ImageAnnotator(imageAnnotator)
{
	bool connected = connect(m_ImageAnnotator,
			&KImageAnnotator::tabCloseRequested,
			this,
			&MainWindow::tabCloseRequested);
	if(!connected)
		throw std::runtime_error("not connected");

//	connect(m_ImageAnnotator,
//			&KImageAnnotator::tabCloseRequested,
//			qApp, &QApplication::aboutQt);
}

MainWindow::~MainWindow()
{

}

void MainWindow::tabCloseRequested(int index)
{
	std::cout<<"MainWindow::tabCloseRequested is called"<<std::endl;
	//removeTab(index);
	m_ImageAnnotator->removeTab(index);
}



#endif /* SRC_MAINWINDOW_CPP_ */
