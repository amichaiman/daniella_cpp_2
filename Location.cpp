/*
 * Location.cpp
 *
 *  Created on: Nov 16, 2018
 *      Author: cs306438375
 */

#include "Location.h"

int Location::getI() const {
    return i;
}

void Location::setI(int i) {
    Location::i = i;
}

int Location::getJ() const {
    return j;
}

void Location::setJ(int j) {
    Location::j = j;
}

Location::Location(int i, int j) : i(i), j(j) {}
