#pragma once
#include "EchiquierCase.hpp";

namespace interface {
	class EchiquierCase : public QLabel
	{
		Q_OBJECT
	public:
		EchiquierCase(QWidget* parent) : QLabel(parent) {
			setFrameStyle(QFrame::Box);
			setMinimumSize(50, 50);
		}
	signals:
		void cliqueCase();

	private:
		void mousePressEvent(QMouseEvent* event) override {
			emit cliqueCase();
		}
	}
};