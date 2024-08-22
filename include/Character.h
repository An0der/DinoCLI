#pragma once

#include <string_view>
#include <utility>

#include "Rect.h"
#include "Image.h"


class Character : public Image, Rect
{
public:
    Character(int left, int top,
              std::string_view relPathToDir, std::string_view fileName,
              float velocity=1
              );
    virtual ~Character() = default;

    bool isCollidedWith(const Character& object);

    virtual void render() const = 0;

    virtual void move() = 0;

    int initWidth() const;

    int initHeight() const;

    virtual int chooseState() = 0;

private:
    // float mVelocity {};  should be in rect because it's more rect property
    // int mState {}; should be in image because it's more image property 
};

