#include "soundSys.h"

soundSys::soundSys()
{
	sound->setSoundVolume(.4);
	sound->play2D("Audio/open-space.mp3", GL_TRUE);
}

void soundSys::gameSounds(int s)
{
	if (s == 1)
	{
		sound->play2D("Audio/Mario_Jumping-Mike_Koenig-989896458.mp3", GL_FALSE);
	}
	else if (s == 2)
	{
		
	}
}

void soundSys::gameOver()
{
	sound->stopAllSounds();
	sound->play2D("Audio/382310__myfox14__game-over-arcade.wav", GL_FALSE);
}
