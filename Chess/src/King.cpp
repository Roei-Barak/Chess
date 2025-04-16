
#include "King.h"

King::King(bool isWhite) : Piece(isWhite) {}

char King::getSymbol() const {
    return isWhite ? 'K' : 'k';
}

bool King::isMoveLegal(int srcRow, int srcCol, int dstRow, int dstCol, Piece* const board[8][8]) const {
    int rowDiff = dstRow - srcRow;
    int colDiff = dstCol - srcCol;

    if (rowDiff >= -1 && rowDiff <= 1 && colDiff >= -1 && colDiff <= 1) {
        if (rowDiff != 0 || colDiff != 0) {
            Piece* dest = board[dstRow][dstCol];
            if (dest == nullptr || dest->getIsWhite() != isWhite) {
                return true;
            }
        }
    }

    return false;
}
