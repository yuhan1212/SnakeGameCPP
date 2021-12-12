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

void Draw() {
	system("clear");
	for (int i = 0; i < width + 2; i++) 
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j ++) {
			if (j == 0)
				cout << "#";

			if (i == y && j == x)
				cout << "o";

			else if (i == fruitY && j == fruitX)
				cout << "F";

			else {
				bool print = false;
				for (int k = 0; k < nTail; k ++) {
					if (tailX[k] == j && tailY[k] == i) {
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}

			if (j == width - 1) 
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++) 
		cout << "#";
	cout << endl;
	cout << "Score: " << score << endl;

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