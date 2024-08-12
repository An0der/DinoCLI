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

void Term::set_tty()
{
    // Sending Symbol without USING ENTER | ECHO OFF.
    mNewTermP->c_lflag &= ~(ICANON | ECHO);	
    tcsetattr(STDIN_FILENO, TCSANOW, mNewTermP);
}

void Term::set_background()
{
    std::cout << "\x1b[47m";
}

void Term::cursor_visibility(bool mode)
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
    cursor_visibility(1);
}

winsize Term::get_size() { return mSize; }
