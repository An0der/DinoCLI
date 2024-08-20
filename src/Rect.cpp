#include "Rect.h"


Rect::Rect(std::pair<int, int> initPos)
    : mLeftTop {initPos}
{}


int Rect::getLeft() const { return mLeft; }

int Rect::getRight() const { return mRight; }

int Rect::getTop() const { return mTop; }

int Rect::getBottom() const { return mBottom; }