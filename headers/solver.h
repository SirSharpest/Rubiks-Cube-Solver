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

    solver();

    void AStarIDS(rCube * cubeToSolve);


private:

    std::stack <moves> frontier;




};


#endif //RUBKIS_SOLVER_H
