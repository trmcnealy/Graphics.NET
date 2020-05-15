#pragma once
#include <string>
namespace glsl
{
    static const std::string chart_fs = R"shader(
#version 330

uniform vec4 color;

out vec4 outputColor;

void main(void)
{
   outputColor = color;
}
)shader";
}
