#define MAX_KEYS 1024
#define MAX_BUTTONS 32

#include <GLFW/glfw3.h>
namespace engine {
namespace input {
class Input {
public:
  static Input &getInstance() {
    static Input instance; // Guaranteed to be destroyed.
                           // Instantiated on first use.
    return instance;
  }

private:
  bool _keys[MAX_KEYS];
  bool _buttons[MAX_BUTTONS];
  double _mx, _my = 0;

private:
  Input() {
    for (int i = 0; i < MAX_KEYS; i++)
      _keys[i] = false;
    for (int i = 0; i < MAX_BUTTONS; i++)
      _buttons[i] = false;
  }
  static void handleKeyCallback(int key, int scancode, int action, int mods);
  static void handleMouseCallback(int button, int action, int mods);
  static void handleCursorCallback(double xpos, double ypos);

public:
  inline bool isKeyPressed(unsigned int key) {
    if (key >= MAX_KEYS)
      return false;
    return _keys[key];
  }

  inline bool isMousePressed(unsigned int button) {
    if (button >= MAX_BUTTONS)
      return false;
    return _buttons[button];
  }

  Input(Input const &) = delete;
  void operator=(Input const &) = delete;
  static void key_callback(GLFWwindow *window, int key, int scancode,
                           int action, int mods) {
    handleKeyCallback(key, scancode, action, mods);
  }

  static void mouse_callback(GLFWwindow *window, int button, int action,
                             int mods) {
    handleMouseCallback(button, action, mods);
  }

  static void cursor_pos_callback(GLFWwindow *window, double xpos,
                                  double ypos) {
    handleCursorCallback(xpos, ypos);
  }
};

} // namespace input
} // namespace engine