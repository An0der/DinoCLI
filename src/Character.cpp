#include "Character.h"


Character::Character(
                     int left, int top,
                     std::string_view relPathToDir, std::string_view fileName,
                     float velocity
                     )
    :   Image(relPathToDir, fileName), Rect (left, top, initWidth(), initHeight(), velocity)
{
    
}

// the most easy checker which checks whether this collides with
// object via right edge of rectangle
bool Character::isCollidedWith(const Character& object)
{
    if ((this->getLeft() + this->getWidth()) >= (object.getLeft() + object.getWidth()) / 2)
    {
        return 1;
    }
    return 0;
    
}

// Inits rect width with using Image::mImageLines
int Character::initWidth() const
{
    int maxLineWidth = 0;
    const std::map<int, std::vector<std::string> >& mImageLines = getImageLines();
    for (const auto& line : mImageLines)
    {
        maxLineWidth = std::max(static_cast<int>(line.second.size()), maxLineWidth);
    }
    return maxLineWidth;
}
// Inits rect height using Image::mImageLines
int Character::initHeight() const 
{   
    const std::map<int, std::vector<std::string> >& mImageLines = getImageLines();
    return mImageLines.size(); 
}






