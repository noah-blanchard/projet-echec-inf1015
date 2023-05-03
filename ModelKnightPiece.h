/**
 * @file ModelKnightPiece.h
 * @author Noah Blanchard / Bai Wu Li
 * @brief Model for the Knight Piece
 * @date 20/04/2023
 */

#pragma once
#include "ModelPiece.h"

namespace logic {
    class ModelKnightPiece : public ModelPiece
    {
    public:
        ModelKnightPiece() = default;
        ModelKnightPiece(bool isWhite);

        //std::vector<ModelSquare*> getValidMoves(ModelChecker* checker, bool validate) override;

    private:
        static const std::string whiteImagePath_;
        static const std::string blackImagePath_;
    };
}

