#pragma once
#include "ModelPiece.h"

namespace logic {
    class ModelCavalierPiece : public ModelPiece
    {
    public:
        ModelCavalierPiece() = default;
        ModelCavalierPiece(bool isWhite);

        std::vector<ModelSquare*> getValidMoves(ModelChecker* checker) override;

    private:
        static const std::string whiteImagePath;
        static const std::string blackImagePath;
    };
}

