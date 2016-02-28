//
// Created by nathan on 05/02/16.
//

#include <iostream>
#include "../headers/rCube.hpp"

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
 * 0 = white = front face (ALWAYS All relative to this state)
 * 1 = red = top face
 * 2 = green = east face
 * 3 = blue = west face
 * 4 = orange = bottom face
 * 5 = yellow = back face
 *
 */


rCube::rCube():
        f(1)
{


    this->initCompletedCube();

}

rCube::rCube(int f) {

    this->f = f;

}


rCube::rCube(const rCube &toCpy, int f){


    this->f = f;

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



void rCube::initCompletedCube() {

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

void rCube::printCube() {

    std::cout << "  --- \t\t\t   ---" << std::endl;


    //for each face
    for(int i = 0; i < 3; i++ ){

        //for each column
        for(int j = 0; j < 3; j++){



            std::cout << "| ";

            std::cout << cube[i][0][j];
            std::cout << cube[i][1][j];
            std::cout << cube[i][2][j];

            std::cout << " | ";


            std::cout <<  i;
            std::cout << "\t\t";
            std::cout << i+3;

            std::cout << "| ";

            std::cout << cube[i+3][0][j];
            std::cout << cube[i+3][1][j];
            std::cout << cube[i+3][2][j];

            std::cout << " |"

            << std::endl;

        }

        //Break up the faces when printing
        std::cout << "  --- \t\t\t   ---" << std::endl;

    }

}

void rCube::makeMove(moves direction) {


    switch (direction){

        //Rotate the white face top row to the east (right)
        case TOP_CLOCKWISE:
            performTopMove(true);
            break;
        //Rotate the white face
        case TOP_ANTICLOCKWISE:
            performTopMove(false);
            break;
        case RIGHT_CLOCKWISE:
            performRightMove(true);
            break;
        case RIGHT_ANTICLOCKWISE:
            performRightMove(false);
            break;
        case BOTTOM_CLOCKWISE:
            performBottomMove(true);
            break;
        case BOTTOM_ANTICLOCKWISE:
            performBottomMove(false);
            break;
        case LEFT_CLOCKWISE:
            performLeftMove(true);
            break;
        case LEFT_ANTICLOCKWISE:
            performLeftMove(false);
            break;
        case FRONT_CLOCKWISE:
            performFrontMove(true);
            break;
        case FRONT_ANTICLOCKWISE:
            performFrontMove(false);
            break;
        case BACK_CLOCKWISE:
            performBackMove(true);
            break;
        case BACK_ANTICLOCKWISE:
            performBackMove(false);
            break;
        default:
            std::cout << "Error that is not a valid movement" << std::endl;
            return;
        }

}

bool rCube::isComplete() {
    return evaluateCube();
}


void rCube::rotateOnPivotPoint(int faceToRotate, bool isClockwise) {

    //tmp cube to hold original values
    rCube tmpCube(*this);

    //if we are moving in the clockwise direction
    if(isClockwise){

        //TODO: Calculate new positions when movement is complete

        //Top Row goes:
            //0,0 -> 2,0
            //1,0 -> 2,1
            //2,0 -> 2,2

        cube[faceToRotate][2][0] = tmpCube.cube[faceToRotate][0][0];
        cube[faceToRotate][2][1] = tmpCube.cube[faceToRotate][1][0];
        cube[faceToRotate][2][2] = tmpCube.cube[faceToRotate][2][0];


        //Middle row goes:
            //0,1 -> 1,0
            //1,1 -> 1,1
            //2,1 -> 1,2

        cube[faceToRotate][1][0] = tmpCube.cube[faceToRotate][0][1];
        cube[faceToRotate][1][1] = tmpCube.cube[faceToRotate][1][1];
        cube[faceToRotate][1][2] = tmpCube.cube[faceToRotate][2][1];


        //Bottom row goes:
            //0,2 -> 0,0
            //1,2 -> 0,1
            //2,2 -> 0,2

        cube[faceToRotate][0][0] = tmpCube.cube[faceToRotate][0][2];
        cube[faceToRotate][0][1] = tmpCube.cube[faceToRotate][1][2];
        cube[faceToRotate][0][2] = tmpCube.cube[faceToRotate][2][2];


    }else{

        //Top Row goes:
            //0,0 -> 0,2
            //1,0 -> 0,1
            //2,0 -> 0,0
        cube[faceToRotate][0][2] = tmpCube.cube[faceToRotate][0][0];
        cube[faceToRotate][0][1] = tmpCube.cube[faceToRotate][1][0];
        cube[faceToRotate][0][0] = tmpCube.cube[faceToRotate][2][0];


        //Middle row goes:
            //0,1 -> 1,2
            //1,1 -> 1,1
            //2,1 -> 1,0
        cube[faceToRotate][1][2] = tmpCube.cube[faceToRotate][0][1];
        cube[faceToRotate][2][1] = tmpCube.cube[faceToRotate][1][1];
        cube[faceToRotate][1][0] = tmpCube.cube[faceToRotate][2][1];


        //Bottom Row goes to:
            //0,2 -> 2,2
            //1,2 -> 2,1
            //2,2 -> 2,0
        cube[faceToRotate][2][0] = tmpCube.cube[faceToRotate][0][2];
        cube[faceToRotate][2][1] = tmpCube.cube[faceToRotate][1][2];
        cube[faceToRotate][2][0] = tmpCube.cube[faceToRotate][2][2];


    }

}

bool rCube::evaluateCube(){

    //Check each face
    for(int i = 0; i < 6; i++){

        //Check each row and column
        for(int j = 0; j < 3; j++){

            for(int k = 0; k < 3; k++){

                if(cube[i][j][k] == (Color) i){
                    continue;
                }else{
                    return false;
                }
            }

        }

    }
    return true;
}


int rCube::getF() {
    return this->f;
}

void rCube::setF(int newF) {

    this->f = newF;
}

bool rCube::compare(rCube cube) {

    for(int i = 0; i < 6; i++){

        for( int j = 0; j < 3; j++){

            for (int k = 0; k < 3; k++){

                if(this->cube[i][j][k] == cube.cube[i][j][k]){
                    continue;
                }else{
                    return false;
                }


            }

        }

    }


    return true;

}


void rCube::setCustomCube() {


    //face 1
    cube[0][0][0] = orange;
    cube[0][0][1] = orange;
    cube[0][0][2] = green;

    cube[0][1][0] = green;
    cube[0][1][1] = white;
    cube[0][1][2] = yellow;

    cube[0][2][0] = green;
    cube[0][2][1] = white;
    cube[0][0][2] = orange;

    //face 2
    cube[1][0][0] = yellow;
    cube[1][0][1] = white;
    cube[1][0][2] = blue;

    cube[1][1][0] = yellow;
    cube[1][1][1] = red;
    cube[1][1][2] = red;

    cube[1][2][0] = yellow;
    cube[1][2][1] = green;
    cube[1][0][2] = red;

    //face 3
    cube[2][0][0] = yellow;
    cube[2][0][1] = red;
    cube[2][0][2] = blue;

    cube[2][1][0] = yellow;
    cube[2][1][1] = green;
    cube[2][1][2] = yellow;

    cube[2][2][0] = blue;
    cube[2][2][1] = orange;
    cube[2][0][2] = orange;

    //face 4
    cube[3][0][0] = orange;
    cube[3][0][1] = red;
    cube[3][0][2] = blue;

    cube[3][1][0] = blue;
    cube[3][1][1] = blue;
    cube[3][1][2] = green;

    cube[3][2][0] = yellow;
    cube[3][2][1] = blue;
    cube[3][0][2] = red;

    //face 5
    cube[4][0][0] = white;
    cube[4][0][1] = white;
    cube[4][0][2] = red;

    cube[4][1][0] = blue;
    cube[4][1][1] = orange;
    cube[4][1][2] = orange;

    cube[4][2][0] = white;
    cube[4][2][1] = orange;
    cube[4][0][2] = green;


    //face 6
    cube[5][0][0] = red;
    cube[5][0][1] = green;
    cube[5][0][2] = white;

    cube[5][1][0] = red;
    cube[5][1][1] = yellow;
    cube[5][1][2] = white;

    cube[5][2][0] = green;
    cube[5][2][1] = blue;
    cube[5][0][2] = white;




}


/*
 * Refactoring section
 */
void rCube::performTopMove(bool isClockwise) {

    //tmp cube to hold original values
    rCube tmpCube(*this);

    if(isClockwise){
        //do first swap
        //moves face 0 into the position of face 2
        cube[2][0][0] = tmpCube.cube[0][0][0];
        cube[2][1][0] = tmpCube.cube[0][1][0];
        cube[2][2][0] = tmpCube.cube[0][2][0];


        //do second swap
        //moves face 2 into face 5
        cube[5][0][0] = tmpCube.cube[2][0][0];
        cube[5][1][0] = tmpCube.cube[2][1][0];
        cube[5][2][0] = tmpCube.cube[2][2][0];


        //do third swap
        //moves face 5 into face 3
        cube[3][0][0] = tmpCube.cube[5][0][0];
        cube[3][1][0] = tmpCube.cube[5][1][0];
        cube[3][2][0] = tmpCube.cube[5][2][0];


        //do fourth swap
        //moves face 3 into face 0
        cube[0][0][0] = tmpCube.cube[3][0][0];
        cube[0][1][0] = tmpCube.cube[3][1][0];
        cube[0][2][0] = tmpCube.cube[3][2][0];
    }else{

        //do first swap
        //moves face 0 into the position of face 3
        cube[3][0][0] = tmpCube.cube[0][0][0];
        cube[3][1][0] = tmpCube.cube[0][1][0];
        cube[3][2][0] = tmpCube.cube[0][2][0];


        //do second swap
        //moves face 3 into face 5
        cube[5][0][0] = tmpCube.cube[3][0][0];
        cube[5][1][0] = tmpCube.cube[3][1][0];
        cube[5][2][0] = tmpCube.cube[3][2][0];


        //do third swap
        //moves face 5 into face 2
        cube[2][0][0] = tmpCube.cube[5][0][0];
        cube[2][1][0] = tmpCube.cube[5][1][0];
        cube[2][2][0] = tmpCube.cube[5][2][0];


        //do fourth swap
        //moves face 2 into face 0
        cube[0][0][0] = tmpCube.cube[2][0][0];
        cube[0][1][0] = tmpCube.cube[2][1][0];
        cube[0][2][0] = tmpCube.cube[2][2][0];



    }



    //Rotate top face (1)
    rotateOnPivotPoint(1, isClockwise);


}

void rCube::performRightMove(bool isClockwise) {

    //tmp cube to hold original values
    rCube tmpCube(*this);

    if (isClockwise) {
        //do first swap
        //moves face 0 into the position of face 1
        cube[1][2][0] = tmpCube.cube[0][2][0];
        cube[1][2][1] = tmpCube.cube[0][2][1];
        cube[1][2][2] = tmpCube.cube[0][2][2];


        //do second swap
        //moves face 1 into face 5
        cube[5][2][0] = tmpCube.cube[1][2][0];
        cube[5][2][1] = tmpCube.cube[1][2][1];
        cube[5][2][2] = tmpCube.cube[1][2][2];


        //do third swap
        //moves face 5 into face 4
        cube[4][2][0] = tmpCube.cube[5][2][0];
        cube[4][2][1] = tmpCube.cube[5][2][1];
        cube[4][2][2] = tmpCube.cube[5][2][2];


        //do fourth swap
        //moves face 4 into face 0
        cube[0][2][0] = tmpCube.cube[4][2][0];
        cube[0][2][1] = tmpCube.cube[4][2][1];
        cube[0][2][2] = tmpCube.cube[4][2][2];
    } else {

        //do first swap
        //moves face 0 into the position of face 4
        cube[4][2][0] = tmpCube.cube[0][2][0];
        cube[4][2][1] = tmpCube.cube[0][2][1];
        cube[4][2][2] = tmpCube.cube[0][2][2];


        //do second swap
        //moves face 4 into face 5
        cube[5][2][0] = tmpCube.cube[4][2][0];
        cube[5][2][1] = tmpCube.cube[4][2][1];
        cube[5][2][2] = tmpCube.cube[4][2][2];


        //do third swap
        //moves face 5 into face 1
        cube[1][2][0] = tmpCube.cube[5][2][0];
        cube[1][2][1] = tmpCube.cube[5][2][1];
        cube[1][2][2] = tmpCube.cube[5][2][2];


        //do fourth swap
        //moves face 1 into face 0
        cube[0][2][0] = tmpCube.cube[1][2][0];
        cube[0][2][1] = tmpCube.cube[1][2][1];
        cube[0][2][2] = tmpCube.cube[1][2][2];


    }

    rotateOnPivotPoint(2, isClockwise);

}

void rCube::performBottomMove(bool isClockwise) {

    //tmp cube to hold original values
    rCube tmpCube(*this);

    if(isClockwise){
        //do first swap
        //moves face 0 into the position of face 2
        cube[2][0][2] = tmpCube.cube[0][0][2];
        cube[2][1][2] = tmpCube.cube[0][1][2];
        cube[2][2][2] = tmpCube.cube[0][2][2];


        //do second swap
        //moves face 2 into face 5
        cube[5][0][2] = tmpCube.cube[2][0][2];
        cube[5][1][2] = tmpCube.cube[2][1][2];
        cube[5][2][2] = tmpCube.cube[2][2][2];


        //do third swap
        //moves face 5 into face 3
        cube[3][0][2] = tmpCube.cube[5][0][2];
        cube[3][1][2] = tmpCube.cube[5][1][2];
        cube[3][2][2] = tmpCube.cube[5][2][2];


        //do fourth swap
        //moves face 3 into face 0
        cube[0][0][2] = tmpCube.cube[3][0][2];
        cube[0][1][2] = tmpCube.cube[3][1][2];
        cube[0][2][2] = tmpCube.cube[3][2][2];
    }else{

        //do first swap
        //moves face 0 into the position of face 3
        cube[3][0][2] = tmpCube.cube[0][0][2];
        cube[3][1][2] = tmpCube.cube[0][1][2];
        cube[3][2][2] = tmpCube.cube[0][2][2];


        //do second swap
        //moves face 3 into face 5
        cube[5][0][2] = tmpCube.cube[3][0][2];
        cube[5][1][2] = tmpCube.cube[3][1][2];
        cube[5][2][2] = tmpCube.cube[3][2][2];


        //do third swap
        //moves face 5 into face 2
        cube[2][0][2] = tmpCube.cube[5][0][2];
        cube[2][1][2] = tmpCube.cube[5][1][2];
        cube[2][2][2] = tmpCube.cube[5][2][2];


        //do fourth swap
        //moves face 2 into face 0
        cube[0][0][2] = tmpCube.cube[2][0][2];
        cube[0][1][2] = tmpCube.cube[2][1][2];
        cube[0][2][2] = tmpCube.cube[2][2][2];

    }

    rotateOnPivotPoint(4, isClockwise);

}

void rCube::performLeftMove(bool isClockwise) {

    //tmp cube to hold original values
    rCube tmpCube(*this);

    if (isClockwise) {
        //do first swap
        //moves face 0 into the position of face 1
        cube[1][0][0] = tmpCube.cube[0][0][0];
        cube[1][0][1] = tmpCube.cube[0][0][1];
        cube[1][0][2] = tmpCube.cube[0][0][2];


        //do second swap
        //moves face 1 into face 5
        cube[5][0][0] = tmpCube.cube[1][0][0];
        cube[5][0][1] = tmpCube.cube[1][0][1];
        cube[5][0][2] = tmpCube.cube[1][0][2];


        //do third swap
        //moves face 5 into face 4
        cube[4][0][0] = tmpCube.cube[5][0][0];
        cube[4][0][1] = tmpCube.cube[5][0][1];
        cube[4][0][2] = tmpCube.cube[5][0][2];


        //do fourth swap
        //moves face 4 into face 0
        cube[0][0][0] = tmpCube.cube[4][0][0];
        cube[0][0][1] = tmpCube.cube[4][0][1];
        cube[0][0][2] = tmpCube.cube[4][0][2];
    } else {

        //do first swap
        //moves face 0 into the position of face 4
        cube[4][0][0] = tmpCube.cube[0][0][0];
        cube[4][0][1] = tmpCube.cube[0][0][1];
        cube[4][0][2] = tmpCube.cube[0][0][2];


        //do second swap
        //moves face 4 into face 5
        cube[5][0][0] = tmpCube.cube[4][0][0];
        cube[5][0][1] = tmpCube.cube[4][0][1];
        cube[5][0][2] = tmpCube.cube[4][0][2];


        //do third swap
        //moves face 5 into face 1
        cube[1][0][0] = tmpCube.cube[5][0][0];
        cube[1][0][1] = tmpCube.cube[5][0][1];
        cube[1][0][2] = tmpCube.cube[5][0][2];


        //do fourth swap
        //moves face 1 into face 0
        cube[0][0][0] = tmpCube.cube[1][0][0];
        cube[0][0][1] = tmpCube.cube[1][0][1];
        cube[0][0][2] = tmpCube.cube[1][0][2];


    }

    rotateOnPivotPoint(3, isClockwise);

}

void rCube::performBackMove(bool isClockwise) {


    //tmp cube to hold original values
    rCube tmpCube(*this);

    if(isClockwise){
        //do first swap
        //moves face 1 into the position of face 2
        cube[2][0][0] = tmpCube.cube[1][0][0];
        cube[2][1][0] = tmpCube.cube[1][1][0];
        cube[2][2][0] = tmpCube.cube[1][2][0];


        //do second swap
        //moves face 2 into face 4
        cube[4][0][0] = tmpCube.cube[2][0][0];
        cube[4][1][0] = tmpCube.cube[2][1][0];
        cube[4][2][0] = tmpCube.cube[2][2][0];


        //do third swap
        //moves face 4 into face 3
        cube[3][0][0] = tmpCube.cube[4][0][0];
        cube[3][1][0] = tmpCube.cube[4][1][0];
        cube[3][2][0] = tmpCube.cube[4][2][0];


        //do fourth swap
        //moves face 3 into face 1
        cube[1][0][0] = tmpCube.cube[3][0][0];
        cube[1][1][0] = tmpCube.cube[3][1][0];
        cube[1][2][0] = tmpCube.cube[3][2][0];
    }else{

        //do first swap
        //moves face 1 into the position of face 3
        cube[3][0][0] = tmpCube.cube[1][0][0];
        cube[3][1][0] = tmpCube.cube[1][1][0];
        cube[3][2][0] = tmpCube.cube[1][2][0];


        //do second swap
        //moves face 3 into face 4
        cube[4][0][0] = tmpCube.cube[3][0][0];
        cube[4][1][0] = tmpCube.cube[3][1][0];
        cube[4][2][0] = tmpCube.cube[3][2][0];


        //do third swap
        //moves face 4 into face 2
        cube[2][0][0] = tmpCube.cube[4][0][0];
        cube[2][1][0] = tmpCube.cube[4][1][0];
        cube[2][2][0] = tmpCube.cube[4][2][0];


        //do fourth swap
        //moves face 2 into face 1
        cube[1][0][0] = tmpCube.cube[2][0][0];
        cube[1][1][0] = tmpCube.cube[2][1][0];
        cube[1][2][0] = tmpCube.cube[2][2][0];

    }

    rotateOnPivotPoint(5, isClockwise);
}

void rCube::performFrontMove(bool isClockwise) {


    //tmp cube to hold original values
    rCube tmpCube(*this);

    if(isClockwise){
        //do first swap
        //moves face 1 into the position of face 2
        cube[2][0][2] = tmpCube.cube[1][0][2];
        cube[2][1][2] = tmpCube.cube[1][1][2];
        cube[2][2][2] = tmpCube.cube[1][2][2];


        //do second swap
        //moves face 2 into face 4
        cube[4][0][2] = tmpCube.cube[2][0][2];
        cube[4][1][2] = tmpCube.cube[2][1][2];
        cube[4][2][2] = tmpCube.cube[2][2][2];


        //do third swap
        //moves face 4 into face 3
        cube[3][0][2] = tmpCube.cube[4][0][2];
        cube[3][1][2] = tmpCube.cube[4][1][2];
        cube[3][2][2] = tmpCube.cube[4][2][2];


        //do fourth swap
        //moves face 3 into face 1
        cube[1][0][2] = tmpCube.cube[3][0][2];
        cube[1][1][2] = tmpCube.cube[3][1][2];
        cube[1][2][2] = tmpCube.cube[3][2][2];
    }else{

        //do first swap
        //moves face 1 into the position of face 3
        cube[3][0][2] = tmpCube.cube[1][0][2];
        cube[3][1][2] = tmpCube.cube[1][1][2];
        cube[3][2][2] = tmpCube.cube[1][2][2];


        //do second swap
        //moves face 3 into face 4
        cube[4][0][2] = tmpCube.cube[3][0][2];
        cube[4][1][2] = tmpCube.cube[3][1][2];
        cube[4][2][2] = tmpCube.cube[3][2][2];


        //do third swap
        //moves face 4 into face 2
        cube[2][0][2] = tmpCube.cube[4][0][2];
        cube[2][1][2] = tmpCube.cube[4][1][2];
        cube[2][2][2] = tmpCube.cube[4][2][2];


        //do fourth swap
        //moves face 2 into face 1
        cube[1][0][2] = tmpCube.cube[2][0][2];
        cube[1][1][2] = tmpCube.cube[2][1][2];
        cube[1][2][2] = tmpCube.cube[2][2][2];

    }

    rotateOnPivotPoint(0, isClockwise);


}
