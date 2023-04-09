#pragma once
#include <string>
#include <vector>
#include <QObject>
//#include "ModelSquare.h"

namespace logic {
	class ModelPiece : public QObject
	{
		Q_OBJECT
			
	public:
		ModelPiece() = default;
		ModelPiece(bool isWhite, std::string whitePath, std::string blackPath);
		//~ModelPiece();

		bool isWhite();
		virtual std::vector<class ModelSquare*> getValidMoves(class ModelSquare* square, class ModelChecker* checker) = 0;
		std::string getImagePath() const { return imagePath; }
		//void move(ModelSquare* square);
	private:
		std::string imagePath;
		bool white;

	/*signals:
		void movedSignal();*/
	};
}

