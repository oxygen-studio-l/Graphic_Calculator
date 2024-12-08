#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <cmath>
#include "ResourcePool.h"
#include "math.h"

class Renderer {

   
public:

    void setClearColor(float r, float g, float b, float a);
    void clear();

    void drawPoint(float x, float y, const float* color);
   
    void drawArrays(GLenum mode, GLint first, GLsizei count);
    void drawRectangle(float x, float y, float width, float height, const float* color);

    void drawLine(const float startX, const float startY, const float endX, const float endY, const float* color);
   

    

};

#endif // RENDERER_H

