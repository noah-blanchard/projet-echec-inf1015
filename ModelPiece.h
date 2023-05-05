/**
 * @file ModelPiece.h
 * @author Noah Blanchard / Bai Wu Li
 * @brief Model for the Piece
 * @date 20/04/2023
 */

#pragma once
#include <string>
#include <vector>
#include <QObject>
//#include "ModelSquare.h"

namespace logic {

	template <typename T>
	class foo : public QObject
	{
	};

	class ModelPiece
	{
			
	public:
		ModelPiece() = default;
		ModelPiece(bool isWhite, std::string whitePath, std::string blackPath);
		~ModelPiece();

		bool isWhite();
		virtual std::vector<class ModelSquare*> getValidMoves(class ModelChecker* checker, bool validate) = 0;
		std::string getImagePath() const { return imagePath_; }
		void setCurrentSquare(ModelSquare * square);
		virtual bool isKing();
		//void move(ModelSquare* square);
	
	protected:
		ModelSquare* currentSquare = nullptr;
	private:
		std::string imagePath_;
		bool white_;

	/*signals:
		void movedSignal();*/
	};
}

