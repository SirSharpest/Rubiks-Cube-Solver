//
// Created by nathan on 05/02/16.
//




#ifndef RUBKIS_RCUBE_H
#define RUBKIS_RCUBE_H

#include "color.h"
#include "moves.h"


class rcube {

    Color cube[6][3][3];


public:

    /*
     * Constructor for a rcube
     */
    rcube();

    /*
     * This function creates a completed cube
     * It can be used to compare other cubes or it can be used
     * to evaluate goal state
     */
    void initCompletedCube();

    void printCube();



    /*
     * This function makes the move on the cube dependant on the direction given
     */
    void makeMove(moves direction);


private:




};


#endif //RUBKIS_RCUBE_H
