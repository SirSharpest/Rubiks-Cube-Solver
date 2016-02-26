//
// Created by nathan on 11/02/16.
//

#include <iostream>
#include "../headers/solver.hpp"


solver::solver() {

}

void solver::AStarIDS(rCube *cubeToSolve, int depth) {


    visited.push_back(*cubeToSolve);

    //The aim is to take a cube, create a list of all possible moves at this level
    //Use A* to evaluate those moves and then take the next best likely course of action.

    // f(n) = h(n) + g(n)
    // f being the value to evaluate, h being the heuristic value and g being the distance currently traveled. (moves made)


    std::cout << depth << std::endl;

    if(cubeToSolve->isComplete()){
        std::cout << "It completed \n";
        cubeToSolve->printCube();
        return;
    }



    getCurrentStates(*cubeToSolve);

    rCube tmp = frontier.top();
    frontier.pop();
    AStarIDS(&tmp, depth+1);




}

void solver::getCurrentStates(rCube &currentState) {


    //There are 12 states
    //Apply the 12 states to each of the possible moves
    for (int i = 0; i < 12; ++i) {

        rCube tmpCube(currentState, 0);
        tmpCube.makeMove((moves) i);

        tmpCube.setF(cubesOutOfPlace(tmpCube));
        frontier.push(tmpCube);

    }

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
