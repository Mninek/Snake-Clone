#include "game.h"

void random(int &x, int &y)
{
	srand(time(0));
	x = 1 + rand() % (38 - 1);
	y = 1 + rand() % (38 - 1);
}

void random2(int &x, int &y)
{
	srand(time(0) + time(0));
	x = 1 + rand() % (38 - 1);
	y = 1 + rand() % (38 - 1);
}

Game::Game()
{
	FPS = 15;
}

void Game::gameKeyCallback(GLFWwindow* w)
{
	if (glfwGetKey(w,GLFW_KEY_A) == GLFW_PRESS)
	{
		if (snakeD != RIGHT)
			snakeD = LEFT;
	}
	if (glfwGetKey(w, GLFW_KEY_D) == GLFW_PRESS)
	{
		if (snakeD != LEFT)
			snakeD = RIGHT;
	}
	if (glfwGetKey(w, GLFW_KEY_W) == GLFW_PRESS)
	{
		if (snakeD != DOWN)
			snakeD = UP;
	}
	if (glfwGetKey(w, GLFW_KEY_S) == GLFW_PRESS)
	{
		if (snakeD != UP)
			snakeD = DOWN;
	}


}

void Game::initGrid(int x, int y)
{
	gridX = x;
	gridY = y;

}

void Game::drawGrid()
{
	for (int x = 0; x < gridX; x++)
	{
		for (int y = 0; y < gridY; y++)
		{
			drawSquare(x, y);
		}

	}

}

void Game::drawSquare(int x, int y)
{
	if (x == 0 || y == 0 || x == gridX - 1 || y == gridY - 1)
	{
		glLineWidth(3.0);
		glColor3f(1.0, 0.0, 0.0);
	}
	else
	{
		glLineWidth(1.0);
		glColor3f(1.0, 1.0, 1.0);
	}

	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x + 1, y);
	glVertex2f(x + 1, y + 1);
	glVertex2f(x, y + 1);
	glEnd();
}

void Game::drawSnake()
{
	for (int i = snakeLength - 1; i > 0; i--)
	{
		posX[i] = posX[i - 1];
		posY[i] = posY[i - 1];

	}
	if (snakeD == UP)
		posY[0]++;
	else if (snakeD == DOWN)
		posY[0]--;
	else if (snakeD == LEFT)
		posX[0]--;
	else if (snakeD == RIGHT)
		posX[0]++;

	for (int i = 0; i < snakeLength; i++)
	{
		glColor3f(0.0, 1.0, 0.0);
		glRectd(posX[i], posY[i], posX[i] + 1, posY[i] + 1);
	}
	for (int i = 1; i < snakeLength; i++)
	{
		if (posX[i] == posX[0] && posY[i] == posY[0])
		{
			gameOver = true;
		}
	}

	if (posX[0] == 0 || posX[0] == gridX - 1 || posY[0] == 0 || posY[0] == gridY - 1)
		gameOver = true;
	if (posX[0] == foodX && posY[0] == foodY)
		ate = true;
}

void Game::drawFood()
{
	if (ate)
	{
		random(foodX, foodY);
		snakeLength++;
		score++;
		if (score % 5 == 0 && score != 0)
			FPS++;

		if (score % 7 == 0 && score != 0)
		{
			createBaddies();
		}
	}

	ate = false;
	glColor3f(1.0, 1.0, 1.0);
	glRectf(foodX, foodY, foodX + 1, foodY + 1);
}

void Game::drawBaddies()
{
	for (int i = 0; i < 10; i++)
	{
		if (bad[i] == 0)
			i = 10;
		else
		{

			glColor3f(1.0, 0.0, 1.0);
			glRecti(badX[i], badY[i], badX[i] + 1, badY[i] + 1);
		}
		if (posX[0] == badX[i] && posY[0] == badY[i])
			gameOver = true;
	}
}

void Game::createBaddies()
{
	int current = -1;
	for (int i = 0; i < 10; i++)
	{
		if (bad[i] == 0)
		{
			bad[i] = 1;
			current = i;
			i = 10;
		}
	}
	if (current == -1)
	{
	}
	else
	{
		int tempX, tempY;

		random2(tempX, tempY);
		while (tempX >= posX[0] - 4 && tempX <= posX[0] + 4 && tempY >= posY[0] - 4 && tempY <= posY[0] + 4)
			random2(tempX, tempY);

		badX[current] = tempX;
		badY[current] = tempY;
	}
}

void Game::moveBaddies()
{
	for (int i = 0; i < 10; i++)
	{
		if (bad[i] == 0)
			i = 10;
		else
		{
			int xy = rand() % 2;
			int pm = (rand() + rand()) % 2;
			if (xy == 0)
			{
				if (pm == 0 && badX[i] != 38)
					badX[i] += 1;
				else if (pm == 1 && badX[i] != 1)
					badX[i] -= 1;
			}
			else if (xy == 1)
			{
				if (pm == 0 && badY[i] != 38)
					badY[i] += 1;
				else if (pm == 1 && badY[i] != 1)
					badY[i] -= 1;
			}
		}
	}
}

int Game::gameOverFunc()
{
	char sScore[5];
	sprintf_s(sScore, "%d", score);
	char text[17] = "Your Score: ";
	strcat_s(text, sScore);
	MessageBox(NULL, text, "GAME OVER", 0);
	
	return 0;
}

int Game::checkGameOver()
{
	if (gameOver)
	{
		return 1;
	}
	else return 0;
}

int Game::getFPS()
{
	return FPS;
}

int Game::getScore()
{
	return score;
}