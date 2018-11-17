//
// Created by amichai on 17/11/18.
//

#ifndef DANIELLA_CPP_2_SPOT_H
#define DANIELLA_CPP_2_SPOT_H

class Spot {
public:
    Spot();
    typedef enum{BLACK, WHITE, EMPTY} spotValue;
    spotValue getValue() const;
    void setValue(spotValue value);
    void print();

    void flip();

private:
    spotValue value;
};


#endif //DANIELLA_CPP_2_SPOT_H
