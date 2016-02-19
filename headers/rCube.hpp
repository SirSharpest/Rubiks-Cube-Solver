//
// Created by nathan on 05/02/16.
//




#ifndef RUBKIS_RCUBE_H
#define RUBKIS_RCUBE_H

#include "color.hpp"
#include "moves.hpp"



class rCube {



public:

    Color cube[6][3][3];


    /*
     * Constructor for a rCube
     */
    rCube();

    /*
     * Copy constructor
     */
    rCube(const rCube & toCpy, int f);

    /*
     * Constructor to set the f
     */
    rCube(int f);


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


    /**
     * Evaluates the cube's state and decides if it is complete
     */
    bool isComplete();



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


    void rotateVerticalCols(int column, int faceOld1, int faceNew1,
                            int faceOld2, int faceNew2,
                            int faceOld3, int faceNew3,
                            int faceOld4, int faceNew4);



    /*
     * When a move occurs the Face perpendicular to the rotation will pivot on the center point
     * in the clockwise direction of the move
     */
    void rotateOnPivotPoint(int faceToRotate, bool isClockwise);

    /*
     * This function makes the move on the cube dependant on the direction given
     */
    void makeMove(moves direction);

    bool evaluateCube();

    //gets the value at F
    int getF();

    //sets the value at F
    void setF(int newF);


    struct compareF
    {
        bool operator()(const rCube& lhs, const rCube& rhs) const
        {
            return lhs.f > rhs.f;
        }
    };

    bool compare(rCube cube);

private:

    //This is the value to use as a comparator
    int f;






};


#endif //RUBKIS_RCUBE_H
