#include <iostream>
#include "../headers/rCube.h"
#include "../headers/solver.h"

#define debug

int main() {

    rCube rcube1 = rCube();
    solver solver1 = solver();

#ifdef debug
    rcube1.makeMove((moves)1);
    rcube1.makeMove((moves)1);
    rcube1.makeMove((moves)4);
    rcube1.makeMove((moves)7);
    rcube1.makeMove((moves)9);
    rcube1.makeMove((moves)11);

    rcube1.printCube();

    solver1.AStarIDS(&rcube1, 0);

    std::cout << "Completed code has been made" << std::endl;

#endif



    return 0;
}