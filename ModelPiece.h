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
		~ModelPiece();

		bool isWhite();
		virtual std::vector<class ModelSquare*> getValidMoves(class ModelChecker* checker, bool validate) = 0;
		std::string getImagePath() const { return imagePath; }
		void setCurrentSquare(ModelSquare * square);
		virtual bool isKing();
		//void move(ModelSquare* square);
	
	protected:
		ModelSquare* currentSquare = nullptr;
	private:
		std::string imagePath;
		bool white;

	/*signals:
		void movedSignal();*/
	};
}

