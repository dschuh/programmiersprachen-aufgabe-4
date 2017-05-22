#include "color.hpp"

Color::Color():
r_{0.0f},
g_{0.0f},
b_{0.0f}
{}

Color::Color(float c):
r_{c},
g_{c},
b_{c}
{}

Color::Color(float r, float g, float b):
r_{r},
g_{g},
b_{b}
{}