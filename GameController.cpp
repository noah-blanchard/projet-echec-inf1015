#include "State.h"

namespace logic
{

	ModelChecker* GameController::startGameFileLayout(QFile* file, bool showChessboard) {
		logic::ModelKingPiece::resetInstanceCounter();
		ModelChecker* checkerModel = new ModelChecker();

		if (file->open(QIODevice::ReadOnly | QIODevice::Text)) {
			QTextStream in(file);

			while (!in.atEnd()) {
				QString line = in.readLine();
				QStringList fields = line.split(" ");

				int col = fields[0].toInt();
				int row = fields[1].toInt();
				bool isWhite = fields[2].toInt() == 1;
				QString pieceChar = fields[3];

				checkerModel->getSquareAtPosition(row, col)->setPiece(createPieceFromChar(pieceChar.toStdString()[0], isWhite));
				if (pieceChar.toStdString()[0] == 'K') {
					if (isWhite)
						checkerModel->setWhiteKingSquare(checkerModel->getSquareAtPosition(row, col));
					else
						checkerModel->setBlackKingSquare(checkerModel->getSquareAtPosition(row, col));
				}

				// Faites quelque chose avec les informations extraites
			}

			file->close();
		}

		currentTurn_ = whiteTurn_;

		if (showChessboard) {
			checkerView_ = nullptr;
			

			checkerView_ = std::make_unique<view::ViewCheckerMainWindow>(checkerModel);
			checkerView_->show();
		}

		return checkerModel;

	}

	std::shared_ptr<ModelPiece> GameController::createPieceFromChar(char pieceChar, bool isWhite) {
		switch (pieceChar)
		{
		case 'P':
			return std::make_shared<ModelPawnPiece>(isWhite, true);
		case 'K':
			return std::make_shared<ModelKingPiece>(isWhite);
		case 'Q':
			return std::make_shared<ModelQueenPiece>(isWhite);
		case 'B':
			return std::make_shared<ModelBishopPiece>(isWhite);
		case 'N':
			return std::make_shared<ModelKnightPiece>(isWhite);
		case 'R':
			return std::make_shared<ModelRook>(isWhite);
		default:
			return nullptr;
		}
	}
}