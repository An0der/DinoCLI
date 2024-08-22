#pragma once

#include <string_view>
#include <utility>

#include "Rect.h"
#include "Image.h"


class Character : public Image, Rect
{
private:

public:
    Character(
              int left, int top,
              std::string_view relPathToDir, std::string_view fileName
             );
    virtual ~Character() = default;
    
    bool isCollidedWith(const Character& object);
    
    virtual void render() const = 0;
    
    virtual void move() = 0;

    int initWidth() const;

    int initHeight() const;
};

