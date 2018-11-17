/*
 * Player.h
 *
 *  Created on: Nov 16, 2018
 *      Author: cs306438375
 */

#ifndef REMOTESYSTEMSTEMPFILES_PLAYER_H_
#define REMOTESYSTEMSTEMPFILES_PLAYER_H_

#include "Disk.h"
#include "Spot.h"
#include "Board.h"
#include <string>

using namespace std;
class Player {
public:
	Player(Spot::spotValue color);
	Player();
	virtual ~Player();
    void setColor(Spot::spotValue color);
    Spot::spotValue getOtherColor();
    string getMove(Board &board);
    char toChar();
    Spot::spotValue getColor() const;

private:
    Spot::spotValue color;
};

#endif /* REMOTESYSTEMSTEMPFILES_PLAYER_H_ */
