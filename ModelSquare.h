/**
 * @file ModelSquare.h
 * @author Noah Blanchard / Bai Wu Li
 * @brief Model for the Squares of the board
 * @date 20/04/2023
 */

#pragma once
#include "ModelPiece.h"
#include <QObject>


namespace model {
	class Square : public QObject
	{
		Q_OBJECT
	public:
		Square() : light_(false), x_(-1), y_(-1) {}
		Square(bool isLight, int x, int y) : light_(isLight), x_(x), y_(y) {}
		//ModelSquare(bool isLight, int x, int y, ModelPiece* piece) : light(isLight), x(x), y(y), piece(piece) {}
		~Square();
		bool isLight() const { return light_; }
		int getX() const { return x_; }
		int getY() const { return y_; }
		std::shared_ptr<Piece> getPiece() const { return piece_; }
		void setPiece(std::shared_ptr<Piece> piece);
		void setPlayable(bool p);
		bool isPlayable() const { return playable_; }
		void transformPiece(std::string selected);
		void emitTransformSignal();
	private:
		int x_, y_;
		bool light_ = false;
		bool playable_ = false;
		std::shared_ptr<Piece> piece_ = nullptr;

	signals:
		void playableSignal();
		void updatePieceSignal();
		void transformPieceSignal();
	};
}

