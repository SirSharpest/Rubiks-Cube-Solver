//
// Created by nathan on 05/02/16.
//

#include <iostream>
#include "../headers/rcube.h"



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
    this->printCube();

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

        for(int j = 0; j < 3; j++){

            std::cout << cube[i][j][0] << std::endl;
            std::cout << cube[i][j][1] << std::endl;
            std::cout << cube[i][j][2] << std::endl;

        }



    }


}

void rcube::makeMove(moves direction) {


    switch (direction){

        case TOP_CLOCKWISE:

            //For this the top row will want to shuffle to the right


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
        }






}
