#include <iostream>
#include "../headers/rCube.hpp"
#include "../headers/solver.hpp"
#include <sys/resource.h>


#define debug

void fixRam();


int main() {

    rCube rcube1 = rCube();
    solver solver1 = solver();

#ifdef debug

    //Do a little ram fix so that we can fill the thing!
    fixRam();


    std::srand(std::time(NULL));
    int move;
    int numMoves;
    std::cin >> numMoves;

    //Loop for as many moves as we request
    for(int i = 0; i < numMoves ; i++){
        move = (rand() % 12 + 0);

        std::cout << move << ":";

        rcube1.makeMove((moves) move );
    }

    //Print out a blank line in between
    std::cout << std::endl;

    rcube1.printCube();

    //solver1.AStarIDS(&rcube1, 0);
    solver1.randomSolver(rcube1);


    //Print out if it was completed
    std::cout << "Completed code has been made" << std::endl;

#endif



    return 0;
}


void fixRam(){

    const rlim_t kStackSize = 7000 * 1024 * 1024;   // min stack size = 7000 MB
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                fprintf(stderr, "setrlimit returned result = %d\n", result);
            }
        }
    }
}