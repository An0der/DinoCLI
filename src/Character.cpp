#include "Character.h"


Character::Character(std::string_view fileName, std::pair<int, int> initPos)
    : Rect{initPos}, Image{fileName}
{
    // set Rect parameters from input Image
}


bool Character::isCollidedWith(const Character& object)
{
    if (this->mRight <= object.mLeft)
    {
        return 0;
    }
    if (this->mBottom <= object.mLeft)
    {
        return 0;
    }
    
}


