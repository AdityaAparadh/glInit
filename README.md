# GL INIT

A set of wrapper classes around OpenGL Calls, for bootstrapping an OpenGL project. 
### ⚠️ (Work - In - Progress)

## Setup
You should be on a Unix-like system, and have CMake installed.

This code builds its own GLFW, along with GLAD extension loader. Make sure you install all GLFW dependencies listed [here](https://www.glfw.org/docs/latest/compile.html).


1. Clone this repository and change directory into it:

```bash
git clone https://github.com/AdityaAparadh/glInit && cd glInit
```

2. Create a new `build` directory to hold all your build files
```bash
mkdir build && cd build
```

3. Configure the project using :
```bash
cmake ..
```

4. Build the project:
```bash
cmake --build .
```

This will build the project with the defualt configuration, and create a `Graphics` executable binary file in the build directory.
