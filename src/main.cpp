#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

#include <iostream>

int main(int argc, const char** argv) {
  SPDLOG_INFO("Start program");
  if (!glfwInit()) {
    const char* description = nullptr;
    glfwGetError(&description);
    SPDLOG_ERROR("failed to initalize glfw: {}", description);
    return -1;
  }

  SPDLOG_INFO("Create glfw Window");
  auto window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME,
                                 nullptr, nullptr);
  if (!window) {
    SPDLOG_INFO("failed to create glfw window");
    glfwTerminate();
    return -1;
  }

  SPDLOG_INFO("Start main loop");
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}