#include "include/input.h"
#include <iostream>
namespace engine {
namespace input {
void Input::handleKeyCallback(int key, int scancode, int action, int mods) {
  std::cout << key << std::endl;
  Input::getInstance()->_keys[key] = action != GLFW_RELEASE;
}
} // namespace input
} // namespace engine