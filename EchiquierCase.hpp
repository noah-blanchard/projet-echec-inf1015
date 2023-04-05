#pragma once
#include <QLabel>

namespace interface {
	class EchiquierCase : public QLabel {
		Q_OBJECT
	public:
		EchiquierCase(QWidget* parent = nullptr);
		
		void setLight();
		void setDark();
		void setImage(QPixmap image);
	
	signals:
		void cliqueCase();
		
	private:
		void mousePressEvent(QMouseEvent* event) override;
	};
};