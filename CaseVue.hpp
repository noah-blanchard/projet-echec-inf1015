#pragma once
#include <QLabel>

namespace interface {
	class CaseVue : public QLabel {
		Q_OBJECT
	public:
		CaseVue(QWidget* parent = nullptr);
		
		void setLight();
		void setDark();
		void setImage(QPixmap image);
	
	signals:
		void cliqueCase();
		
	private:
		void mousePressEvent(QMouseEvent* event) override;
	};
};