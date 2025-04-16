#pragma once
#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(bool isWhite);
    char getSymbol() const override;
    bool isMoveLegal(int srcRow, int srcCol, int dstRow, int dstCol, Piece* const board[8][8]) const override;
};
