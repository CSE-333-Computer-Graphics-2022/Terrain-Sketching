#include "ui.hpp"

void UI::sidebar()
{
	ImGui::SetNextWindowSize(ImVec2(SCREEN_W * 0.25, SCREEN_H));
	ImGui::SetNextWindowPos(ImVec2(SCREEN_W * 0.7, 0));
	ImGui::SetNextWindowBgAlpha(1.0f);
	ImGui::Begin("Active Mode", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
	if (ImGui::RadioButton("Fly Mode", &programMode, FLY) || ImGui::IsKeyPressed('1'))
	{
		programMode = FLY;
	}
	if (ImGui::RadioButton("Silhouette Mode", &programMode, SILHOUETTE) || ImGui::IsKeyPressed('2'))
	{
		programMode = SILHOUETTE;
	}
	if (ImGui::RadioButton("Region Mode", &programMode, REGION) || ImGui::IsKeyPressed('3'))
	{
		programMode = REGION;
	}
	if (ImGui::RadioButton("Aerial Mode", &programMode, AERIAL) || ImGui::IsKeyPressed('4'))
	{
		programMode = AERIAL;
	}

		ImGui::NewLine();
	ImGui::Text("Press 1 to 4 to cycle through different modes.\n\n\n\n");

	switch(programMode)
	{
		case FLY:
			ImGui::Text("Fly Navigation Mode: \nUse WASD keys to move around.\nQ/E to move up and down.\nMouse to look around.\nHold Shift for faster navigation.\n");
			break;
		case SILHOUETTE:
			ImGui::Text("Silhouette Mode: \nDraw a silhouette curve by mouse.\nBoundary and Shadow are automatically created.\nPress Enter to deform the terrain.\n");
			break;
		case REGION:
			ImGui::Text("Region Mode: \nDraw a region (closed curve) by mouse.\nPress Enter then draw a noise.\nPress Enter again to deform the terrain.\n");
			break;
		case AERIAL:
			ImGui::Text("Aerial Mode: \nDraw a shadow curve on terrain by mouse.\nPress Enter to generate the boundary curve.\nPress Enter and draw the silhouette.\nPress Enter to deform the terrain.\n");
		default:
		break;
	}

	ImGui::End();

	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::Begin("info", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMouseInputs);
	ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 255, 255));
	switch (programMode)
	{
	case FLY:
		ImGui::Text("Fly Navigation Mode");
		break;

	case SILHOUETTE:
		ImGui::Text("Silhouette Mode");
		break;

	case REGION:
		ImGui::Text("Region Mode");
		break;

	case AERIAL:
		ImGui::Text("Aerial Mode");
		break;

	default:
		ImGui::Text("Fly Navigation Mode");
		break;
	}
	ImGui::PopStyleColor();
	ImGui::End();
}