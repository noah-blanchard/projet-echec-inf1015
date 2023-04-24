#include "ViewMainWindow.h"

namespace view {
	ViewMainWindow::ViewMainWindow(QWidget* checker, QWidget* controls, QWidget* parent) : QMainWindow(parent)
	{
		setWindowTitle("Chess Game");
		setFixedSize(1000, 500);
		//centralWidget_ = new QWidget(this);
		centralWidget_ = std::make_unique<QWidget>(this);
		//splitterLayout_ = new QSplitter(Qt::Horizontal, centralWidget_);
		splitterLayout_ = std::make_unique<QSplitter>(Qt::Horizontal, centralWidget_.get());
		splitterLayout_->setGeometry(0,0, 1000, 500);
		splitterLayout_->addWidget(checker);
		if (controls != nullptr) {
			splitterLayout_->addWidget(controls);
		}
		this->setCentralWidget(centralWidget_.get());
	}
}