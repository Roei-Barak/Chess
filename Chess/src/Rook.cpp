#include "Rook.h"

Rook::Rook(bool isWhite) : Piece(isWhite) {}

char Rook::getSymbol() const {
    return isWhite ? 'R' : 'r';
}

bool Rook::isMoveLegal(int srcRow, int srcCol, int dstRow, int dstCol, Piece* const board[8][8]) const {
    if (srcRow != dstRow && srcCol != dstCol)
        return false;

    if (srcRow == dstRow) {
        int step = (dstCol > srcCol) ? 1 : -1;
        for (int col = srcCol + step; col != dstCol; col += step) {
            if (board[srcRow][col] != nullptr)
                return false;
        }
    }
    else {
        int step = (dstRow > srcRow) ? 1 : -1;
        for (int row = srcRow + step; row != dstRow; row += step) {
            if (board[row][srcCol] != nullptr)
                return false;
        }
    }

    Piece* destinationPiece = board[dstRow][dstCol];
    if (destinationPiece && destinationPiece->getIsWhite() == isWhite)
        return false;

    return true;
}
