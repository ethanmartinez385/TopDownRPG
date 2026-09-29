#include "raylib.h"

int main()
{
	InitWindow(800, 450, "My Top Down RPG");

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		DrawRectangle(50, 50, 100, 100, { 255,0,0,255 });

		DrawText("My RPG is running!", 250, 200, 20, WHITE);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}