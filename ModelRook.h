#pragma once
#include "ModelPiece.h"

namespace logic {
    class ModelRook :
        public ModelPiece
    {
    public:
        ModelRook() = default;
        ModelRook(bool isWhite);
    private:
        static const std::string whiteImagePath_;
        static const std::string blackImagePath_;
    };
}
