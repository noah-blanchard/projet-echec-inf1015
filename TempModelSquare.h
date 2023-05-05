/**
 * @file TempModelSquare.h
 * @author Noah Blanchard / Bai Wu Li
 * @brief Temporary ModelSquare to implment RAII
 * @date 20/04/2023
 */

#pragma once
#include "ModelSquare.h"

namespace model {

	class TempSquare {
	public:
		TempSquare() : modelSquare_(new Square()) {}
		~TempSquare();
		Square* operator->();
	private:
		Square* modelSquare_;
	};

}