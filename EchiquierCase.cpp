#pragma once
#include "EchiquierCase.hpp";

namespace interface {

		EchiquierCase::EchiquierCase(QWidget* parent) : QLabel(parent) {
			setFrameStyle(QFrame::Box);
			setMinimumSize(50, 50);
		}

		void EchiquierCase::setLight() {
			setStyleSheet("background-color: #face93;");
		}

		void EchiquierCase::setDark() {
			setStyleSheet("background-color: #784400;");
		}

		void EchiquierCase::mousePressEvent(QMouseEvent* event) {
			emit cliqueCase();
		}
	};
