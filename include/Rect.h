#pragma once
#include <utility>



class Rect
{
public:
    Rect(int left, int top, int width, int height, float velocity=1);
    virtual ~Rect() = default;
    int getLeft() const;
    // int getRight() const; - it's easier to change only 2 coors instead of 4
    // Just change left, top and count right and bottom using width and height if it's needed
    int getTop() const;
    // int getBottom() const; - it's easier to change only 2 coors instead of 4
    std::pair<int, int> getPos() const;
    
    void setPos(int x, int y);
    
    int getWidth() const;

    int getHeight() const;
    
    float getVelocity() const;

    void setVelocity(float velocity);
private:
    int mLeft {};
    int mTop {};
    int mWidth {};
    int mHeight {};
    std::pair<int, int> mPos {};
    float mVelocity {};
};