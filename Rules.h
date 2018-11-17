/*
 * Rules.h
 *
 *  Created on: Nov 16, 2018
 *      Author: cs306438375
 */

#ifndef REMOTESYSTEMSTEMPFILES_RULES_H_
#define REMOTESYSTEMSTEMPFILES_RULES_H_

#include "Board.h"
#include "Location.h"
#include "Player.h"
#include <string>

using namespace std;
class Rules {
public:
	Rules();
	virtual ~Rules();

	static bool boardFull(Board &board);
    static bool isInBoard(int n);
	static bool isValidInput(string input, Board &board, Player *player);
	static void moveInDirection(Location &location, int directionI, int directionJ);
	static bool isValidSpot(Location location, Board &board, Player *player);
	static bool isValidDirection(Board &board, Location location, int directionI, int directionJ, Player *player);

	static void flip(Board &board, Location location, Player &player);

	static void flipDirection(Board &board, Location location, int directionI, int directionJ, Player &player);
};

#endif /* REMOTESYSTEMSTEMPFILES_RULES_H_ */
