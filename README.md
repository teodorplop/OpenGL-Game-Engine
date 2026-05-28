# OpenGL-Game-Engine

A 3D game engine built with OpenGL and C++17. Designed with a component-based architecture inspired by Unity3D, this engine provides core rendering, physics, and scene management features for building interactive 3D applications.

## Features

* 3D math module using GLM
* Input handling (mouse and keyboard)
* Meshes, materials, shaders & textures
* .obj format importer
* Scene management with hierarchical organization of objects in XML files
* Component system: GameObject, Transform, Camera, MeshRenderer and custom scripts
* Engine compiled as static library, scripting done with C++
* Basic collision detection using Cube Colliders

---

## Prerequisites & Dependencies

To compile and run this project on Linux, you will need a C++17 compliant compiler (`gcc` or `clang`), `cmake`, and the following development libraries:

* **OpenGL** (Core Graphics Drivers)
* **GLEW** (Extension Wrangler)
* **GLFW** (Windowing & Input)
* **FreeGLUT** (Utility Toolkit)
* **FreeImage** (Image Loading)
* **GLM** (OpenGL Mathematics)

### Dependency Installation

#### CachyOS / Arch Linux

```bash
# Install core build tools and standard libraries
sudo pacman -S base-devel cmake glew glfw freeglut glm

# Install FreeImage from the AUR (Do NOT run with sudo)
paru -S freeimage
# OR:
yay -S freeimage
```

#### Ubuntu / Debian

```bash
sudo apt update
sudo apt install build-essential cmake libglew-dev libglfw3-dev freeglut3-dev libfreeimage-dev libglm-dev
```

---

## Building the Project

You can build the project either directly through the terminal or by using Visual Studio Code.

### Method 1: Via Terminal (Standard CMake)

From the project root directory, run the following commands to configure and compile:

```bash
# Create and enter the build directory
mkdir build && cd build

# Configure the project
cmake -DCMAKE_BUILD_TYPE=Debug ..

# Compile the executable
make
```

### Method 2: Via VS Code (Recommended)

1. Open the project folder in VS Code.

2. Install the following extensions:
   - **C/C++** (by Microsoft)
   - **CMake Tools** (by Microsoft)

3. Open the Command Palette (`Ctrl + Shift + P`) and run **CMake: Select a Kit**. Choose your native host compiler (e.g., GCC or Clang).

4. Run **CMake: Configure**.

5. Click the **Build** button on the bottom blue status bar (or press `F7`).

---

## Running the Application

### Important Platform Constraints

1. **Working Directory**: The application loads assets (Shaders, Textures, Scenes) using relative paths. The executable must be run from the build directory where assets are automatically copied.

2. **Wayland Display Server**: If you are running a Wayland-based desktop (default on many modern Linux distributions), GLEW requires an X11 context to initialize properly. You must pass the `GLFW_PLATFORM=x11` environment variable to force XWayland compatibility.

### Running via Terminal

```bash
# From the project root folder
cd build/ExampleGame

# Launch the app forcing X11 context compatibility
GLFW_PLATFORM=x11 ./ExampleGame
```

### Running via VS Code (Automated Setup)

To make clicking the Play **[▷]** button in VS Code work seamlessly, create or update `.vscode/settings.json` in your project root with the following configuration:

```json
{
    "cmake.debugConfig": {
        "environment": [
            {
                "name": "GLFW_PLATFORM",
                "value": "x11"
            }
        ]
    }
}
```

Once saved, clicking **Launch / Play** on the bottom status bar will properly handle display window contexts automatically.

---

## Usage

For details on how the engine should be used, check the **ExampleGame** folder which demonstrates:
* Scene loading from XML
* Custom component scripts
* Basic rendering and camera controls
* Collision detection examples