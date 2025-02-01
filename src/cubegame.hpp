#ifndef INCLUDE_CUBEGAMEHPP
#define INCLUDE_CUBEGAMEHPP

#include "raylib.h"
#include <string>

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
  // Important functions
  void init();
  void main_loop();
  void drawing();
  void input();
  void calc();
  // Functions
  void toggle_fullscreen();

public:
  int run();
};
}; // namespace CubeGame

#endif // INCLUDE_CUBEGAMEHPP
