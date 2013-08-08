#ifndef MOON_GFX_H
#define MOON_GFX_H

#include "moon.hxx"

namespace Moon {
  struct Rect {
    GLfloat x;
    GLfloat y;
    GLfloat w;
    GLfloat h;
  };

  struct vec2 {
    GLfloat x;
    GLfloat y;
  };

  struct uvMap {
    GLfloat u;
    GLfloat v;
  };

  struct Color {
    GLfloat r;
    GLfloat g;
    GLfloat b;
    GLfloat a;
  };

  struct vertex {
    vec2  pos;
    uvMap tex_coord;
    Color color;
  };
}
#endif