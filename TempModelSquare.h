/**
 * @file TempModelSquare.h
 * @author Noah Blanchard / Bai Wu Li
 * @brief Temporary ModelSquare to implment RAII
 * @date 20/04/2023
 */

#pragma once
#include "ModelSquare.h"

namespace logic {

	// implémentation RAII
	class TempModelSquare {
	public:
		TempModelSquare() : modelSquare_(new ModelSquare()) {}
		~TempModelSquare();
		ModelSquare* operator->();
	private:
		ModelSquare* modelSquare_;
	};

}