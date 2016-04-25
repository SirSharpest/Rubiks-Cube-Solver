//
// Created by nathan on 11/02/16.
//

#include <iostream>
#include "../headers/solver.hpp"


solver::solver() {

}


std::vector<rCube> solver::getCurrentStates(rCube &currentState) {


    //There are 12 states
    std::vector<rCube> tmpCubes;
    //Apply the 12 states to each of the possible moves
    for (int i = 0; i < 12; ++i) {
        rCube tmp = currentState;
        tmp.makeMove((moves) i);
        tmp.setF(cubesOutOfPlace(tmp));
        tmpCubes.push_back(tmp);
    }
    return tmpCubes;
}


int solver::cubesOutOfPlace(rCube &cube) {

    int numOOP = 0;

    for(int i = 0; i < 6; i++){

        for(int j = 0; j <  3; j++){

            for(int k = 0; k < 3; k++){

                if(cube.cube[i][j][k] == (Color) i){
                    continue;
                }else{
                    numOOP++;
                }

            }

        }

    }


    return numOOP;
}

void solver::randomSolver(rCube &cube) {

    rCube tmpCube = cube;

    int move;

    for(int i = 0; i <= 18; i++){

        if(tmpCube.isComplete()){
            std::cout << "I did it! \n";
            tmpCube.printCube();
            return;
        }

        move = (rand() % 12 + 0);

        tmpCube.makeMove((moves) move );

        std::cout << move << " ";


    }
    std::cout << std::endl;

    if(!tmpCube.isComplete())
        randomSolver(cube);
    else{

        int x;
        std::cin >> x;

    }

}


void solver::multiStageSolver(rCube &cube) {


    //step 1 find white cross



    //step 2 find white corners

    //step 3 solve second layer

    //step 4 find yellow cross

    //step 5 position yellow edges

    //step 6 yellow corners positioned

    //step 7 orientate yellow corners



}

std::vector<moves> solver::whiteCross(rCube &cube) {

    //Breadth first search if you please
    //The move sequence that we find first will be used

    std::vector<moves> movesToMake;



    return movesToMake;
}





