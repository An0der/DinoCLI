#include <iostream>

#include "Dino.h"



Dino::Dino(int left, int top,
           std::string_view relPathToDir, std::string_view fileName,
           float velocity
           )
    : Character(left, top, relPathToDir, fileName, velocity)
{

}

void Dino::setPos(this->getLeft() + moveX, this->getTop() + moveY)
{
    setPos(this->getLeft() + moveX, this->getTop() + moveY);
}


void Dino::render()
{   
    std::vector<std::string> > image;
    swich(mState)
    {
        case 1:
        image = 

    }
}

std::string chooseImage()
{
    
}

void Dino::changState()
{
    switch (getState())
    {
    case 1:
        setState(2);
        break;
    case 2:
        setState(1);
        break;
    case 3:
        setState(4);
        break;
    case 4:
        setState(3);
        break;
    }
}