#pragma once
#include "CaseVue.hpp"

namespace interface {

		CaseVue::CaseVue(QWidget* parent) : QLabel(parent) {
			setFrameStyle(QFrame::Box);
			setMinimumSize(50, 50);
		}

		void CaseVue::setLight() {
			setStyleSheet("background-color: #face93;");
		}

		void CaseVue::setDark() {
			setStyleSheet("background-color: #784400;");
		}

		void CaseVue::mousePressEvent(QMouseEvent*) {
			emit cliqueCase();
		}

		void CaseVue::setImage(QPixmap image) {
			setPixmap(image.scaled(50, 50));
		}
	};
