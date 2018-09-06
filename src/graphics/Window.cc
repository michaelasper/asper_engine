#define GL_SILENCE_DEPRECATION

#include "include/Window.h"
#include "../input/include/input.h"
#include <iostream>

namespace engine {
namespace graphics {
void resizeWindow(GLFWwindow *window, int height, int width);

Window::Window(const char *name, int width, int height) {
  _name = name;
  _width = width;
  _height = height;
  if (!init()) {
    glfwTerminate();
  }
}

Window::~Window() { glfwTerminate(); }

void Window::update() {
  glfwSwapBuffers(_window);
  glfwPollEvents();
}

bool Window::init() {

  if (!glfwInit()) {
    std::cout << "Error" << std::endl;
    return false;
  } else {
    std::cout << "Success" << std::endl;
  }

  _window = glfwCreateWindow(_width, _height, _name, NULL, NULL);

  if (!_window) {
    glfwTerminate();
    std::cout << "Error on creating window" << std::endl;
    return false;
  }

  glfwMakeContextCurrent(_window);
  glfwSetWindowSizeCallback(_window, resizeWindow);
  glfwSetWindowUserPointer(_window, this);
  glfwSetKeyCallback(_window, engine::input::Input::getInstance().key_callback);
  glfwSetMouseButtonCallback(
      _window, engine::input::Input::getInstance().mouse_callback);

  std::cout << "OpenGL Version " << glGetString(GL_VERSION) << std::endl;

  return true;
}

void resizeWindow(GLFWwindow *window, int height, int width) {
  glViewport(0, 0, width, height);
  Window *windowObject =
      (engine::graphics::Window *)glfwGetWindowUserPointer(window);
  windowObject->_height = height;
  windowObject->_width = width;
}
} // namespace graphics
} // namespace engine