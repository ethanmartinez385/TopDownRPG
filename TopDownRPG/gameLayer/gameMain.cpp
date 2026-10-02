#include "gameMain.h"
#include <raylib.h>
#include <assert.h>

struct GameData
{

	float positionX = 100;
	float positionY = 100;


}gameData;
bool initGame()
{
	// Initialize game resources here
	return true;
}

bool updateGame()
{

	float deltaTime = GetFrameTime();
	if (deltaTime > 1.f / 5) { deltaTime = 1 / 5.f; } //limit deltaTime to 1/5th of a second to avoid large jumps in position when the game lags

	if (IsKeyDown(KEY_A)) { gameData.positionX -= 200 * deltaTime; }
	if (IsKeyDown(KEY_D)) { gameData.positionX += 200 * deltaTime; }
	if (IsKeyDown(KEY_W)) { gameData.positionY -= 200 * deltaTime; }
	if (IsKeyDown(KEY_S)) { gameData.positionY += 200 * deltaTime; }




	//position x, position y, width, height, color
	DrawRectangle(gameData.positionX, gameData.positionY, 50, 50, {255, 0, 200, 255});

	// Update game logic here
	return true;
}

void closeGame()
{
	// Clean up game resources here
}