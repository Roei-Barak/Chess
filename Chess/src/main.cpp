// Chess 
#include <iostream>
#include "Chess.h"
#include "Board.h"
int main()
{
	string boardString =
		"rnbqkbnr"  // row 1 (Black)
		"pppppppp"  // row 2 (Black Pawns)
		"########"   // row 3
		"########"   // row 4
		"########"   // row 5
		"########"   // row 6
		"PPPPPPPP"   // row 7 (White Pawns)
		"RNBQKBNR";  // row 8 (White)

	//string board = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr"; 
	//string boardString = "R######R###############K##############k#################r######r";

//	string board = "##########K###############################R#############r#r#####";
	Chess a(boardString);
	Board board(boardString);
	int codeResponse = 0;
	string res = a.getInput();
	while (res != "exit")
	{
		/* 
		codeResponse value : 
		Illegal movements : 
		11 - there is not piece at the source  
		12 - the piece in the source is piece of your opponent
		13 - there one of your pieces at the destination 
		21 - illegal movement of that piece 
		31 - this movement will cause you checkmate

		legal movements : 
		41 - the last movement was legal and cause check 
		42 - the last movement was legal, next turn 
		*/

		/**/ 
		if (res.size() != 4) {
			codeResponse = 13;
		}
		else {
			int srcRow = res[0] - 'a';
			int srcCol = res[1] - '1';
			int dstRow = res[2] - 'a';
			int dstCol = res[3] - '1';

			bool isWhiteTurn = board.isWhiteTurn();  // getter  
			board.movePiece(srcRow, srcCol, dstRow, dstCol, isWhiteTurn, codeResponse);
		}

		/**/

		a.setCodeResponse(codeResponse);
		res = a.getInput(); 
	}

	cout << endl << "Exiting " << endl; 
	return 0;
}