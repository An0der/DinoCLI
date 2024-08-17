#pragma once

#include <utility> // for std::pair
#include "Rect.h"

class Dino : public Rect
{
public:
    Dino() = default;
    Dino(std::pair<int, int>);
    void render();
    std::pair<int, int> getPos() const;
    void setPos(std::pair<int, int>);
    void render_basic();
    void render_run_L();
    void render_run_R();
    void render_low();
    void render();
    struct Image
    {

    };
private:
    std::pair<int, int> mPos {}; // position of leftmost character

    int mState = 0; // basic = 0, run = 1, jump = 2, low = 3;
};