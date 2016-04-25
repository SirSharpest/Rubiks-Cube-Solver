//
// Created by nathan on 11/02/16.
//

#ifndef RUBKIS_SOLVER_H
#define RUBKIS_SOLVER_H

#include "rCube.hpp"
#include <stack>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>


class solver {

public:

    /*
     * Constructs the object that can do solving
     * of a rubiks cube
     */
    solver();



    /*
     * Gathers all possible states at current state
     * returns an array of states
     */
    std::vector<rCube> getCurrentStates(rCube &currentState);


    /*
     * Counts how many tiles are not in the correct place
     */
    int cubesOutOfPlace(rCube &cube);

    /*
     * Solver to try upto 18 random moves
     */
    void randomSolver(rCube &cube);


    void multiStageSolver(rCube &cube);

    std::vector<moves> whiteCross(rCube &cube);

private:


    std::vector<rCube> visited;

    std::priority_queue<rCube, std::vector<rCube>, rCube::compareF> frontier;

};


#endif //RUBKIS_SOLVER_H
