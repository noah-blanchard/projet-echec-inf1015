#pragma once
#include "ModelPiece.h"

namespace model {
    class Rook :
        public Piece
    {
    public:
        Rook() = default;
        Rook(bool isWhite);
    private:
        static const std::string whiteImagePath_;
        static const std::string blackImagePath_;
    };
}
