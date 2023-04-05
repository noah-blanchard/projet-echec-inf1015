#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include "EchiquierWindow.hpp"
#include "EchiquierCase.hpp"

namespace interface {
	EchiquierWindow::EchiquierWindow(QWidget* parent) : QMainWindow(parent) {
		QWidget* central = new QWidget(this);
		setCentralWidget(central);
		
		pointeurGrille = new QGridLayout(central);

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                EchiquierCase* nouvelleCase = new EchiquierCase(central);

                if ((i + j) % 2 == 0) {
                    nouvelleCase->setLight();
                }
                else {
                    nouvelleCase->setDark();
                }
                
                pointeurGrille->addWidget(nouvelleCase, i, j);
                connect(nouvelleCase, &EchiquierCase::cliqueCase, this, &EchiquierWindow::eventCliqueCase);
            }
        }

        central->setLayout(pointeurGrille);
        setWindowTitle("Echiquier");
        resize(500, 500);
	}

	void EchiquierWindow::eventCliqueCase() {
        EchiquierCase* caseCliquee = qobject_cast<EchiquierCase*>(sender());
		int ligne = 0, colonne = 0, spanLigne = 0, spanColonne = 0;
        pointeurGrille->getItemPosition(pointeurGrille->indexOf(caseCliquee), &ligne, &colonne, &spanLigne, &spanColonne);

		std::string message = "Vous avez clique sur une case : " + std::to_string(ligne) + ", " + std::to_string(colonne);
        QMessageBox::information(this, "Clique", message.c_str());
	}

    void EchiquierWindow::updatePieces(std::vector<logique::BasePiece*> pieces) {
        
        for (logique::BasePiece* piece : pieces) {
            logique::Position pos = piece->position;
            QWidget* item = pointeurGrille->itemAtPosition(pos.ligne, pos.ligne)->widget();
            EchiquierCase* label = qobject_cast<EchiquierCase*>(item);
            QPixmap pixmap(piece->image.c_str());
            label->setImage(pixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
        
    }
}