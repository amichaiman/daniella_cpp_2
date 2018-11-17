/*
 * Rules.cpp
 *
 *  Created on: Nov 16, 2018
 *      Author: cs306438375
 */

#include "Rules.h"
#include "Location.h"
#include <string>
#include <iostream>
using namespace std;

Rules::Rules() { }

Rules::~Rules() { }

bool Rules::boardFull(Board &board) {
    int whiteCount = 0;
    int blackCount = 0;
    board.getColorCount(whiteCount, blackCount);
    return (whiteCount+blackCount) == (Board::BOARDSIZE*Board::BOARDSIZE);
}

bool Rules::isValidInput(string input, Board &board, Player *player) {
    if (cin.fail()){
        return false;
    }
    if (input == "QUIT" || input == "PASS"){
        return true;
    }
    if (input.length() != 2){
        return false;
    }
    if (!isInBoard(input[0]-'A') || !isInBoard(input[1]-'1')){
        return false;
    }
    if (!isValidSpot(Location(input[1]-'1',input[0]-'A'), board, player)){
        return false;
    }
    return true;
}

bool Rules::isInBoard(int n) {
    return n>=0 && n < Board::BOARDSIZE;
}

bool Rules::isValidSpot(Location location, Board &board, Player *player) {
    int directionI[] = {-1,-1,-1,0,0,1,1,1};
    int directionJ[] = {-1,0,1,-1,1,-1,0,1};
    const int NUMBER_OF_DIRECTIONS = 8;
    for (int k=0; k<NUMBER_OF_DIRECTIONS; k++){
        if (isValidDirection(board, location, directionI[k], directionJ[k], player)){
            return true;
        }
    }
    return false;
}

bool Rules::isValidDirection(Board &board, Location location, int directionI, int directionJ, Player *player) {
    moveInDirection(location, directionI, directionJ);
    if (board.get(location.getI(), location.getJ()) != player->getOtherColor()){
        return false;
    }
    moveInDirection(location, directionI, directionJ);
    while (isInBoard(location.getI() && isInBoard(location.getJ()))){
        if (board.get(location.getI(), location.getJ()) == player->getColor()){
            return true;
        }
        if (board.get(location.getI(), location.getJ()) != player->getOtherColor()){
            return false;
        }
        moveInDirection(location, directionI, directionJ);
    }
    return false;
}

void Rules::moveInDirection(Location &location, int directionI, int directionJ) {
    location.setI(location.getI()+directionI);
    location.setJ(location.getJ()+directionJ);
}

void Rules::flip(Board &board, Location location, Player &player) {
    int directionI[] = {-1,-1,-1,0,0,1,1,1};
    int directionJ[] = {-1,0,1,-1,1,-1,0,1};
    const int NUMBER_OF_DIRECTIONS = 8;

    for (int k=0; k<NUMBER_OF_DIRECTIONS; k++){
        if (isValidDirection(board, location, directionI[k], directionJ[k], &player)){
            flipDirection(board,location, directionI[k], directionJ[k], player);
        }
    }
}

void Rules::flipDirection(Board &board, Location location, int directionI, int directionJ, Player &player) {
    moveInDirection(location,directionI,directionJ);
    while (board.get(location.getI(),location.getJ()) == player.getOtherColor()){
        board.flip(location.getI(), location.getJ());
    }
}

