#pragma once
#include <irrKlang.h>
#include <Windows.h>
#include <gl/GL.h>
using namespace irrklang;

class soundSys
{
private: 
	ISoundEngine * sound = createIrrKlangDevice();
public:
	soundSys();
	void gameSounds(int);
	void gameOver();
};
