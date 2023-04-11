﻿#pragma once
#include <QApplication>

#if __has_include("bibliotheque_cours.hpp")
#include "bibliotheque_cours.hpp"
#define BIBLIOTHEQUE_COURS_INCLUS
using bibliotheque_cours::cdbg;
#else
auto& cdbg = clog;
#endif

#if __has_include("verification_allocation.hpp")
#include "verification_allocation.hpp"
#include "debogage_memoire.hpp"  //NOTE: Incompatible avec le "placement new", ne pas utiliser cette entête si vous utilisez ce type de "new" dans les lignes qui suivent cette inclusion.
#endif

#include "ViewChecker.h"
//#include "ModelChecker.h"
//#include "ModelRoiPiece.h"
#include "ModelFouPiece.h"
#include "ModelReinePiece.h"
#include "ModelRoiPiece.h"
#include "ModelPionPiece.h"

void initialiserBibliothequeCours([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
	#ifdef BIBLIOTHEQUE_COURS_INCLUS
	bibliotheque_cours::activerCouleursAnsi();  // Permet sous Windows les "ANSI escape code" pour changer de couleurs https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac les supportent normalement par défaut.

	// cdbg.setTee(&clog);  // Décommenter cette ligne pour que cdbg affiche sur la console en plus de la "Sortie" du débogueur.
	
	bibliotheque_cours::executerGoogleTest(argc, argv); // Attention de ne rien afficher avant cette ligne, sinon l'Explorateur de tests va tenter de lire votre affichage comme un résultat de test.
	#endif
	//NOTE: C'est normal que la couverture de code dans l'Explorateur de tests de Visual Studio ne couvre pas la fin de cette fonction ni la fin du main après l'appel à cette fonction puisqu'il exécute uniquement les tests Google Test dans l'appel ci-dessus.
}

int main(int argc, char *argv[])
{
	bibliotheque_cours::VerifierFuitesAllocations verifierFuitesAllocations;
	QApplication app(argc, argv);
	initialiserBibliothequeCours(argc, argv);

	logic::ModelChecker model;
	/*model.getSquareAtPosition(0, 2)->setPiece(new logic::ModelFouPiece(false));
	model.getSquareAtPosition(0, 3)->setPiece(new logic::ModelReinePiece(false));
	model.getSquareAtPosition(0, 4)->setPiece(new logic::ModelRoiPiece(false));
	model.getSquareAtPosition(0, 5)->setPiece(new logic::ModelFouPiece(false));

	model.getSquareAtPosition(7, 2)->setPiece(new logic::ModelFouPiece(true));
	model.getSquareAtPosition(7, 4)->setPiece(new logic::ModelReinePiece(true));
	model.getSquareAtPosition(7, 3)->setPiece(new logic::ModelRoiPiece(true));
	model.getSquareAtPosition(7, 5)->setPiece(new logic::ModelFouPiece(true));*/

	model.getSquareAtPosition(0, 3)->setPiece(new logic::ModelRoiPiece(false));
	model.getSquareAtPosition(5, 0)->setPiece(new logic::ModelRoiPiece(true));
	model.getSquareAtPosition(5, 6)->setPiece(new logic::ModelPionPiece(false, false));
	model.getSquareAtPosition(6, 0)->setPiece(new logic::ModelFouPiece(true));
	model.getSquareAtPosition(6, 2)->setPiece(new logic::ModelFouPiece(false));
	
	view::ViewChecker view(&model);

	view.show();
	

	return app.exec();
}
