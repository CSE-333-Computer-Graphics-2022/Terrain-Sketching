#include "ui.hpp"

void UI::sidebar()
{
	ImGui::SetNextWindowSize(ImVec2(SCREEN_W * 0.25, SCREEN_H));
	ImGui::SetNextWindowPos(ImVec2(SCREEN_W * 0.7, 0));
	ImGui::SetNextWindowBgAlpha(1.0f);
	ImGui::Begin("Toolbar", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
	if (ImGui::RadioButton("Fly Mode", &programMode, FLY) || ImGui::IsKeyPressed('1'))
	{
		programMode = FLY;
	}
	if (ImGui::RadioButton("Silhouette Mode", &programMode, SILHOUETTE) || ImGui::IsKeyPressed('2'))
	{
		programMode = SILHOUETTE;
	}
	ImGui::End();


	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::Begin("info", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | 
	ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMouseInputs);
	ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(48, 48, 48, 255));
	switch (programMode)
	{
	case FLY:
		ImGui::Text("Fly Navigation Mode");
		break;
	
	case SILHOUETTE:
		ImGui::Text("Silhouette Mode");
		break;
	default:
		ImGui::Text("Fly Navigation Mode");
		break;
	}
	ImGui::PopStyleColor();
	ImGui::End();
}