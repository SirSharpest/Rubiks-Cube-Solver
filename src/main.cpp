#include <iostream>
#include "../headers/rCube.h"


int main() {

    rCube rcube1 = rCube();


    int move;

    rcube1.printCube();

    do{

        std::cin >> move;


        rcube1.makeMove((moves) move);
        rcube1.printCube();


    }while(!rcube1.isComplete());


    std::cout << "Completed code has been made" << std::endl;




    return 0;
}