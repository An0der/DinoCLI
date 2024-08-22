/*
*
*/

// Term declaration
#include "Term.h"

// for termios struct
#include <termios.h>

// for winsize struct
#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>

Term::Term(termios term, winsize termSize)
    : mOldTerm {term}, mNewTerm {mOldTerm},
      mSize {termSize}
{

}

void Term::setTty()
{
    // Sending Symbol without USING ENTER | ECHO OFF.
    mNewTermP->c_lflag &= ~(ICANON | ECHO);	
    tcsetattr(STDIN_FILENO, TCSANOW, mNewTermP);
}

void Term::setBackground()
{
    std::cout << "\x1b[47m";
}

void Term::cursorVisibility(bool mode)
{
    if (mode)
        printf("\x1b[?25h");
    else
        printf("\x1b[?25l");
}

void Term::clear()
{
    printf("\x1b[2J");
}

void Term::reset()
{	
    printf("x\1b[m");
    tcsetattr(STDIN_FILENO, TCSANOW, mOldTermP);
    cursorVisibility(1);
}

winsize Term::getSize() { return mSize; }

void Term::moveCursorTo(int x, int y)
{
    std::cout << "\x1b[" << x << ';' << y << 'H';
}
