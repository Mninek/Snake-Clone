#include "leaderboard.h"

leaderboard::leaderboard()
{
	name = "";
	score = 0;
	SYSTEMTIME time;
	GetLocalTime(&time);
	day = time.wDay;
	month = time.wMonth;
	year = time.wYear;
}

leaderboard::leaderboard(string s, int x)
{
	name = s;
	score = x;

	SYSTEMTIME time;
	GetLocalTime(&time);
	day = time.wDay;
	month = time.wMonth;
	year = time.wYear;
}

leaderboard::leaderboard(string s, int x, int m, int d, int y)
{
	name = s;
	score = x;
	day = d;
	month = m;
	year = y;
}

void leaderboard::writeToFile()
{
	ofstream leaderboardFile("leaderboard.txt", ios_base::app);
	leaderboardFile << name << ' ' << score << ' ' << month << ' ' << day << ' ' << year << endl;
}


void leaderboard::display()
{
	cout << month << '/' << day << '/' << year << "\t" << name << ": " << score << endl;
}