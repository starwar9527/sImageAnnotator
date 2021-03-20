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
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>

#include "MainWindow.hpp"
#include <iostream>
#include <stdexcept>

using namespace ImageAnnotator;

MainWindow::MainWindow():
		QMainWindow()
{
	QPixmap pixmap(QSize(500, 500));
	pixmap.fill(QColor(Qt::white));
	m_ImageAnnotator = new KImageAnnotator();
	m_ImageAnnotator->addTab(pixmap, QStringLiteral("image1"), QStringLiteral("image1"));
//	m_ImageAnnotator->addTab(pixmap, QStringLiteral("image2"), QStringLiteral("image2"));
//	m_ImageAnnotator->addTab(pixmap, QStringLiteral("image3"), QStringLiteral("image3"));
//	m_ImageAnnotator->adjustSize();
	m_ImageAnnotator->setTabBarAutoHide(false);
	m_ImageAnnotator->setWindowState(Qt::WindowMaximized);


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
	setMinimumSize(m_ImageAnnotator->sizeHint());

//	QPixmap imageItem(QSize(100, 100));
//	imageItem.fill(QColor(Qt::yellow));
//	m_ImageAnnotator->insertImageItem(QPointF(100,100), imageItem);


	bool connected = connect(m_ImageAnnotator,
			&KImageAnnotator::tabCloseRequested,
			this,
			&MainWindow::tabCloseRequested);
	if(!connected)
		throw std::runtime_error("not connected");

//	connect(m_ImageAnnotator,
//			&KImageAnnotator::tabCloseRequested,
//			qApp, &QApplication::aboutQt);

	setCentralWidget(m_ImageAnnotator);
}

MainWindow::~MainWindow()
{

}

void MainWindow::tabCloseRequested(int index)
{
	if(discardChanges(index))
	{
		std::cout<<"changes not discarded!"<<std::endl;
		m_ImageAnnotator->removeTab(index);
	}
	else
	{
		std::cout<<"changes discarded!"<<std::endl;
	}

}

bool MainWindow::discardChanges(int index)
{
	QString title("Warning-SaveImage");
	QString question("Do you want to save the change?");

	auto reply = QMessageBox::question(nullptr, title, question,
			QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

	if(reply == QMessageBox::No)
		return true;
	else if(reply == QMessageBox::Cancel)
		return false;
	else
		return saveImage();
}

bool MainWindow::saveImage()
{
	//std::cout<<"Image saved"<<std::endl;
	QString filename = QFileDialog::getSaveFileName(
			this,
			tr("Save Image"),
			"",
			tr("Images (*.png *.xpm *.jpg);; All Files (*))") );

	//qDebug()<<"image is saved to file "<<filename;
}

#endif /* SRC_MAINWINDOW_CPP_ */
