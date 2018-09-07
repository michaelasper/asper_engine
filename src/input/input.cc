#include "include/input.h"
#include <iostream>
namespace engine {
namespace input {
void Input::handleKeyCallback(int key, int scancode, int action, int mods) {
  std::cout << key << std::endl;
  Input::getInstance()._keys[key] = action != GLFW_RELEASE;
}

void Input::handleMouseCallback(int button, int action, int mods) {
  std::cout << button << std::endl;
  Input::getInstance()._buttons[button] = action != GLFW_RELEASE;
}

void Input::handleCursorCallback(double xpos, double ypos) {
  //   std::cout << xpos << " " << ypos << std::endl;
  Input::getInstance()._mx = xpos;
  Input::getInstance()._my = ypos;
}
} // namespace input
} // namespace engine