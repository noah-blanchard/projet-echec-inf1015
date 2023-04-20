/**
 * @file ModelSquare.h
 * @author Noah Blanchard / Bai Wu Li
 * @brief Model for the Squares of the board
 * @date 20/04/2023
 */

#pragma once
#include "ModelPiece.h"
#include <QObject>

namespace logic {
	class ModelSquare : public QObject
	{
		Q_OBJECT
	public:
		ModelSquare() : light_(false), x_(-1), y_(-1) {}
		ModelSquare(bool isLight, int x, int y) : light_(isLight), x_(x), y_(y) {}
		//ModelSquare(bool isLight, int x, int y, ModelPiece* piece) : light(isLight), x(x), y(y), piece(piece) {}
		~ModelSquare();
		bool isLight() const { return light_; }
		int getX() const { return x_; }
		int getY() const { return y_; }
		std::shared_ptr<ModelPiece> getPiece() const { return piece_; }
		void setPiece(std::shared_ptr<ModelPiece> piece);
		void setPlayable(bool p);
		bool isPlayable() const { return playable_; }
	private:
		int x_, y_;
		bool light_ = false;
		bool playable_ = false;
		std::shared_ptr<ModelPiece> piece_ = nullptr;

	signals:
		void playableSignal();
		void updatePieceSignal();
	};
}

