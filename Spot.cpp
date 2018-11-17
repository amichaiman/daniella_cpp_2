//
// Created by amichai on 17/11/18.
//

#include "Spot.h"
#include <iostream>
using namespace std;

Spot::spotValue Spot::getValue() const {
    return value;
}

void Spot::setValue(Spot::spotValue value) {
    Spot::value = value;
}
void Spot::print() {
    cout << (value == EMPTY ? "O" : value == BLACK ? "B" : "W");
}

Spot::Spot() {
    value = EMPTY;
}

void Spot::flip() {
    value = (value == BLACK ? WHITE : BLACK);
}
