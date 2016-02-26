//
// Created by nathan on 11/02/16.
//

#include <iostream>
#include "../headers/solver.hpp"


solver::solver() {

}

void solver::AStarIDS(rCube &cubeToSolve, int depth) {

    /*

    //we want to look at all elements at the current level and check if they are the answer
    std::vector<rCube> states= getCurrentStates(cubeToSolve);

    for(int i = 0; i < states.size(); i++ ){

        std::vector<rCube> tmp = getCurrentStates(states.front());

        for(int j = 0; j < tmp.size(); j++){

            std::vector<rCube> tmp1 = getCurrentStates(tmp.front());



        }

    }

     */

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

int solver::MH3D(int x1, int y1, int z1,
                 int x2, int y2, int z2) {


    return (x1-x2)+(y1-y2)+(z1-z2);


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

