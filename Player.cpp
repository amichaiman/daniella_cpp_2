/*
 * Player.cpp
 *
 *  Created on: Nov 16, 2018
 *      Author: cs306438375
 */

#include "Player.h"
#include <iostream>
#include <limits>
#include "Rules.h"

Player::Player() { }

Player::~Player() { }

Player::Player(Spot::spotValue color) : color(color){ }

void Player::setColor(Spot::spotValue color) {
    Player::color = color;
}

string Player::getMove(Board &board) {
    string input;
    cin >> input;

    /* clear cin stream */
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (!Rules::isValidInput(input,board,this)){
        cout << "Invalid move; the game awaits a valid move." << endl;
        cin >> input;
    }

    return input;
}

Spot::spotValue Player::getOtherColor() {
    return color == Spot::BLACK ? Spot::WHITE : Spot::BLACK;
}

Spot::spotValue Player::getColor() const {
    return color;
}

char Player::toChar() {
    return color == Spot::BLACK ? 'B' : 'W';
}


