/*
 * Location.h
 *
 *  Created on: Nov 16, 2018
 *      Author: cs306438375
 */

#ifndef REMOTESYSTEMSTEMPFILES_LOCATION_H_
#define REMOTESYSTEMSTEMPFILES_LOCATION_H_

class Location {
public:
    Location(int i, int j);
    int getI() const;
    void setI(int i);
    int getJ() const;
    void setJ(int j);
private:
    int i,j;
};

#endif /* REMOTESYSTEMSTEMPFILES_LOCATION_H_ */
