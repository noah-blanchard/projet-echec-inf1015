#pragma once

#include <QMainWindow>
#include <QSplitter>

namespace view {
	class ViewMainWindow : public QMainWindow
	{
	public:
		ViewMainWindow(QWidget* checker, QWidget* controls = nullptr, QWidget* parent = nullptr);

	private:
		//QWidget* centralWidget_;
		std::unique_ptr<QWidget> centralWidget_;
		//QSplitter* splitterLayout_;
		std::unique_ptr<QSplitter> splitterLayout_;
	};
}

