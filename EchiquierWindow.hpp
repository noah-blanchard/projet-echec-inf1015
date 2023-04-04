#pragma once
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

namespace interface {
	class EchiquierWindow : public QMainWindow {
		Q_OBJECT
	public:
		EchiquierWindow(QWidget* parent = nullptr);
	private:
		void eventCliqueCase();
		QGridLayout* pointeurGrille;
	};
}