# ODE Integration Application

A high-performance C++ application for solving Ordinary Differential Equations (ODEs) numerically. Built using modern C++17/C++20 standards, managed via Conan 2.0, and driven by CMake Presets.

## Prerequisites

Ensure you have the following toolchains installed on your system:
* **CMake 3.23+** (or newer for Preset Version 4 schema support)
* **Conan 2.0+** (C++ package manager)
* **Ninja** or **Xcode** build tools

## Getting Started

Follow these steps to set up your local development environment.

### 1. Install Dependencies
Install the required third-party libraries and generate the local build infrastructure:
```bash
conan install . --profile=.conan/profiles/macos-debug --build=missing
```

### 2. Configure the Project
Initialize CMake and tie it to the Conan-generated toolchain using the debug preset:
```bash
cmake --preset conan-debug
```

### 3. Build the Application
Compile your code using incremental compilation (only modified files will recompile):
```bash
cmake --build --preset conan-debug
```

The compiled binary will be placed inside the `build/Debug/` directory.

## Editor Integration (Neovim / VS Code)

This repository includes a `.vscode/tasks.json` configuration. 
* **VS Code:** Press `Cmd+Shift+B` (macOS) or `Ctrl+Shift+B` (Linux/Windows) to run the default fast build.
* **Neovim:** If using `overseer.nvim`, run `:OverseerRun` to execute your build tasks straight from your text buffer.

## License

This project is licensed under the terms of the MIT License. See the [LICENSE](LICENSE) file for details.
