cmake_minimum_required(VERSION 3.15)
project(MyGameEnvironment CXX)

# Force C++17 standard globally
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optional: Add your preprocessor flag if still needed
add_compile_definitions(_CRT_SECURE_NO_WARNINGS)

# Tell CMake to process the Engine first, then the Game
add_subdirectory(OpenGL-Game-Engine)
add_subdirectory(ExampleGame)