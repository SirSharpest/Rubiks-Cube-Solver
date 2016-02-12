//
// Created by nathan on 11/02/16.
//

#ifndef RUBKIS_SOLVER_H
#define RUBKIS_SOLVER_H

#include "rCube.h"
#include <stack>
#include <vector>


class solver {

public:

    /*
     * Constructs the object that can do solving
     * of a rubiks cube
     */
    solver();

    /*
     * This funciton uses A* IDS to find a solution
     * It takes a cube and edits it in place
     */
    void AStarIDS(rCube * cubeToSolve);

    /*
     * Gathers all possible states at current state
     * returns an array of states
     */
    void getCurrentStates(rCube &currentState, rCube *states);

private:


    std::stack <moves> frontier;




};


#endif //RUBKIS_SOLVER_H
