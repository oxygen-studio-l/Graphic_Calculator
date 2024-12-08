#include "Renderer.h"
#include <vector>
#include <cmath>
#include <string>


void Renderer::setClearColor(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
}

void Renderer::clear() {
    glEnable(GL_BLEND); // 启用混合
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // 设置混合函数
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::drawArrays(GLenum mode, GLint first, GLsizei count) {
    glDrawArrays(mode, first, count);
}

void Renderer::drawRectangle(float x, float y, float width, float height, const float* color) {
    float vertices[] = {
        x,     y,      0.0f, // Bottom-left corner
        x + width, y,  0.0f, // Bottom-right corner
        x + width, y + height, 0.0f, // Top-right corner
        x,     y + height, 0.0f  // Top-left corner
    };

    float colors[] = {
        color[0], color[1], color[2], color[3],
        color[0], color[1], color[2], color[3],
        color[0], color[1], color[2], color[3],
        color[0], color[1], color[2], color[3]
    };

    unsigned int indices[] = {
        0, 1, 2,  // First triangle
        2, 3, 0   // Second triangle
    };

    // Create and bind VAO
    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Create and bind VBO for vertices
    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Set up vertex attribute pointers for positions
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Create and bind VBO for colors
    unsigned int cbo;
    glGenBuffers(1, &cbo);
    glBindBuffer(GL_ARRAY_BUFFER, cbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

    // Set up vertex attribute pointers for colors
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);

    // Create and bind EBO
    unsigned int ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Draw the rectangle
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    // Clean up
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &cbo);
    glDeleteBuffers(1, &ebo);
    glDeleteVertexArrays(1, &vao);
}

void Renderer::drawLine(const float startX, const float startY, const float endX, const float endY, const float* color) {
    float vertices[] = {
        startX, startY, 0.0f,
        endX,   endY,   0.0f
    };

    float colors[] = {
        color[0], color[1], color[2], color[3],
        color[0], color[1], color[2], color[3]
    };

    // Create and bind VAO
    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Create and bind VBO for vertices
    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Set up vertex attribute pointers for positions
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Create and bind VBO for colors
    unsigned int cbo;
    glGenBuffers(1, &cbo);
    glBindBuffer(GL_ARRAY_BUFFER, cbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

    // Set up vertex attribute pointers for colors
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);

    // Draw the line
    glDrawArrays(GL_LINES, 0, 2);

    // Clean up
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &cbo);
    glDeleteVertexArrays(1, &vao);
}



void Renderer::drawPoint(float x, float y, const float* color) {
    // Define the vertex (point) data
    float vertices[] = {
        x, y, 0.0f
    };

    // Define the color data for the point
    float colors[] = {
        color[0], color[1], color[2], color[3]
    };

    // Create and bind VAO
    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Create and bind VBO for vertices
    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Set up vertex attribute pointers for positions
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Create and bind VBO for colors
    unsigned int cbo;
    glGenBuffers(1, &cbo);
    glBindBuffer(GL_ARRAY_BUFFER, cbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

    // Set up vertex attribute pointers for colors
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);

    // Optionally set the point size
    glPointSize(5.0f); // 设置点的大小

    // Draw the point
    glDrawArrays(GL_POINTS, 0, 1);

    // Clean up
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &cbo);
    glDeleteVertexArrays(1, &vao);
}

