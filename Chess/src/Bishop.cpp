#include "Bishop.h"

Bishop::Bishop(bool isWhite) : Piece(isWhite) {}

char Bishop::getSymbol() const {
    return isWhite ? 'B' : 'b';
}

bool Bishop::isMoveLegal(int srcRow, int srcCol, int dstRow, int dstCol, Piece* const board[8][8]) const {
    int rowDiff = dstRow - srcRow;
    int colDiff = dstCol - srcCol;

    if (rowDiff * rowDiff != colDiff * colDiff)
        return false;

    int rowStep = (rowDiff > 0) ? 1 : -1;
    int colStep = (colDiff > 0) ? 1 : -1;

    int r = srcRow + rowStep;
    int c = srcCol + colStep;

    while (r != dstRow || c != dstCol) {
        if (board[r][c] != nullptr)
            return false;
        r += rowStep;
        c += colStep;
    }

    Piece* dest = board[dstRow][dstCol];
    return dest == nullptr || dest->getIsWhite() != isWhite;
}
