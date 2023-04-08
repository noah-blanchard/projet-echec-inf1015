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
	class EchiquierVue : public QMainWindow {
		Q_OBJECT
	public:
		EchiquierVue(QWidget* parent = nullptr);

		void updatePieces(std::vector<logique::BasePiece*> pieces);
	private:
		void eventCliqueCase();
		QGridLayout* pointeurGrille;
	};
}