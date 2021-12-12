#include <iostream>
#include <ncurses.h>
#include<time.h> 


using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup() {
	initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
    
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}



int main() {
	Setup();
	while (!gameOver) {
		Draw();
		Input();
		Logic();
		// sleep(10);
	}
	return 0;

}