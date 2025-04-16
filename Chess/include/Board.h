#pragma once

#include <string>
#include "Piece.h"
#include "Rook.h"

class Board {
private:
    Piece* board[8][8];
    bool whiteTurn;

public:
    Board(); 
    Board(const std::string& boardString); // 
    ~Board();

    bool movePiece(int srcRow, int srcCol, int dstRow, int dstCol, bool isWhiteTurn, int& resultCode);
    void printBoard() const;

    bool isWhiteTurn() const; // getter 

    Piece* getPieceAt(int row, int col) const;
    bool isCheck(bool forWhite) const;
    bool hasAnyLegalMove(bool forWhite);
};
