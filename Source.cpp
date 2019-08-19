#include <GLFW/glfw3.h>
#include <gl/GL.h>
#include <iostream>
#include <Windows.h>
#include "game.h"
#include <string>
#include "leaderboard.h"
#include "sortLeader.h"


#define COLS 40
#define ROWS 40
#define SCREEN_HEIGHT 800
#define SCREEN_WIDTH 800

short snakeD;
using namespace std;


void initStuff();
//void keyCallback(GLFWwindow*, int, int, int, int);

int main()
{
	if (!glfwInit())
	{
		cout << "GLFW could not be initialized.";
		return -1;
	}


	//glfwSetKeyCallback(window, keyCallback);

	//glClearColor(1.0, 0.0, 0.0, 1.0); //makes window red (rgbAlpha)
	string name = "";
	int endScore = 0;
	int option = 0;
	while (option != 4)
	{
		cout << "Please select your option!\n(1) Play\n(2) Leadboard\n(3) How to play\n(4) Quit\n";
		cin >> option;
		while (option < 1 || option > 4)
		{
			cout << "invalid input, please enter 1-3\n";
			cin >> option;
		}

		while (option == 1)
		{

			glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
			GLFWwindow * window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake Game", NULL, NULL);


			if (!window)
			{
				glfwTerminate();
				return -1;
			}

			glfwMakeContextCurrent(window);

			Game game;
			initStuff();

			game.initGrid(COLS, ROWS);
			game.drawGrid();

			int skip = 0;
			double lasttime = glfwGetTime();
			while (!glfwWindowShouldClose(window))
			{
				int FPS = game.getFPS();
				while (glfwGetTime() < lasttime + 1.0 / FPS) //fps will control how fast my snake moves
				{
				}
				/* Render here */
				glClear(GL_COLOR_BUFFER_BIT);
				if (skip % 2 == 0)
				{
					game.moveBaddies();
				}
				game.drawGrid();
				game.gameKeyCallback(window);
				game.drawSnake();
				game.drawFood();
				game.drawBaddies();
				glfwSwapBuffers(window);


				glfwPollEvents();
				
				skip++;
				lasttime += 1.0 / FPS;

				int q = game.checkGameOver();
				if (q == 1)
				{
					endScore = game.getScore();
					option = game.gameOverFunc();
					glfwDestroyWindow(window);
				}
			}
			cout << "Your Score: " << endScore << "\nPlease Enter your name: ";
			cin >> name;
			cout << "\n\n\n";
			leaderboard player = leaderboard(name, endScore);
			player.writeToFile();
		}

		while (option == 2)
		{
			readFile();
			option = 0;
			system("pause");
			cout << "\n\n\n";
		}

		while (option == 3)
		{
			cout << "This game is a simple snake game. Use WASD to move, collect the white squares, and don't let the red squares touch the snake's head (the body is ok).\n";
			option = 0;
			system("pause");
			cout << "\n\n\n";
		}
	}

	return 0;
}

void initStuff() //initializing some window stuff
{
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT); //viewport (x,y) cords
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, COLS, 0.0, ROWS, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}