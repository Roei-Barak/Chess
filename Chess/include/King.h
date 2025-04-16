#pragma once

#include "Piece.h"

class King : public Piece {
public:
    King(bool isWhite);

    char getSymbol() const override;
    bool isMoveLegal(int srcRow, int srcCol, int dstRow, int dstCol, Piece* const board[8][8]) const override;
};
