#include "Board.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include <iostream>
#include "Pawn.h"
#include"Knight.h"
Board::Board() {
    for (int row = 0; row < 8; ++row)
        for (int col = 0; col < 8; ++col)
            board[row][col] = nullptr;

    whiteTurn = true;
}

Board::Board(const std::string& boardString) {
    int index = 0;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col, ++index) {
            char c = boardString[index];
            switch (c) {
            case 'R': board[row][col] = new Rook(true); break;
            case 'r': board[row][col] = new Rook(false); break;
            case 'K': board[row][col] = new King(true); break;
            case 'k': board[row][col] = new King(false); break;
            case 'Q': board[row][col] = new Queen(true); break;
            case 'q': board[row][col] = new Queen(false); break;
            case 'B': board[row][col] = new Bishop(true); break;
            case 'b': board[row][col] = new Bishop(false); break;
            case 'P': board[row][col] = new Pawn(true); break;
            case 'p': board[row][col] = new Pawn(false); break;
            case 'N': board[row][col] = new Knight(true); break;
            case 'n': board[row][col] = new Knight(false); break;

            default: board[row][col] = nullptr; break;
            }
        }
    }
    whiteTurn = true;
}

Board::~Board() {
    for (int row = 0; row < 8; ++row)
        for (int col = 0; col < 8; ++col)
            delete board[row][col];
}

bool Board::isWhiteTurn() const {
    return whiteTurn;
}

Piece* Board::getPieceAt(int row, int col) const {
    return board[row][col];
}

bool Board::isCheck(bool forWhite) const {
    int kingRow = -1, kingCol = -1;

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            Piece* p = board[row][col];
            if (p && p->getIsWhite() == forWhite) {
                char sym = p->getSymbol();
                if (sym == 'K' || sym == 'k') {
                    kingRow = row;
                    kingCol = col;
                    break;
                }
            }
        }
    }

    if (kingRow == -1 || kingCol == -1)
        return false;

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            Piece* p = board[row][col];
            if (p && p->getIsWhite() != forWhite) {
                if (p->isMoveLegal(row, col, kingRow, kingCol, board))
                    return true;
            }
        }
    }

    return false;
}

bool Board::hasAnyLegalMove(bool forWhite) {
    for (int srcRow = 0; srcRow < 8; ++srcRow) {
        for (int srcCol = 0; srcCol < 8; ++srcCol) {
            Piece* piece = board[srcRow][srcCol];
            if (piece && piece->getIsWhite() == forWhite) {
                for (int dstRow = 0; dstRow < 8; ++dstRow) {
                    for (int dstCol = 0; dstCol < 8; ++dstCol) {
                        if (srcRow == dstRow && srcCol == dstCol)
                            continue;

                        if (piece->isMoveLegal(srcRow, srcCol, dstRow, dstCol, board)) {
                            Piece* backupDst = board[dstRow][dstCol];

                            board[dstRow][dstCol] = piece;
                            board[srcRow][srcCol] = nullptr;

                            bool stillInCheck = isCheck(forWhite);

                            board[srcRow][srcCol] = piece;
                            board[dstRow][dstCol] = backupDst;

                            if (!stillInCheck)
                                return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}

bool Board::movePiece(int srcRow, int srcCol, int dstRow, int dstCol, bool isWhiteTurn, int& resultCode) {
    if (srcRow < 0 || srcRow > 7 || srcCol < 0 || srcCol > 7 ||
        dstRow < 0 || dstRow > 7 || dstCol < 0 || dstCol > 7) {
        resultCode = 21;
        return false;
    }

    Piece* piece = board[srcRow][srcCol];
    Piece* dest = board[dstRow][dstCol];

    if (piece == nullptr) {
        resultCode = 11;
        return false;
    }

    if (piece->getIsWhite() != isWhiteTurn) {
        resultCode = 12;
        return false;
    }

    if (dest && dest->getIsWhite() == isWhiteTurn) {
        resultCode = 13;
        return false;
    }

    if (!piece->isMoveLegal(srcRow, srcCol, dstRow, dstCol, board)) {
        resultCode = 21;
        return false;
    }

    Piece* backup = board[dstRow][dstCol];
    board[dstRow][dstCol] = piece;
    board[srcRow][srcCol] = nullptr;

    if (isCheck(isWhiteTurn)) {
        board[srcRow][srcCol] = piece;
        board[dstRow][dstCol] = backup;
        resultCode = 31;
        return false;
    }

    delete backup;
    whiteTurn = !whiteTurn;

    if (isCheck(!isWhiteTurn)) {
        //if (!hasAnyLegalMove(!isWhiteTurn)) {
        //    resultCode = 99;
        //}
        ///else {
            resultCode = 41;
        //}
    }
    else {
        resultCode = 42;
    }

    return true;
}

void Board::printBoard() const {
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (board[row][col])
                std::cout << board[row][col]->getSymbol() << " ";
            else
                std::cout << ". ";
        }
        std::cout << std::endl;
    }
}
