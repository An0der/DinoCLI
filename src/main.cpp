// For tsgetattr(), tssetattr().
#include <termios.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
// For ioctl().
#include <sys/ioctl.h>
#include <time.h>
#include <csignal>
#include <vector>

// for sleep - fps
#include <thread>
#include <chrono>
#include <string>

// for system();
#include <signal.h>
#include <stdlib.h>

#include "Term.h"

using namespace std;

class Dino
{
private:
	std::pair<int, int> mPos {1, 1};
public:
	Dino() = default;
	Dino(const std::pair<int, int>& pos)
		: mPos {pos}
	{}


	void move(char direction);

	void render(std::pair<int, int> pos)
	{
		
		printf("\x1b[40m");
		for (int i = 0; i < 4; ++i)
		{
			printf("\x1b[%d;%dH", pos.first, pos.second + i);
			cout << ' ';
		}
		printf("\x1b[47m");
		std::flush(std::cout);
		mPos = pos;
	}
	
	std::pair<int, int> getPos() const
	{
		return mPos;
	}

	void setPos(std::pair<int, int> pos) { mPos = pos; }
};

class Game
{
private:
	Dino mDino {{5, 1}};
	Term mTty {};
	bool mRunning {1};
	
	
	
public:
	Game() = default;
	Game(termios term, winsize termSize)
	:	mTty {term, termSize}
	{}
	
	char get_key()
	{
		// std::string line;
		// std::getline(std::cin, line);
		// for (int i = 0; i < line.size(); ++i)
		// {
		// 	if (line[i] == 'a') return 'a';
		// 	if (line[i] == 'd') return 'd';
		// 	if (line[i] == 'w') return 'w';
		// 	if (line[i] == 's') return 's';
		// }
		char key = 0;
		cin >> key;
		return key;
	}

	void init_term()
	{
		mTty.set_tty();
		mTty.cursor_visibility(0);
		mTty.set_background();
		mTty.clear();
	}

	void play()
	{	
		init_term();
		char key = 0;
		while (mRunning)
		{	
			
			key = get_key();
			mTty.clear();
			pair<int, int> pos = mDino.getPos();
			switch (key)
			{
				case 'd':
					pos.second = min((int) mTty.get_size().ws_col, pos.second + 1);
					break;
				case 'a':
					pos.second = max(1, pos.second - 1);
					break;
				case 'w':
					pos.first = max(1, pos.first - 1);
					break;
				case 's':
					pos.first = min((int) mTty.get_size().ws_row, pos.first + 1);
					break;
			}
			mDino.render(pos);
			
			// time
			std::this_thread::sleep_for(std::chrono::nanoseconds(16666666));
		}
		mTty.reset();
		cout << "END\n";
	}
};


int main(int argc, char** argv)
{		

	termios term;
	tcgetattr(STDIN_FILENO, &term);
	winsize size;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &size);
	Game game {term, size};
	game.play();
	cout << "\x1b[32mHell oworld\x1b[m\n";
	return 0;

}
