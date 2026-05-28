# Manually include the root main.cpp and recurse into Scripts
file(GLOB_RECURSE SCRIPT_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/Assets/Scripts/*.cpp")

# Combine them into one list
set(GAME_SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp" 
    ${SCRIPT_SOURCES}
)

add_executable(ExampleGame ${GAME_SOURCES})

# CRITICAL FOR VSCODE: Copy the Assets folder to the build directory.
# In VSCode, the executable runs from the 'build/ExampleGame/' folder. 
# This command ensures your Assets sit right next to the compiled executable.
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/Assets" 
    DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

# Add the Engine as a dependency and force full inclusion of all symbols
target_link_libraries(ExampleGame PRIVATE 
    "-Wl,--whole-archive" 
    OpenGL-Game-Engine 
    "-Wl,--no-whole-archive"
)

# Keep your include directories
target_include_directories(ExampleGame PRIVATE 
    "${CMAKE_SOURCE_DIR}/OpenGL-Game-Engine/Source"
)