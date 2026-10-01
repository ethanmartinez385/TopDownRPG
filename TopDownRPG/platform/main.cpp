#include "iostream"
#include "raylib.h"
#include "imgui.h"
#include "rlImGui.h"

int main()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 450, "My Top Down RPG");

#pragma region imgui
	rlImGuiSetup(true);

	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; //enable docking
	////io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; //enable keyboard controls
	////io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad; //enable gamepad controls
	io.FontGlobalScale = 2; //changes font size for all ImGui windows/text
#pragma endregion

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

		DrawRectangle(75, 75, 100, 100, { 0,255,0,127 });
		DrawRectangle(50, 50, 100, 100, { 255,0,0,127 });

		DrawText("My RPG is running!", 250, 200, 20, WHITE);
#pragma region imgui windows
		ImGui::Begin("test");
		//ImGui::ShowDemoWindow();
		ImGui::Text("Hello, world!");
		//ImGui::Button("Click me!");
		
		//check if a button was pressed
		if (ImGui::Button("button"))
		{
			std::cout << "First button pressed\n";
		}
		ImGui::SameLine(); //puts the next button on the same line as the previous button
		if (ImGui::Button("button##2"))
		{
			std::cout << "Second button pressed\n";
		}
		ImGui::SameLine(); //puts the next button on the same line as the previous button
		if (ImGui::Button("button##3"))
		{
			std::cout << "Third button pressed\n";
		}
		ImGui::PushID(4); //pushes a new ID onto the stack, in this case the fourth button's ID
		if (ImGui::Button("button"))
		{
			std::cout << "Fourth button pressed\n";
		}
		ImGui::PopID(); //pops the last ID from the stack, in this case the fourth button's ID

		ImGui::Text("Speed");
		ImGui::SameLine();
		ImGui::TextDisabled("(?)");//creates a disabled text that is grayed out and cannot be interacted with

		if (ImGui::IsItemHovered())//checks if the last item (in this case the disabled text) is being hovered over by the mouse
		{
			ImGui::BeginTooltip(); //creates a tooltip window
			ImGui::Text("Controls how fast the player moves");
			ImGui::EndTooltip();
		}
		ImGui::End();


		//creating a second window
		ImGui::Begin("test2");

		ImGui::Text("Hello again world!");
		ImGui::Separator(); //creates a line to separate text
		ImGui::NewLine(); //creates a new line to separate text
		static float a = 0; //creates a static float variable to be used in the slider
		ImGui::SliderFloat("slider,", &a, 0, 1); //creates a slider that can be used to change the value of the static float variable

		ImGui::End();


		rlImGuiEnd();
#pragma endregion

		EndDrawing();
	}
#pragma region imgui
	rlImGuiShutdown();
#pragma endregion
	CloseWindow();

	return 0;
}