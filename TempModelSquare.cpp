/**
 * @file TempModelSquare.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief Implementation of the TempModelSquare class
 * @date 20/04/2023
 */

#pragma once
#include "TempModelSquare.h"

namespace logic
{
	TempModelSquare::~TempModelSquare()
	{
		delete modelSquare_;
	}
	
	ModelSquare* TempModelSquare::operator->()
	{
		return modelSquare_;
	}
}