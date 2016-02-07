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

    /*
     *Prints out a cube in a semi-human readable format
     */
    void printCube();


    /*
     * This function will perform a complete rotation,
     * it takes 9 parameters, 1 to stat which row
     * 4 dictate which face to move
     * and 4 corresponding destinations
     */
    void rotateHorizontalRows(int row, int faceOld1, int faceNew1,
                    int faceOld2, int faceNew2,
                    int faceOld3, int faceNew3,
                    int faceOld4, int faceNew4);

    /*
     * This function makes the move on the cube dependant on the direction given
     */
    void makeMove(moves direction);


private:




};


#endif //RUBKIS_RCUBE_H
