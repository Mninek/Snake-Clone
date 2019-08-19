#include "sortLeader.h"

void readFile()
{
	leaderboard topTen[10] = {};
	int scores[10] = {};

	ifstream leaderboardFile("leaderboard.txt");

	int score, month, day, year;
	string name;
	int count = 0;
	while (leaderboardFile >> name >> score >> month >> day >> year)
	{
		leaderboard temp = leaderboard(name, score, month, day, year);

		for (int i = 0; i <= 9; i++)
		{

			if (score > scores[i])
			{
				for (int j = 8; j >= i; j--)
				{
						scores[j + 1] = scores[j];
						topTen[j + 1] = topTen[j]; 
				}
				scores[i] = score;
				topTen[i] = temp;
				i = count + 1;
			}
		}
		count++;
	}
	
	for (int i = 0; i < 10; i++)
	{
	
		leaderboard temp = topTen[i];
		temp.display();
	}


}