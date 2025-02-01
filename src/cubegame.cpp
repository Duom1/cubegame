#include "cubegame.hpp"
#include "raylib.h"

void CubeGame::Game::init() {
  window_size = {800, 600};
  fps_target = 60;
  window_title = "Cube game";
  fullscreen = false;
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(window_size.x, window_size.y, window_title.c_str());
  SetTargetFPS(fps_target);
}

void CubeGame::Game::drawing() {
  BeginDrawing();
  ClearBackground(WHITE);
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
