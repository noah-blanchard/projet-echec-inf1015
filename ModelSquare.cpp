#pragma once
#include "ModelSquare.h"

namespace logic {
	void ModelSquare::setPlayable() { 
		playable = !playable;
		emit playableSignal();
	}
}