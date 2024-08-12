#pragma once

// for termios struct
#include <termios.h>
// for winsize struct
#include <sys/ioctl.h>


class Term
{
using termios_p = termios*;
public:
    Term() = default;
    Term(termios term, winsize termSize);
    void set_tty();
    void set_background();
    void cursor_visibility(bool mode=1);
    void clear();
    void reset();
    winsize get_size();

private:
    termios mOldTerm {};
	termios mNewTerm {};
	termios_p mOldTermP {&mOldTerm};
	termios_p mNewTermP {&mNewTerm};
	winsize mSize {};

};