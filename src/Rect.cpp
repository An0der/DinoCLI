#include <utility>

#include "Rect.h"


Rect::Rect(int left, int top, int width, int height)
    : mLeft { left }, mTop { top },
      mWidth { width }, mHeight { height },
      mRight { left + width }, mBottom { top + height },
      mPos { std::pair<int, int>(mLeft, mTop) }
{}


int Rect::getLeft() const { return mLeft; }

int Rect::getRight() const { return mRight; }

int Rect::getTop() const { return mTop; }

int Rect::getBottom() const { return mBottom; }

std::pair<int, int> Rect::getPos() const { return mPos; }

void Rect::setPos(int left, int top)
{
    mLeft = left;
    mTop = top;
}