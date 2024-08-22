#pragma once
#include <utility>



class Rect
{
private:
    int mLeft {};
    int mTop {};
    int mWidth {};
    int mHeight {};
    int mRight {};
    int mBottom {};
    std::pair<int, int> mPos {};
public:
    Rect(int left, int top, int width, int height);
    virtual ~Rect() = default;
    int getLeft() const;
    int getRight() const;
    int getTop() const;
    int getBottom() const;
    std::pair<int, int> getPos() const;
    void setPos(int x, int y);
};