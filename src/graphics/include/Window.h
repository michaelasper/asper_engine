#include <GLFW/glfw3.h>

namespace engine {
namespace graphics {
class Window {

private: // private variables
  int _width, _height;
  const char *_name;
  GLFWwindow *_window;

public: // public methods
  Window(const char *name, int width, int height);
  ~Window();
  void update();
  inline bool isClosed() const { return glfwWindowShouldClose(_window); }
  inline int getHeight() const { return _height; }
  inline int getWidth() const { return _width; }

private: // private methods
  bool init();
  friend void resizeWindow(GLFWwindow *window, int height, int width);
};

} // namespace graphics
} // namespace engine