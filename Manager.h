/*
 * Manager.h
 *
 *  Created on: Nov 16, 2018
 *      Author: cs306438375
 */

#ifndef REMOTESYSTEMSTEMPFILES_MANAGER_H_
#define REMOTESYSTEMSTEMPFILES_MANAGER_H_


#include "Board.h"
#include "Player.h"

class Manager {
public:
	Manager();
	virtual ~Manager();

	void startGame();
private:
    static const int NUMBER_OF_PLAYERS = 2;
	Board board;
	Player players[NUMBER_OF_PLAYERS];
	int currentPlayer;
    void printWinningStatement(Spot::spotValue discs);
};

#endif /* REMOTESYSTEMSTEMPFILES_MANAGER_H_ */
