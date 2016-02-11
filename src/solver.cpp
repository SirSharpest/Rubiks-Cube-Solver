//
// Created by nathan on 11/02/16.
//

#include "../headers/solver.h"


solver::solver() {

}

void solver::AStarIDS(rCube *cubeToSolve) {


    //The aim is to take a cube, create a list of all possible moves at this level
    //Use A* to evaluate those moves and then take the next best likely course of action.

    // f(n) = h(n) + g(n)
    // f being the value to evaluate, h being the heuristic value and g being the distance currently traveled. (moves made)

    rCube currentState = *cubeToSolve;

    //While the cube is not complete then looplooploop
    while(!currentState.isComplete()){



        rCube possibleMoves[12] = {currentState};

        //There are 12 states
        //Apply the 12 states to each of the possible moves
        for (int i = 0; i < 12; ++i) {

            possibleMoves[i].makeMove((moves) i);

        }

        //We now how an array of all possible board states from the current state.




    }




}