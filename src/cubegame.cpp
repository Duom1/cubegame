#include "cubegame.hpp"
#include "raylib.h"

#include "imgui.h"
#include "rlImGui.h"

void CubeGame::Game::init() {
  init_window();
  init_camera();
  cube_size = 2.0;
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

void CubeGame::Game::draw_debug_gui() {
  rlImGuiBegin();
  ImGui::Begin("Debug info");
  ImGui::Text("fps: %i", GetFPS());
  ImGui::Text("direction: %i", direction);
  ImGui::End();
  rlImGuiEnd();
}

void CubeGame::Game::drawing() {
  BeginDrawing();

  ClearBackground(WHITE);

  BeginMode3D(camera);

  Vector3 cubePosition = {cube_side_pos, 0.0, 3.0};
  Vector3 cube_size_full = {
      cube_size,
      cube_size,
      cube_size,
  };
  DrawCubeV(cubePosition, cube_size_full, RED);
  DrawCubeWiresV(cubePosition, cube_size_full, MAROON);

  EndMode3D();

  draw_debug_gui();

  EndDrawing();
}

void CubeGame::Game::input() {
  if (IsKeyPressed(KEY_F11)) {
    toggle_fullscreen();
  }
  if (IsKeyDown(KEY_A)) {
    direction = INPUT_LEFT;
  } else if (IsKeyDown(KEY_D)) {
    direction = INPUT_RIGHT;
  } else {
    direction = INPUT_NEUTRAL;
  }
}

void CubeGame::Game::calc() {
  if (IsWindowResized()) {
    window_size = {static_cast<float>(GetScreenWidth()),
                   static_cast<float>(GetScreenHeight())};
  }
  calc_cube();
}

void CubeGame::Game::calc_cube() {
  if (cube_vel <= 0.1 && cube_vel >= -0.1) {
    if (direction == INPUT_LEFT) {
      cube_vel -= .01;
    } else if (direction == INPUT_RIGHT) {
      cube_vel += .01;
    }
  }
  if (direction == INPUT_NEUTRAL) {
    if (cube_vel > 0) {
      cube_vel -= .01;
    } else if (cube_vel < 0) {
      cube_vel += .01;
    }
    if (cube_vel < .0001 && cube_vel > -.0001) {
      cube_vel = 0.0;
    }
  }
  cube_side_pos += cube_vel;
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
