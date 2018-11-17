/*
 * Manager.cpp
 *
 *  Created on: Nov 16, 2018
 *      Author: cs306438375
 */

#include "Manager.h"
#include "Rules.h"
#include <iostream>
using namespace std;

Manager::Manager()  {
    players[0].setColor(Spot::BLACK);
    players[1].setColor(Spot::WHITE);
    board.set(3,3,Spot::WHITE);
    board.set(3,4,Spot::BLACK);
    board.set(4,3,Spot::BLACK);
    board.set(4,4,Spot::WHITE);
    currentPlayer = 0;
}

Manager::~Manager() { }

void Manager::startGame() {
    bool passFlag = false;
    while (true) {
        board.printBoard();
        cout << players[currentPlayer].toChar() << ":" << endl;
        string playerMove = players[currentPlayer].getMove(board);
        if (playerMove == "QUIT"){
            cout << players[currentPlayer].toChar() << ": QUIT" << endl;
            printWinningStatement(players[currentPlayer].getOtherColor());
            break;
        }
        if (playerMove == "PASS"){
            if (passFlag){
                printWinningStatement(board.getPlayerWithMoreDiscs());
                break;
            }
            passFlag = true;
            cout << "PASS" << endl;
            currentPlayer = (currentPlayer+1)%2;
            continue;
        }
        board.set(playerMove[1]-'1',playerMove[0]-'A', players[currentPlayer].getColor());
        Rules::flip(board,Location(playerMove[1]-'1', playerMove[0]-'A'),players[currentPlayer]);
        passFlag = false;
        currentPlayer = (currentPlayer+1)%2;
        if (Rules::boardFull(board)){
            printWinningStatement(board.getPlayerWithMoreDiscs());
            break;
        }
    }
}

void Manager::printWinningStatement(Spot::spotValue color) {
    cout << (color == Spot::BLACK ? "B" : "W") << " wins the game." << endl;
}

