#pragma once

#include "Character.h"


/*
Define render() & move() from base class
*/
class Dino : public Character
{
public:
    Dino(int left, int top, 
         std::string_view relPathToDir, std::string_view fileName,
         float velocity=1
         );

    void render();

    void move(int moveX, int moveY);
    // after this we use tty to change the cursor to this->getX() & this->getY()
    // and then use render()

    void jump();

    void changeState();

    void move() override;

    void run();

    void duckRun();

    void printLines() const;
};