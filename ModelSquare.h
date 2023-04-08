#pragma once
#include "ModelPiece.h"
#include <QObject>

namespace logic {
	class ModelSquare : public QObject
	{
		Q_OBJECT
	public:
		ModelSquare(bool isLight, int x, int y) : light(isLight), x(x), y(y) {}
		//ModelSquare(bool isLight, int x, int y, ModelPiece* piece) : light(isLight), x(x), y(y), piece(piece) {}
		//~ModelSquare();
		bool isLight() const { return light; }
		int getX() const { return x; }
		int getY() const { return y; }
		ModelPiece* getPiece() const { return piece; }
		void setPiece(ModelPiece* piece) { this->piece = piece; }
		void setPlayable();
		bool isPlayable() const { return playable; }
	private:
		int x, y;
		bool light = false;
		bool playable = false;
		ModelPiece* piece = nullptr;

	signals:
		void playableSignal();
	};
}

