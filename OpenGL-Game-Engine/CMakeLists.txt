# Gather all engine source files
file(GLOB_RECURSE ENGINE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp")

# Define the Engine as a STATIC library
add_library(OpenGL-Game-Engine STATIC ${ENGINE_SOURCES})

target_compile_definitions(OpenGL-Game-Engine PUBLIC GLM_ENABLE_EXPERIMENTAL)

# Tell the Engine where its own headers are, AND where the Dependencies are.
# Using 'PUBLIC' means that any project (like ExampleGame) that links to this 
# engine will automatically inherit these include directories too!
target_include_directories(OpenGL-Game-Engine PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/Source"
    "${CMAKE_SOURCE_DIR}/Dependencies"
)

# Link the system-wide Linux libraries.
# Again, using 'PUBLIC' ensures ExampleGame inherits these dependencies automatically.
target_link_libraries(OpenGL-Game-Engine PUBLIC
    GL          
    GLEW        
    glut        
    glfw        
    freeimage   
    m           
)