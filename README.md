<div align="center">

# SFML Game Development — Code Base

《SFML Game Development》一书配套的完整示例代码 ・ Complete source code for the book *SFML Game Development*

**[简体中文](#lang-zh)** &nbsp;|&nbsp; **[English](#lang-en)**

</div>

---

<a id="lang-zh"></a>

## 简体中文

本文说明如何构建《SFML Game Development》一书附带的代码。

仓库中包含 10 个章节目录（`01_Intro` ～ `10_Network`），分别对应书中的每一章。例如 `02_Resources` 是第 2 章的代码。所有章节既可以一次性全部构建，也可以分别单独构建。

### 章节索引

| 目录 | 章节 | 主题 |
| --- | --- | --- |
| `01_Intro` | 第 1 章 | 引言：第一个窗口 |
| `02_Resources` | 第 2 章 | 资源管理与场景图 |
| `03_World` | 第 3 章 | 世界、视图与滚动 |
| `04_Input` | 第 4 章 | 输入与命令队列 |
| `05_States` | 第 5 章 | 状态栈 |
| `06_Menus` | 第 6 章 | 菜单与 GUI 组件 |
| `07_Gameplay` | 第 7 章 | 游戏玩法（子弹、敌人等） |
| `08_Graphics` | 第 8 章 | 图形特效（粒子、泛光） |
| `09_Audio` | 第 9 章 | 音效与音乐 |
| `10_Network` | 第 10 章 | 网络对战 |

---

### 一、安装 CMake

安装 CMake，推荐使用图形界面版 CMake-GUI（<https://www.cmake.org>，Linux 下为 `cmake-gui` 包）。

### 二、安装 SFML

下载 SFML 3（<https://www.sfml-dev.org>）。推荐直接下载官方预编译版本。

也可以自行编译 SFML，但此时需确保它已经**安装**（执行 `make install`，或编译 `INSTALL` 项目）。更多细节请参阅官方在线教程。

最终你需要有一个目录，其中至少包含 `include` 和 `lib` 两个子目录，分别存放 SFML 库的头文件和二进制文件。例如 Windows 下的 `C:\SFML`，或 Linux 下的 `/usr/local`。

### 三、生成构建配置

1. 启动 `cmake-gui`。

2. 在 **Where is the source code** 一栏中，填入包含本 `README.md` 的目录路径。路径请使用正斜杠 `/`。

3. 在 **Where to build the binaries** 一栏中，填入另一个路径，用于存放生成的中间构建文件。

4. 点击 **Configure**，并选择你的编译器。

5. 此时可能会弹出“找不到 SFML”的错误提示，这是预期行为。在 `SFML_ROOT` 变量旁的输入框中填入 SFML 的路径即可，也就是第 2 步中提到的、包含 `lib` 和 `include` 子目录的那个目录（例如 `C:/SFML` 或 `/usr/local`）。

6. 将 `CMAKE_BUILD_TYPE` 设为 `Release` 或 `Debug` 来选择构建配置。推荐 `Release`（通常也是默认值）。

7. 在 Windows 上，如果希望静态链接 SFML，请勾选 `SFML_STATIC_LIBRARIES`；若希望动态链接并使用 DLL 文件，则保持不勾选。

8. 将 `CMAKE_INSTALL_PREFIX` 设为你希望存放示例程序可执行文件的路径。请选择一个不同的目录（也可以是当前目录的子目录）。

9. 再次点击 **Configure**，此时应该不会再出现任何错误提示。

10. 点击 **Generate**。

### 四、编译代码

1. 切换到构建目录，即第 3 步中 **Where to build the binaries** 填入的路径。

2. 此时目录中应该已经生成了编译所需的文件。

   - 使用 g++ 或 clang 时，你会得到一个 `Makefile`。在终端中执行 `make install`。
   - 若在 Windows 上使用 MinGW，可能需要改用 `mingw32-make install`。
   - 使用 Visual Studio 时，会得到一个 `.sln` 解决方案。打开它，选择正确的构建配置（`Release` 或 `Debug`），然后构建 `INSTALL` 项目。
   - 使用其他 IDE 时方式类似：编译 `INSTALL` 项目即可。

3. 编译完成后，可执行文件和媒体文件会输出到 `CMAKE_INSTALL_PREFIX` 指定的目录。

### 五、运行结果

每个章节的可执行文件都位于安装目录（`CMAKE_INSTALL_PREFIX`）中。

如果想直接阅读代码，当前目录下的 10 个子目录分别包含对应章节的源文件与头文件，每个章节的媒体资源也一并放在各自的目录中。

---

<a id="lang-en"></a>

## English

This file explains how to build the code accompanying the book *SFML Game Development*.

There are 10 directories that correspond to each of the chapters in the book (`01_Intro` through `10_Network`). For example, `02_Resources` contains the code for Chapter 2. The code for all chapters can be built at once, or each chapter individually.

### Chapter Index

| Directory | Chapter | Topic |
| --- | --- | --- |
| `01_Intro` | Chapter 1 | Introduction: the first window |
| `02_Resources` | Chapter 2 | Resource management and the scene graph |
| `03_World` | Chapter 3 | World, views and scrolling |
| `04_Input` | Chapter 4 | Input and the command queue |
| `05_States` | Chapter 5 | The state stack |
| `06_Menus` | Chapter 6 | Menus and GUI widgets |
| `07_Gameplay` | Chapter 7 | Gameplay (projectiles, enemies, …) |
| `08_Graphics` | Chapter 8 | Visual effects (particles, bloom) |
| `09_Audio` | Chapter 9 | Sound effects and music |
| `10_Network` | Chapter 10 | Networked multiplayer |

---

### I. Install CMake

Install CMake, preferably CMake-GUI (<https://www.cmake.org>, or the `cmake-gui` package on Linux).

### II. Install SFML

Download SFML 3 (<https://www.sfml-dev.org>). We recommend using a precompiled version of SFML, which can be downloaded directly.

It is also possible to build SFML yourself; in that case make sure that it is *installed* (`make install`, or compile the `INSTALL` project). Refer to the online tutorials for more details.

Eventually, you should have a directory with at least the subdirectories `include` and `lib` that contain the headers and binaries of the SFML library — for example `C:\SFML` on Windows, or `/usr/local` on Linux.

### III. Generate the build configuration

1. Start `cmake-gui`.

2. In the field **Where is the source code**, enter the path of the directory containing this `README.md` file. Use forward slashes.

3. In the field **Where to build the binaries**, enter a different path, where you want the intermediate build files of the book's code to be generated.

4. Click **Configure** and choose your compiler.

5. Afterwards, an error message might appear, telling that SFML was not found. This is intended. To fix it, enter the path to SFML in the field next to the `SFML_ROOT` variable. This is the directory mentioned in step II, with the `lib` and `include` subdirectories (e.g. `C:/SFML` or `/usr/local`).

6. Choose your build configuration by setting `CMAKE_BUILD_TYPE` to either `Release` or `Debug`. We recommend `Release` (it should be the default).

7. On Windows, check the box next to `SFML_STATIC_LIBRARIES` if you want to link SFML statically. Leave it unchecked if you prefer linking SFML dynamically and using DLL files.

8. Set `CMAKE_INSTALL_PREFIX` to the path where you want the executables of the book's code to be installed. Choose a different directory (it can be a subdirectory of this one).

9. Click **Configure** again. Now there should be no more error messages.

10. Click **Generate**.

### IV. Compile the code

1. Switch to the build directory (the one you entered in **Where to build the binaries**).

2. Now you should see the files required to compile the code.

   - For g++ or clang, this will be a `Makefile`. In the terminal, type `make install`.
   - If you use MinGW on Windows, you might have to type `mingw32-make install` instead.
   - For Visual Studio, you will see a `.sln` solution. Open it, choose the correct build configuration (`Release` or `Debug`) and build the `INSTALL` project.
   - For other integrated development environments, it will be similar: compile the `INSTALL` project.

3. After compiling, the executables and media files should be output to the directory you specified with `CMAKE_INSTALL_PREFIX`.

### V. Results

The executables for each chapter are located in the install directory (`CMAKE_INSTALL_PREFIX`).

If you would like to inspect the code itself, the current directory comes with 10 subdirectories, each containing the source and header files of the corresponding chapter. The media files can also be found in each chapter's directory.

---

<div align="center">

**[ 返回顶部 / Back to top](#sfml-game-development--code-base)**

</div>
