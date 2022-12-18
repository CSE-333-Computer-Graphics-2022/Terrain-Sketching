#ifndef GLOBALS_H
#define GLOBALS_H

#include "imgui.h"

const int SCREEN_W = 1366;
const int SCREEN_H = 768;

const ImVec4 WHITE = ImVec4(0.1f, 0.1f, 0.1f, 1.0f);

enum MODES
{
    FLY,
    SILHOUETTE,
    REGION,
    AERIAL
};

#endif