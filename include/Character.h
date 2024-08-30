#pragma once

#include <string_view>
#include <utility>

#include "Rect.h"
#include "Image.h"

/*
Represents game characters such as dino, ptero.
This is abstract class - so it can't be initiated
*/
class Character : public Image, public Rect
{
public:
    Character(int left, int top,
              std::string_view relPathToDir, std::string_view fileName,
              float velocity=1
              );
    virtual ~Character() = default;

    bool isCollidedWith(const Character& object);
    // This functions are pure virtial because different characters are rendered
    // in different ways
    virtual void render() const = 0;
    // Characters' movement differs 
    // fucntion should diff its behaivor for diff key input.
    virtual void move() = 0;
    
    // Inits rect width with using Image::mImageLines
    int initWidth() const;
    
    // Inits rect height using Image::mImageLines
    int initHeight() const;

    virtual int chooseState() = 0;

private:
    // float mVelocity {};  should be in rect because it's more rect property
    // int mState {}; should be in image because it's more image property 
};

