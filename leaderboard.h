#pragma once
#include <string>
#include <vector>
#include "player.h"
#include <iostream>
#include <fstream>

using namespace std;

class leaderboard
{
private: 
	string name;
	int score, day, month, year;

public:
	leaderboard();
	leaderboard(string, int);
	leaderboard(string, int, int, int, int);
	void writeToFile();
	void display();
};