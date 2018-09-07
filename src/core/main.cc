#define GLFW_INCLUDE_GLCOREARB
#define GL_SILENCE_DEPRECATION

#include "../graphics/include/Window.h"
#include "../math/include/vec.h"
#include "include/Game.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  using namespace engine;
  math::Vec<float, 2> test{};
  test[0] = 2;
  test[1] = 3;
  auto test2 = test + 5;
  std::cout << test2;
  return 0;
}
