#pragma once
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include "BasePiece.hpp"

namespace interface {
	class EchiquierWindow : public QMainWindow {
		Q_OBJECT
	public:
		EchiquierWindow(QWidget* parent = nullptr);

		void updatePieces(std::vector<logique::BasePiece*> pieces);
	private:
		void eventCliqueCase();
		QGridLayout* pointeurGrille;
	};
}