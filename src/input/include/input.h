#define MAX_KEYS 1024
#define MAX_BUTTONS 32

#include <GLFW/glfw3.h>
namespace engine {
namespace input {
class Input {
public:
  static Input *getInstance() {
    static Input instance; // Guaranteed to be destroyed.
                           // Instantiated on first use.
    return &instance;
  }

private:
  bool _keys[MAX_KEYS];
  bool _buttons[MAX_BUTTONS];
  double mx, my;

private:
  Input() {}
  static void handleKeyCallback(int key, int scancode, int action, int mods);

public:
  Input(Input const &) = delete;
  void operator=(Input const &) = delete;
  static void key_callback(GLFWwindow *window, int key, int scancode,
                           int action, int mods) {
    handleKeyCallback(key, scancode, action, mods);
  }
};

} // namespace input
} // namespace engine