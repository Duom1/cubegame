#ifndef INCLUDE_CUBEGAMEHPP
#define INCLUDE_CUBEGAMEHPP

#include "raylib.h"
#include <cstdint>
#include <string>

#define INPUT_NEUTRAL 0
#define INPUT_LEFT 1
#define INPUT_RIGHT 2

namespace CubeGame {
class Game {
private:
  // Variables window
  Vector2 window_size;
  Vector2 old_window_size;
  std::string window_title;
  int fps_target;
  bool fullscreen;
  // Variables rendering
  Camera3D camera;
  // Variables cube
  float cube_side_pos;
  float cube_vel;
  float cube_size;
  // Input variables
  uint8_t direction;
  // Important functions
  void init();
  void main_loop();
  void drawing();
  void input();
  void calc();
  // Functions
  void draw_debug_gui();
  void toggle_fullscreen();
  void init_camera();
  void init_window();
  void calc_cube();

public:
  int run();
};
}; // namespace CubeGame

#endif // INCLUDE_CUBEGAMEHPP
