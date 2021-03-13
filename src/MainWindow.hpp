/*
 * MainWindow.hpp
 *
 *  Created on: Mar 7, 2021
 *      Author: Allen
 */

#ifndef SRC_MAINWINDOW_HPP_
#define SRC_MAINWINDOW_HPP_

#include <QMainWindow>
#include <kImageAnnotator/KImageAnnotator.h>

using kImageAnnotator::KImageAnnotator;

namespace ImageAnnotator
{
class MainWindow: public QMainWindow
{
	Q_OBJECT
public:
	explicit MainWindow(KImageAnnotator *imageAnnotator);
	~MainWindow() override;

private slots:
	void tabCloseRequested(int index);

private:
	KImageAnnotator *m_ImageAnnotator;
};

}


#endif /* SRC_MAINWINDOW_HPP_ */
