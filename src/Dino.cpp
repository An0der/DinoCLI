#include <iostream>
#include "Dino.h"


Dino::Dino(std::pair<int, int> pos)
    : mPos {pos}
{

}

void Dino::render_basic()
{
    std::cout << "      ___" << std::endl;
    std::cout << "     |o__|" << std::endl;
    std::cout << "     /##/" << std::endl;
    std::cout << "\\_/###/" << std::endl;
    // std::cout << "   #_ #_" << std::endl;
}

void Dino::render_run_L()
{
    // std::cout << "      ___" << std::endl;
    // std::cout << "     |o__|" << std::endl;
    // std::cout << "     /##/" << std::endl;
    // std::cout << "\\_/###/" << std::endl;
    std::cout << "   #  #_";
    std::cout << "   #_" << std::endl;
}

void Dino::render_run_R()
{
    // std::cout << "      ___" << std::endl;
    // std::cout << "     |o__|" << std::endl;
    // std::cout << "     /##/" << std::endl;
    // std::cout << "\\_/###/" << std::endl;
    std::cout << "   #_ #";
    std::cout << "      #_" << std::endl;
}

void Dino::render(int dinoColor)
{
		
    std::cout << "\x1b[40m";
    switch (mState)
    {
        case 1:
            render_run_L();
            render_run_R();
            break;
        case 2:
            render_low();
            break;
        default:
            render_basic();
    }

    
    std::cout << "\x1b[47m";
    std::flush(std::cout);
}