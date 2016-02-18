#include <iostream>
#include "../headers/rCube.h"
#include "../headers/solver.h"
#include <sys/resource.h>


#define debug

void fixRam();


int main() {

    rCube rcube1 = rCube();
    solver solver1 = solver();

#ifdef debug

    //fixRam();

    rcube1.makeMove((moves)1);
    rcube1.makeMove((moves)1);
    rcube1.makeMove((moves)7);
    rcube1.makeMove((moves)7);
    rcube1.makeMove((moves)2);

    rcube1.printCube();

    solver1.AStarIDS(&rcube1, 0);

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