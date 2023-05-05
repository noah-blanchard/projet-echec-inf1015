/**
 * @file ModelKnightPiece.h
 * @author Noah Blanchard / Bai Wu Li
 * @brief Model for the Knight Piece
 * @date 20/04/2023
 */

#pragma once
#include "ModelPiece.h"

namespace model {
    class Knight : public Piece
    {
    public:
        Knight() = default;
        Knight(bool isWhite);
        ~Knight();

    private:
        static const std::string whiteImagePath_;
        static const std::string blackImagePath_;
    };
}

