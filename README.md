# C++ SDK Setup on MacOS 

## CMake Environment Setup
*simplified and corrected guide from [https://developer.softbankrobotics.com/nao6/naoqi-developer-guide/sdks/c-sdk/c-sdk-installation-guide](http://doc.aldebaran.com/2-5/dev/cpp/index.html)*

1. Install CMake, I recommend installing using `brew install cmake` (*requires homebrew [https://brew.sh](https://brew.sh)*) to avoid path issues but you can manually install from here as well: [http://www.cmake.org/cmake/resources/software.html](http://www.cmake.org/cmake/resources/software.html)
2. Check your python install using `python --version`
3. Install qibuild using `pip install qibuild --user`
4. Run `qibuild config --wizard` if this errors restart your terminal
  1. Cmake should be found automatically, if not specify the path
  2. For Cmake generator specify **Unix Makefiles**
  3. Dont specify an IDE, completely unecessary

## Initializing Worktree
1. Create an empty folder ex: /path/to/myWorktree
2. execute `qibuild init`
3. **NOTE: The folder should remain empty**

## NAOqi C++ SDK Setup
*the following requires you to have created a worktree folder as per previous section*
1. Download the C++ SDK from [https://developer.softbankrobotics.com/nao6/downloads/nao6-downloads-mac](https://www.aldebaran.com/en/support/nao-6/downloads-softwares)
2. extract the folder and rename to **naoqi-sdk** \
   ***Location of this folder does not matter*** 
3. execute `qitoolchain create mytoolchain /path/to/naoqi-sdk/toolchain.xml` to create a toolchain from the C++ SDK
4. cd into your worktree `/path/to/myWorktree`
5. execute `qibuild add-config myconfig -t mytoolchain --default`
6. Ensure `unset DYLD_LIBRARY_PATH`

## Confirm Setup
Follow this tutorial to make sure everything was configured correctly: \
[https://developer.softbankrobotics.com/nao6/naoqi-developer-guide/sdks/c-sdk/c-sdk-hello-world-step-step](http://doc.aldebaran.com/2-5/dev/cpp/helloworld_auto.html)

# ROBOT SETUP
## Robot Settings for MacOS
Download the application here and follow the GUI steps to install: \
[https://community-static.aldebaran.com/resources/2.8.5/robot-settings-2.8.5.10-mac64-setup.dmg](https://community-static.aldebaran.com/resources/2.8.6/robot-settings-2.8.6.23-mac64-setup.dmg)

# Deploying Code
sadly not allowed\
`$ qibuild deploy <my_project> --url nao@nao.local:/home/nao/<my_project>`
