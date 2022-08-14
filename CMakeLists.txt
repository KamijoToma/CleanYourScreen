cmake_minimum_required(VERSION 3.23)
project(LearningOpenGL)

set(CMAKE_CXX_STANDARD 14)

# Add dependencies
include(FetchContent)
add_executable(LearningOpenGL main.cpp glad.c)
## GLFW
set(GLFW_USE_WAYLAND on)
FetchContent_Declare(
        GLFW
        GIT_REPOSITORY https://github.com/glfw/glfw
        GIT_TAG 7482de6071d21db77a7236155da44c172a7f6c9e
)
FetchContent_MakeAvailable(GLFW)
target_link_libraries(LearningOpenGL PRIVATE glfw)
