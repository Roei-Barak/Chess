#include "Knight.h"

Knight::Knight(bool isWhite) : Piece(isWhite) {}

char Knight::getSymbol() const {
    return isWhite ? 'N' : 'n';
}

bool Knight::isMoveLegal(int srcRow, int srcCol, int dstRow, int dstCol, Piece* const board[8][8]) const {
    int rowDiff = dstRow - srcRow;
    int colDiff = dstCol - srcCol;

    if ((rowDiff == 2 && colDiff == 1) || (rowDiff == -2 && colDiff == 1) ||
        (rowDiff == 2 && colDiff == -1) || (rowDiff == -2 && colDiff == -1) ||
        (rowDiff == 1 && colDiff == 2) || (rowDiff == -1 && colDiff == 2) ||
        (rowDiff == 1 && colDiff == -2) || (rowDiff == -1 && colDiff == -2)) {
        Piece* dest = board[dstRow][dstCol];
        return dest == nullptr || dest->getIsWhite() != isWhite;
    }

    return false;
}
