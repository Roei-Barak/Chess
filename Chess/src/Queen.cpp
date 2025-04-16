#include "Queen.h"

Queen::Queen(bool isWhite) : Piece(isWhite) {}

char Queen::getSymbol() const {
    return isWhite ? 'Q' : 'q';
}

bool Queen::isMoveLegal(int srcRow, int srcCol, int dstRow, int dstCol, Piece* const board[8][8]) const {
    int rowDiff = dstRow - srcRow;
    int colDiff = dstCol - srcCol;

    if (srcRow == dstRow || srcCol == dstCol) {
        int stepRow = (dstRow == srcRow) ? 0 : (dstRow > srcRow ? 1 : -1);
        int stepCol = (dstCol == srcCol) ? 0 : (dstCol > srcCol ? 1 : -1);

        int r = srcRow + stepRow;
        int c = srcCol + stepCol;

        while (r != dstRow || c != dstCol) {
            if (board[r][c] != nullptr)
                return false;
            r += stepRow;
            c += stepCol;
        }
    }
    else if ((dstRow - srcRow) * (dstRow - srcRow) == (dstCol - srcCol) * (dstCol - srcCol)){
        int stepRow = (dstRow > srcRow) ? 1 : -1;
        int stepCol = (dstCol > srcCol) ? 1 : -1;

        int r = srcRow + stepRow;
        int c = srcCol + stepCol;

        while (r != dstRow || c != dstCol) {
            if (board[r][c] != nullptr)
                return false;
            r += stepRow;
            c += stepCol;
        }
    }
    else {
        return false;
    }

    Piece* dest = board[dstRow][dstCol];
    return dest == nullptr || dest->getIsWhite() != isWhite;
}
