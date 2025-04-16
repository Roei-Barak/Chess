#pragma once

class Piece {
protected:
    bool isWhite;

public:
    Piece(bool isWhite) : isWhite(isWhite) {}
    virtual ~Piece() = default;

    bool getIsWhite() const { return isWhite; }

        virtual bool isMoveLegal(int srcRow, int srcCol, int dstRow, int dstCol, Piece* const board[8][8]) const = 0;

    virtual char getSymbol() const = 0;
};
