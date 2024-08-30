#pragma once
#include <utility>


/*
Left and top are class member to control character's position.
mPos member variable is used to facilitate position managing.
mVelocity is used for advanced movement mechanics e.g jumping
mWidth & mHeight represent the width and height of the rectangle respectively
 and can be used to count the right and bottom side coordinates
*/
class Rect
{
public:
    Rect(int left, int top, int width, int height, float velocity=1);
    // why virtual and not abstract class? 
    // - cause Character class abstract class
    virtual ~Rect() = default;
    int getLeft() const;
    // int getRight() const; - it's easier to change only 2 coors instead of 4
    // Just change left, top and count right and bottom using width and height 
    //if it's needed
    // That's why i didn't use left, top, right, bottom.
    int getTop() const;

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