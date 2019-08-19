#pragma once
#include <GLFW/glfw3.h>
#include <gl/GL.h>
#include <ctime>
#include <iostream>
#include <Windows.h>
#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4


class Game
{
private:
	int gridX = 0, gridY = 0, posX[1444]{ 20,20,20,20,20 }, posY[1444] = { 20,19,18,17,16}, foodX, foodY, snakeLength = 5, bad[10] = {}, badX[10] = {}, badY[10] = {}, score = -1, FPS = 15;
	bool gameOver = false, ate = true;
	short snakeD = RIGHT;
public:
	Game();
	void initGrid(int, int);
	void drawSquare(int, int);
	void drawGrid();
	void drawSnake();
	void drawFood();
	void drawBaddies();
	void createBaddies();
	void moveBaddies();
	int gameOverFunc();
	void gameKeyCallback(GLFWwindow*);
	int checkGameOver();
	int getFPS();
	int getScore();
};