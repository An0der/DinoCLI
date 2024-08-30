#include <iostream>

#include "Dino.h"



Dino::Dino(int left, int top,
           std::string_view relPathToDir, std::string_view fileName,
           float velocity
           )
    : Character(left, top, relPathToDir, fileName, velocity)
{

}

// void Dino::setPos(this->getLeft() + moveX, this->getTop() + moveY)
// {
//     setPos(this->getLeft() + moveX, this->getTop() + moveY);
// }

void Dino::run()
{
    printLines();
    if (getState() == 2) setState(1);
    else setState(2);
}

void Dino::duckRun()
{
    printLines();
    if (getState() == 4) setState(5);
    else setState(4);
}
// print Character's image depending on its current state;
// TODO May be place it to Character() class.
// TODO make imageLines of Image - protected for easy access from children classes
void Dino::printLines() const
{   
    
    for (int i = 0; i < mImageLines[getState()].size(); ++i)
    {
        std::cout << mImageLines[getState()][i] << '\n';
    }
}

// TODO Dino::jump()
// void Dino::jump()
// {
//     setState(1);
// }

void Dino::move()
{
    setPos(getLeft() + getVelocity(), getTop());
}


void Dino::render()
{
    switch (getState())
    {
        case 2:
        case 3:
            run();
            break;
        case 4:
        case 5:
            duckRun();
            break;
        default:
            setState(1);
            printLines();
    }
}