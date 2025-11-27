# Qt GUI sample

This repository contains a minimal Qt Widgets application written in C++ and helper scripts to build it both on Windows and Linux.

## Requirements

- Qt 5.15+ or Qt 6 (Widgets module) installed and discoverable by CMake. Set `QT_PREFIX_PATH` if CMake cannot auto-detect Qt.
- CMake 3.16+
- A compiler toolchain supported by Qt (MSVC + Ninja/Visual Studio on Windows, GCC/Clang + Ninja/Make on Linux)

## Project structure

- `src/main.cpp` – Qt Widgets sample showing a simple window with a button.
- `CMakeLists.txt` – shared CMake build definition.
- `build_windows.ps1` – PowerShell helper for Windows builds.
- `build_linux.sh` – Bash helper for Linux builds.

## Building on Linux

```bash
chmod +x build_linux.sh
./build_linux.sh
./build_linux.sh build-linux-debug Debug   # optional custom dir + config
```

The script defaults to Ninja; export `CMAKE_GENERATOR` or `QT_PREFIX_PATH` to override defaults. Executables are placed inside the chosen build directory.

## Building on Windows

```powershell
pwsh ./build_windows.ps1
pwsh ./build_windows.ps1 -BuildDir build-nmake -Generator "NMake Makefiles"
```

Run the script from a Qt-enabled developer prompt (for example “x64 Native Tools Command Prompt for VS” after running `qtenv2.bat`). Override `QT_PREFIX_PATH` if Qt is outside the default discovery path. The produced `QtGuiSample.exe` lives in the build directory.

## Running

After a successful build, launch the executable (`QtGuiSample` / `QtGuiSample.exe`). You should see a small window with a label and a button that pops up a message box when clicked.

## GitHub Actions builds

Pushing to `main` or opening a pull request automatically triggers `.github/workflows/build.yml`. The workflow installs Qt 6.6.3, builds the app on both `ubuntu-latest` and `windows-latest`, and uploads the resulting executables as workflow artifacts (`QtGuiSample-ubuntu-latest`, `QtGuiSample-windows-latest`). You can download those artifacts directly from the workflow run page on GitHub without setting up Qt locally.


