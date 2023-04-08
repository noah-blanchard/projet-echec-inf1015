#pragma once
#include <string>
#include <vector>

namespace logic {
	class ModelPiece
	{
	public:
		ModelPiece() = default;
		ModelPiece(bool isWhite, std::string whitePath, std::string blackPath);
		~ModelPiece();

		bool isWhite();
		virtual std::vector<class ModelSquare*> getValidMoves(class ModelSquare* square, class ModelChecker* checker) = 0;
		std::string getImagePath() const { return imagePath; }
	private:
		std::string imagePath;
		bool white;
	};
}

