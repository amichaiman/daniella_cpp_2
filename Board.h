/*
 * Board.h
 *
 *  Created on: Nov 16, 2018
 *      Author: cs306438375
 */
#include "Spot.h"

#ifndef BOARD_H_
#define BOARD_H_

class Board {
public:
	static const int BOARDSIZE = 8;
	Board();
	void printBoard();
	void set(int i, int j, Spot::spotValue value);
    Spot::spotValue get(int i, int j);

	Spot::spotValue getPlayerWithMoreDiscs();
	void getColorCount(int &whiteCount, int &blackCount);

    void flip(int i, int j);

private:
	Spot board[BOARDSIZE][BOARDSIZE];
};
#endif /* BOARD_H_ */
