#include "Pawn.h"

Pawn::Pawn(bool isWhite) : Piece(isWhite) {}

char Pawn::getSymbol() const {
    return isWhite ? 'P' : 'p';
}

bool Pawn::isMoveLegal(int srcRow, int srcCol, int dstRow, int dstCol, Piece* const board[8][8]) const {
    if (dstRow < 0 || dstRow > 7 || dstCol < 0 || dstCol > 7)
        return false;

    int direction = isWhite ? -1 : 1;
    int startRow = isWhite ? 6 : 1;

    Piece* dest = board[dstRow][dstCol];

    if (dstCol == srcCol) {
        if (dstRow == srcRow + direction && dest == nullptr)
            return true;

        if (srcRow == startRow && dstRow == srcRow + 2 * direction &&
            dest == nullptr && board[srcRow + direction][srcCol] == nullptr)
            return true;
    }

    if ((dstCol == srcCol + 1 || dstCol == srcCol - 1) &&
        dstRow == srcRow + direction &&
        dest != nullptr && dest->getIsWhite() != isWhite)
        return true;

    return false;
}
