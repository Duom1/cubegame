#include "cubegame.hpp"
#include "raylib.h"

#include "imgui.h"
#include "rlImGui.h"

void CubeGame::Game::init() {
  init_window();
  init_camera();
  rlImGuiSetup(true);
}

void CubeGame::Game::init_window() {
  fps_target = 60;
  window_size = {800, 600};
  window_title = "Cube game";
  fullscreen = false;
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(window_size.x, window_size.y, window_title.c_str());
  SetTargetFPS(fps_target);
  SetExitKey(KEY_NULL);
}

void CubeGame::Game::init_camera() {
  camera.position = {0.0, 5.0, 5.0};
  camera.target = {0.0, 0.0, 0.0};
  camera.up = {0.0, 1.0, 0.0};
  camera.fovy = 90.0;
  camera.projection = CAMERA_PERSPECTIVE;
}

void CubeGame::Game::drawing() {
  BeginDrawing();

  ClearBackground(WHITE);

  BeginMode3D(camera);

  Vector3 cubePosition = {0.0, 0.0, 3.0};
  DrawCube(cubePosition, 2.0, 2.0, 2.0, RED);
  DrawCubeWires(cubePosition, 2.0, 2.0, 2.0, MAROON);

  EndMode3D();

  rlImGuiBegin();
  ImGui::Begin("Hello world");
  ImGui::Text("fps: %i", GetFPS());
  ImGui::End();
  rlImGuiEnd();

  EndDrawing();
}

void CubeGame::Game::input() {
  if (IsKeyPressed(KEY_F11)) {
    toggle_fullscreen();
  }
}

void CubeGame::Game::calc() {
  if (IsWindowResized()) {
    window_size = {static_cast<float>(GetScreenWidth()),
                   static_cast<float>(GetScreenHeight())};
  }
}

void CubeGame::Game::main_loop() {
  while (!WindowShouldClose()) {
    drawing();
    input();
    calc();
  }
}

int CubeGame::Game::run() {
  init();
  main_loop();
  rlImGuiShutdown();
  CloseWindow();
  return 0;
}

void CubeGame::Game::toggle_fullscreen() {
  if (!fullscreen) {
    old_window_size = window_size;
    SetWindowSize(GetMonitorWidth(0), GetMonitorHeight(0));
  }
  ToggleFullscreen();
  if (fullscreen) {
    window_size = old_window_size;
    SetWindowSize(window_size.x, window_size.y);
  }
  fullscreen = !fullscreen;
}
