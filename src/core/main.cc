#define GLFW_INCLUDE_GLCOREARB
#define GL_SILENCE_DEPRECATION

#include "../graphics/include/Window.h"
#include "include/Game.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  using namespace engine;
  using namespace graphics;
  Window *window = new Window("Hello World", 640, 480);

  GLuint vao;
  glGenVertexArrays(1, &vao);
  while (!window->isClosed()) {
    window->update();
  }
  return 0;
}
