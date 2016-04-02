#include <iostream>
#include "../headers/rCube.hpp"
#include "../headers/solver.hpp"
#include "../headers/imageProcessor.hpp"
#include <sys/resource.h>


void fixRam();
void startUp();

int main() {

    //Call start up function
    startUp();

    //Create image processor
    imageProcessor processor = imageProcessor();
    //Init the processing of images
    processor.init();

    //Create solver and cube objects
    rCube rcube1 = rCube();
    solver solver1 = solver();

    rcube1.makeMove((moves) 1);
    rcube1.makeMove((moves) 5);
    rcube1.makeMove((moves) 10);



    rcube1.printCube();


    //Apply random solver to the cube
    solver1.randomSolver(rcube1);

    return 0;
}


/*
 * Small function to start up required functionality such as
 * init of the random seed for later use, and to allocate more ram to the stack
 */
void startUp(){

    std::srand((unsigned int) std::time(NULL));
    fixRam();


}

void fixRam(){

    //Cast to u_long to fix compiler error
    const rlim_t kStackSize = (u_long) 5000 * 1024 * 1024;   // min stack size = 500 MB
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