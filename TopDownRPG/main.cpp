#include "iostream"
#include "raylib.h"

#include "imgui.h"
#include "rlImGui.h"

#include "gameMain.h"


int main()
{

#if PRODUCTION_BUILD == 1
	SetTraceLogLevel(LOG_NONE); //no log output to the console by raylib
#endif 

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 450, "My Top Down RPG");
	SetExitKey(KEY_NULL);// Disable Esc from closing window
	SetTargetFPS(240);
#pragma region imgui
	rlImGuiSetup(true);

	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; //enable docking
	////io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; //enable keyboard controls
	////io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad; //enable gamepad controls
	io.FontGlobalScale = 2; //changes font size for all ImGui windows/text
#pragma endregion

	if (!initGame())
	{
		return 0;
	}
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
#pragma region imgui
		rlImGuiBegin();

		ImGui::PushStyleColor(ImGuiCol_WindowBg, {});//makes the background of all ImGui windows transparent
		ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {}); //makes the background of the docking space transparent
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport()); //enable docking for all ImGui windows
		ImGui::PopStyleColor(2); //pops the two style colors we pushed earlier
#pragma endregion

		if (!updateGame())
		{
			CloseWindow();
		}

	#pragma region imgui
		rlImGuiEnd();
	#pragma endregion

		EndDrawing();
	}

	CloseWindow();

	std::cout << "\n\nCLOSED!!!!!!!!!\n\n";
	closeGame();

#pragma region imgui
	rlImGuiShutdown();
#pragma endregion

	return 0;
}