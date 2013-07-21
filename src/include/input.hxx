#ifndef MOON_INPUT_H
#define MOON_INPUT_H

#include "moon.hxx"
#include <cmath>

namespace Moon {

  struct Button {
  public:
    Button();
    Button(int button_id, char* name);
    int button_id;
    char* name;
    int state;
    int mods;  
  };

  typedef Button KeyboardKey;
  typedef Button MouseButton;

  typedef std::unordered_map<int, Button> ButtonMap;
  typedef ButtonMap KeyMap;

  class Input {
  public: 
    static void initialize(GLFWwindow* window);
    static void update_key(GLFWwindow* window, int key_id, int scancode, int action, int mods);
    static KeyboardKey* get_key(int key_id);
    static bool key_mod(int key_id, int mod);
    static bool key_state_is_eq(int key_id, int state);
    static bool key_state_is_eq_with_mod(int key_id, int state, int mod);

    class Mouse {
    public:
      static int x();
      static int y();
      static void update_button(GLFWwindow* window, int button_id, int action, int mods);
      static bool button_mod(int button_id, int mod);
      static bool button_state_is_eq(int button_id, int state);
      static bool button_state_is_eq_with_mod(int button_id, int state, int mod);
    };

  protected:
    static GLFWwindow* window; // the main engine window
    static KeyMap keyboard_keys;
    static ButtonMap mouse_buttons;

  friend void Moon::moon_mrb_input_init(mrb_state*); // give access to map key enums
  };
}

#endif