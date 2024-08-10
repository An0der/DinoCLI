// For tsgetattr(), tssetattr().
#include <termios.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
// For ioctl().
#include <sys/ioctl.h>
#include <time.h>
#include <csignal>


using namespace std;


class Term
{
using termios_p = termios*;
private:
	termios mOldTerm {};
	termios mNewTerm {};
	termios_p mOldTermP {&mOldTerm};
	termios_p mNewTermP {&mNewTerm};
	winsize mSize {};
	bool helper {};
public:

	Term(const termios term)
		: mOldTerm {term}, mNewTerm {mOldTerm},
		  helper {ioctl(STDIN_FILENO, TIOCGWINSZ, &mSize)}
	{
		
	}
	
	void set_tty()
	{
		// Sending Symbol without USING ENTER | ECHO OFF.
		mNewTermP->c_lflag &= ~(ICANON | ECHO);	
		tcsetattr(STDIN_FILENO, TCSANOW, mNewTermP);
	}

	void cursor_visibility(bool mode=1)
	{	
		if (mode)
			printf("\e[?25h");
		else
			printf("\e[?25l");
	}

	void set_color();

	void clear()
	{
		printf("\e[2J");
	}

	void reset()
	{	
		printf("x\1b[m");
		tcsetattr(STDIN_FILENO, TCSANOW, mOldTermP);
		cursor_visibility(1);
	}

	winsize size() { return mSize; }
	

	friend std::ostream& operator<< (std::ostream& out, const Term& term);
};

std::ostream& operator<< (std::ostream& out, const Term& term)
{
	out << "\nRows: " << term.mSize.ws_row << "\nCols: " << term.mSize.ws_col << '\n'; 
	return out;
}

class Dino
{
private:
	std::pair<int, int> mPos {1, 1};
	

public:

	Dino(const std::pair<int, int>& pos)
		: mPos {pos}
	{}


	void move(char direction);

	void render(std::pair<int, int> pos)
	{
		
		printf("\e[%d;%dH", pos.first, pos.second);
		cout << '@';
	}
	
	std::pair<int, int> getPos()
	{
		return mPos;
	}

	void setPos(std::pair<int, int> pos) { mPos = pos; }
};


int main()
{	
	
	termios term;
	tcgetattr(STDIN_FILENO, &term);
	Term tty {term};
	tty.clear();
	tty.set_tty();
	tty.cursor_visibility(0);
	
	bool running = true;
	char key = '0';
	
	timespec req = {};
	timespec rem = {};
	
	winsize term_size = tty.size();
	Dino dino {std::pair<int, int> {term_size.ws_row / 2, 1}};
	while (running)
	{	
		cin >> key;
		tty.clear();
		std::pair<int, int> pos = dino.getPos();
		if (key == 'd')
		{	
			pos.second = min((int) tty.size().ws_col, pos.second + 1);
			
		}
		if (key == 'a')
		{
			pos.second = max(1, pos.second - 1);
		}
		if (key == 'w')
		{
			pos.first = max(1, pos.first - 1);
		}
		if (key == 's')
		{
			pos.first = min((int) tty.size().ws_row, pos.first + 1);
		}
		dino.setPos(pos);
		dino.render(pos);
		std::flush(cout);
		req.tv_nsec = 0.1 * 1000000000;
		nanosleep(&req, &rem);
		
		
		
	}
	tty.reset();
	cout << tty << '\n';
	cout << "\e[32mHell oworld\e[m\n";
	return 0;

}


