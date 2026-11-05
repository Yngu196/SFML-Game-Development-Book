#####################
SFML Game Development
Code Base
#####################

This file explains how to build the code accompanying the book SFML Game Development.
此文件解释如何构建《SFML Game Development》一书附带的代码。
There are 10 directories that correspond to each of the chapters in the book. For example, 02_Resources contains the code for Chapter 2. The code for all chapters can be built at once.
这里有10个部分(01_Intro~10_Network)，分别对应于书中的每一章。例如，02_Resources包含第2章的代码。每个章节的代码都可以单独构建。

================
I. Install CMake
================
Install CMake, preferably CMake-GUI (www.cmake.org or the cmake-gui package in Linux).
安装CMake，最好是CMake-gui （www.cmake.org或Linux中的CMake-gui包）。

================
II. Install SFML
================
Download SFML 3 (www.sfml-dev.org). We recommend using a precompiled version of SFML which can be directly downloaded. 
下载SFML 3 （www.sfml-dev.org）。我们推荐使用可直接下载的SFML预编译版本。
It is also possible to build SFML yourself, in this case make sure that it is *installed* (make install, or compile the INSTALL project). Refer to the online tutorials for more details.
如果您自己构建SFML，请确保已*安装*SFML（执行install或编译install项目）。详情请参阅在线教程。
Eventually, you should have a directory with at least the subdirectories "include" and "lib" that contain headers and binaries of the SFML library, for example C:\SFML in Windows or /usr/local in Linux.
最后，您需要有一个目录，其中至少有包含SFML库的头文件和二进制文件的子目录：“include”和“lib”，例如Windows中的C:\SFML或Linux中的/usr/local。

=====================================
III. Generate the build configuration
=====================================
1. Start cmake-gui.
   启动 cmake-gui。

2. In the field "Where is the source code", enter the path of the directory containing this ReadMe.txt file. Use forward slashes.
   在“Where is the source code”一栏中，填入包含本 ReadMe.txt 文件的目录路径。路径请使用正斜杠。

3. In the field "Where to build the binaries", enter a different path, where you want the intermediate build files of the book's code to be generated.
   在“Where to build the binaries”一栏中，填入另一个路径，用于存放本书代码生成的中间构建文件。

4. Click "Configure" and choose your compiler.
   点击“Configure”，并选择你的编译器。

5. After, an error message might appear, telling that SFML is not found. This is intended. In order to fix it, enter the path to SFML in the field next to the SFML_ROOT variable. This is the directory mentioned in step II with the "lib" and "include" subdirectories (e.g. C:/SFML or /usr/local).
   之后可能会弹出“找不到 SFML”的错误提示，这是预期行为。要解决它，请在 SFML_ROOT 变量旁的输入框中填入 SFML 的路径。也就是第 II 步中提到的、包含“lib”和“include”子目录的那个目录（例如 C:/SFML 或 /usr/local）。

6. Choose your build configuration by setting CMAKE_BUILD_TYPE to either "Release" or "Debug". We recommend "Release" (it should be the default).
   通过将 CMAKE_BUILD_TYPE 设为“Release”或“Debug”来选择构建配置。我们推荐“Release”（它通常也是默认值）。

7. In Windows, check the box next to SFML_STATIC_LIBRARIES if you want to link SFML statically. Leave it unchecked if you prefer linking SFML dynamically and using DLL files.
   在 Windows 上，如果你希望静态链接 SFML，请勾选 SFML_STATIC_LIBRARIES 旁的复选框；如果你更希望动态链接并使用 DLL 文件，则保持不勾选。

8. Set the CMAKE_INSTALL_PREFIX to the path where you want the executables of the book's code to be installed. Choose a different directory (it can be a subdirectory of this one).
   将 CMAKE_INSTALL_PREFIX 设为你希望安装本书代码可执行文件的路径。请选择一个不同的目录（它可以是当前目录的子目录）。

9. Click again "Configure". Now, there should be no more error messages.
   再次点击“Configure”。此时不应再出现任何错误提示。

10. Click "Generate".
    点击“Generate”。


====================
IV. Compile the code
====================
1. Switch to the build directory (the one you entered in "Where to build the binaries").
   切换到构建目录（即你在“构建二进制文件的位置”中填入的那个路径）。

2. Now you should see the files required to compile the code. 
   现在你应该能看到编译代码所需的文件。

   For g++ or clang, this will be a Makefile. In the terminal, type "make install".
   对于 g++ 或 clang，这会是一个 Makefile。在终端中输入“make install”。
   If you use MinGW on Windows, you might have to type "mingw32-make install" instead.
   如果你在 Windows 上使用 MinGW，可能需要改为输入“mingw32-make install”。

   For Visual Studio, you will see a .sln solution. Open it, choose the correct build configuration ("Release" or "Debug") and build the INSTALL project.
   对于 Visual Studio，你会看到一个 .sln 解决方案。打开它，选择正确的构建配置（“Release”或“Debug”），然后构建 INSTALL 项目。
   
   For other integrated development environments, it will be similar. Compile the INSTALL project.
   对于其他集成开发环境，方式类似：编译 INSTALL 项目即可。

3. After compiling, the executables and media files should be output to the directory you specified with CMAKE_INSTALL_PREFIX.
   编译完成后，可执行文件和媒体文件应该会输出到你用 CMAKE_INSTALL_PREFIX 指定的目录。


==========
V. Results
==========
The executables for each chapter are located in the install directory (CMAKE_INSTALL_PREFIX).
每个章节的可执行文件都位于安装目录（CMAKE_INSTALL_PREFIX）中。

If you like to inspect the code itself, the current directory comes with 10 subdirectories, each containing the source and header files of the corresponding chapter. Also, the media files can be found for each chapter.
如果你想直接查看代码本身，当前目录下带有 10 个子目录，每个都包含对应章节的源文件和头文件。同时，每个章节的媒体文件也能在各自的目录中找到。
