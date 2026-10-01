#include "gameMain.h"
#include <raylib.h>

bool initGame()
{
	// Initialize game resources here
	return true;
}

bool updateGame()
{
	DrawRectangle(75, 75, 100, 100, { 0,255,0,127 });
	DrawRectangle(50, 50, 100, 100, { 255,0,0,127 });

	DrawText("My RPG is running!", 250, 200, 20, WHITE);
	// Update game logic here
	return true;
}

void closeGame()
{
	// Clean up game resources here
}