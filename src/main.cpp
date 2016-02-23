#include <iostream>
#include "../headers/rCube.hpp"
#include "../headers/solver.hpp"
#include <sys/resource.h>


void fixRam();


int main() {

    rCube rcube1 = rCube();
    solver solver1 = solver();
    std::srand((unsigned int) std::time(NULL));

    rcube1.printCube();




    return 0;
}


void fixRam(){

    //Cast to u_long to fix compiler error
    const rlim_t kStackSize = (u_long) 7000 * 1024 * 1024;   // min stack size = 7000 MB
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