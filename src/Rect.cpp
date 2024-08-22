#include <utility>

#include "Rect.h"


Rect::Rect(int left, int top, int width, int height, float velocity)
    : mLeft { left }, mTop { top },
      mWidth { width }, mHeight { height },
      mPos { std::pair<int, int>(mLeft, mTop) },
      mVelocity {velocity}
{}

int Rect::getLeft() const { return mLeft; }

int Rect::getTop() const { return mTop; }

std::pair<int, int> Rect::getPos() const { return mPos; }

int Rect::getHeight() const { return mHeight; }

int Rect::getWidth() const { return mWidth; }

void Rect::setPos(int left, int top)
{
    mLeft = left;
    mTop = top;
}

float Rect::getVelocity() const { return mVelocity; }

void Rect::setVelocity(float velocity) { mVelocity = velocity; }