#include <iostream>


#include "glad/glad.h"
#include <GLFW/glfw3.h>

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    cout << "Change the display resolution when you want to clean your monitor? Really?" << endl;
    glViewport(0, 0, width, height);
}

inline void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        cout << "Now enjoy your cleaner screen!" << endl;
        glfwSetWindowShouldClose(window, true);
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    auto pMonitor = glfwGetPrimaryMonitor();
    auto videoMode = glfwGetVideoMode(pMonitor);
    auto window = glfwCreateWindow(videoMode->width, videoMode->height, "Clean Your Screen", pMonitor, nullptr);
    if(window == nullptr){
        cerr << "Error creating GLFW Window!" << endl
            << "Do you really have a monitor to clean?" << endl;
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Seems that you need a gpu to clean your monitor first." << std::endl;
        glfwTerminate();
        return -1;
    }

    glViewport(0, 0, videoMode->width, videoMode->height);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

    // Clean now!
    while(!glfwWindowShouldClose(window)){
        processInput(window);
        glfwSwapBuffers(window);
        glfwPollEvents();

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    glfwTerminate();
    return 0;
}
