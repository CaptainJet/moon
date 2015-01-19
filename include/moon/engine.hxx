#ifndef MOON_ENGINE_H
#define MOON_ENGINE_H

#include "moon/stdh.hxx"

#include "moon/window.hxx"
#include "moon/input.hxx"
#include "moon/audio.hxx"
#include "moon/fps.hxx"

#include "moon/mrb.hxx"

namespace Moon {
  enum run_status {
    RUN_STATUS_SUCESS,
    RUN_STATUS_EXCEPTION
  };

  class Engine {
  public:
    Engine();
    ~Engine();
    int run();

    bool load_mrb_file(const char *path);
    //void set_resource_path(const char *path);
  private:
    mrb_state *mrb;
    FPS fps;
    Window window;

    std::string resource_path;

    void load_mrb();

    void setup_opengl();
  };
};

void moon_load_user_scripts(Moon::Engine *engine);
void moon_config(Moon::Engine *engine);
void moon_step(mrb_state *mrb, double delta);
int moon_main(Moon::Engine *engine); // user entry point

#endif
