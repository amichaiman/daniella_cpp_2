/*
 * Board.cpp
 *
 *  Created on: Nov 16, 2018
 *      Author: cs306438375
 */
#include <iostream>
#include "Board.h"
#include "Spot.h"

using namespace std;

Board::Board(){ }

void Board::printBoard(){
    for(int i=0;i<BOARDSIZE;i++){
    	for(int j=0;j<BOARDSIZE;j++) {
    	    board[i][j].print();
    	    cout << (j == BOARDSIZE-1 ? "\n" : " ");
		}
    }
}

void Board::set(int i, int j, Spot::spotValue value) {
	board[i][j].setValue(value);
}

Spot::spotValue Board::get(int i, int j) {
	return board[i][j].getValue();
}

void Board::getColorCount(int &whiteCount, int &blackCount){
	for(int i=0;i<BOARDSIZE;i++){
		for(int j=0;j<BOARDSIZE;j++) {
			if (board[i][j].getValue() == Spot::BLACK){
				blackCount++;
			} else if (board[i][j].getValue() == Spot::WHITE){
				whiteCount++;
			}
		}
	}
}
Spot::spotValue Board::getPlayerWithMoreDiscs() {
	int whiteCount = 0;
	int blackCount = 0;

	getColorCount(whiteCount, blackCount);

	return whiteCount > blackCount ? Spot::WHITE : Spot::BLACK;
}

void Board::flip(int i, int j) {
	board[i][j].flip();
}
