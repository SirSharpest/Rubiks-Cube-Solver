//
// Created by nathan on 05/02/16.
//

#include <iostream>
#include "../headers/rcube.h"

#define debug

/*
 * When referencing the cube, the front face will be 0, the back will be 3
 * The east side face will be 1, the west will be 4
 * The top side face will be 2, the bottom 5
 *
 *
 */


/* Just for reference these are the proposed faces of completion:
 *
 *
 * 0 = white
 * 1 = red
 * 2 = green
 * 3 = blue
 * 4 = orange
 * 5 = yellow
 *
 */


rcube::rcube() {


    this->initCompletedCube();

    #ifdef debug
        this->printCube();
    #endif
}

rcube::rcube(const rcube &toCpy) {

    //For each face
    for(int i = 0; i < 6; i++){

        //for each row
        for(int j = 0; j < 3; j++){

            for(int k = 0; k < 3; k++){

                this->cube[i][j][k] = toCpy.cube[i][j][k];

            }

        }

    }

}



void rcube::initCompletedCube() {

    //for each face:
    for(int i = 0; i < 6; i++){


        Color tmpColor;

        switch (i){
            case 0:
                tmpColor = white;
                break;
            case 1:
                tmpColor = red;
                break;
            case 2:
                tmpColor = green;
                break;
            case 3:
                tmpColor = blue;
                break;
            case 4:
                tmpColor = orange;
                break;
            case 5:
                tmpColor = yellow;
                break;
            default:
                std::cout << "Couldn't assign a color" << std::endl;
                return;
         }

        //for each row of that face:
        for(int j = 0; j < 3; j++){


            cube[i][j][0] = tmpColor;
            cube[i][j][1] = tmpColor;
            cube[i][j][2] = tmpColor;

        }

    }

}

void rcube::printCube() {


    //for each face
    for(int i = 0; i < 6; i++ ){

        //for each row
        for(int j = 0; j < 3; j++){

            std::cout << cube[i][j][0];
            std::cout << cube[i][j][1];
            std::cout << cube[i][j][2] << std::endl;

        }

        //Break up the faces when printing
        std::cout << "---" << std::endl;

    }

}

void rcube::makeMove(moves direction) {


    switch (direction){

        case TOP_CLOCKWISE:

            //For this the top row will want to shuffle to the right

                //Moving face 0(front), 1(east), 3(back) ,4(west)
                //[0][0][x] -> [1][0][x]
                //[1][0][x] -> [3][0][x]
                //[3][0][x] -> [4][0][x]
                //[4][0][x] -> [0][0][x]



            //The top face will pivot on the center point


            break;
        case TOP_ANTICLOCKWISE:
            break;
        case RIGHT_CLOCKWISE:
            break;
        case RIGHT_ANTICLOCKWISE:
            break;
        case BOTTOM_CLOCKWISE:
            break;
        case BOTTOM_ANTICLOCKWISE:
            break;
        case LEFT_CLOCKWISE:
            break;
        case LEFT_ANTICLOCKWISE:
            break;
        default:
            std::cout << "Error that is not a valid movement" << std::endl;
            return;
        }

}

void rcube::rotateHorizontalRows(int row, int faceOld1, int faceNew1, int faceOld2, int faceNew2, int faceOld3,
                                 int faceNew3, int faceOld4, int faceNew4) {


    //tmp cube to hold original values
    rcube tmpCube(*this);

    //do first swap
    cube[faceNew1][row][0] = tmpCube.cube[faceOld1][row][0];
    cube[faceNew1][row][1] = tmpCube.cube[faceOld1][row][1];
    cube[faceNew1][row][2] = tmpCube.cube[faceOld1][row][2];


    //do second swap
    cube[faceNew2][row][0] = tmpCube.cube[faceOld2][row][0];
    cube[faceNew2][row][1] = tmpCube.cube[faceOld2][row][1];
    cube[faceNew2][row][2] = tmpCube.cube[faceOld2][row][2];


    //do third swap
    cube[faceNew3][row][0] = tmpCube.cube[faceOld3][row][0];
    cube[faceNew3][row][1] = tmpCube.cube[faceOld3][row][1];
    cube[faceNew3][row][2] = tmpCube.cube[faceOld3][row][2];


    //do fourth swap
    cube[faceNew4][row][0] = tmpCube.cube[faceOld4][row][0];
    cube[faceNew4][row][1] = tmpCube.cube[faceOld4][row][1];
    cube[faceNew4][row][2] = tmpCube.cube[faceOld4][row][2];

}


void rcube::rotateOnPivotPoint(int faceToRotate, bool isClockwise) {

    //tmp cube to hold original values
    rcube tmpCube(*this);

    //if we are moving in the clockwise direction
    if(isClockwise){

        //TODO: Calculate new positions when movement is complete


    }else{

        //TODO: Calculate new positions when movement is complete


    }

}
