/*
 * MainWindow.cpp
 *
 *  Created on: Mar 7, 2021
 *      Author: Allen
 */

#ifndef SRC_MAINWINDOW_CPP_
#define SRC_MAINWINDOW_CPP_

#include <QMainWindow>
#include <QVBoxLayout>
#include <QMenuBar>

#include "MainWindow.hpp"
#include <iostream>
#include <stdexcept>

using namespace ImageAnnotator;

MainWindow::MainWindow():
		QMainWindow()
{
	QPixmap pixmap(QSize(500, 500));
	pixmap.fill(QColor(Qt::darkGreen));
	m_ImageAnnotator = new KImageAnnotator();
	m_ImageAnnotator->addTab(pixmap, QStringLiteral("image1"), QStringLiteral("image1"));
	m_ImageAnnotator->addTab(pixmap, QStringLiteral("image2"), QStringLiteral("image2"));
	m_ImageAnnotator->adjustSize();

	setCentralWidget(m_ImageAnnotator);
	auto menuBar = this->menuBar();
	auto menu = new QMenu(QStringLiteral("Edit"));
	auto annotationAction = new QAction(QStringLiteral("Annotation"), this);
	auto cropAction = new QAction(QStringLiteral("Crop"), this);
	auto scaleAction = new QAction(QStringLiteral("Scale"), this);
	auto modifyCanvasAction = new QAction(QStringLiteral("Modify Canvas"), this);
	connect(annotationAction, &QAction::triggered, m_ImageAnnotator, &KImageAnnotator::showAnnotator);
	connect(cropAction, &QAction::triggered, m_ImageAnnotator, &KImageAnnotator::showCropper);
	connect(scaleAction, &QAction::triggered, m_ImageAnnotator, &KImageAnnotator::showScaler);
	connect(modifyCanvasAction, &QAction::triggered, m_ImageAnnotator, &KImageAnnotator::showCanvasModifier);
	menu->addAction(annotationAction);
	menu->addAction(cropAction);
	menu->addAction(scaleAction);
	menu->addAction(modifyCanvasAction);
	menuBar->addMenu(menu);
	//show();
	setMinimumSize(m_ImageAnnotator->sizeHint());

	QPixmap imageItem(QSize(100, 100));
	imageItem.fill(QColor(Qt::yellow));
	m_ImageAnnotator->insertImageItem(QPointF(100,100), imageItem);


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
