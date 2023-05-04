#include "State.h"

namespace model
{

	Checker* GameController::startGameFileLayout(QFile* file, bool showChessboard) {
		model::King::resetInstanceCounter();
		Checker* checkerModel = new Checker();

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
			

			checkerView_ = std::make_unique<view::CheckerMainWindow>(checkerModel);
			checkerView_->show();
		}

		return checkerModel;

	}

	std::shared_ptr<Piece> GameController::createPieceFromChar(char pieceChar, bool isWhite) {
		switch (pieceChar)
		{
		case 'P':
			return std::make_shared<Pawn>(isWhite, true);
		case 'K':
			return std::make_shared<King>(isWhite);
		case 'Q':
			return std::make_shared<Queen>(isWhite);
		case 'B':
			return std::make_shared<Bishop>(isWhite);
		case 'N':
			return std::make_shared<Knight>(isWhite);
		case 'R':
			return std::make_shared<Rook>(isWhite);
		default:
			return nullptr;
		}
	}
}