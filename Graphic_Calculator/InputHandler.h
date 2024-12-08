#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>


// ����ȫ�ֱ���
extern bool rightMousePressed;
extern float lastX, lastY;
extern glm::vec2 translation;
extern float OE_ZOOM;


// ��갴ť�ص�����
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

// ���λ�ûص�����
void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);

// �ӿڴ�С�ı�Ļص�����
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// �����ֻص�����
void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);

#endif // CALLBACKS_H