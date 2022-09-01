# NAO6-Research

## C++ SDK Setup on MacOS 
*simplified and corrected guide from https://developer.softbankrobotics.com/nao6/naoqi-developer-guide/sdks/c-sdk/c-sdk-installation-guide*
1. Install CMake, the documentation says install from here: http://www.cmake.org/cmake/resources/software.html
   but this creates path issues so use `brew install cmake` instead \
   *requires homebrew https://brew.sh/*
2. Check your python version using `python --version` should be 2.7
3. Install qibuild using `pip install qibuild --user`
4. Adding paths to ~/.bash_profile, `vi ~/.bash_profile` to edit then include these lines:\
  `export PATH="$HOME/Library/Python/2.7/bin:$PATH"`\
  `export PATH="/Applications/CMake.app/Contents/bin:$PATH"`
5. Run `qibuild config --wizard` if this errors restart your terminal and confirm that the paths are saved in your bash_profile
6. Cmake should be found automatically, if not specify the path
7. For Cmake generator specify **Unix Makefiles**
8. Dont specify an IDE, completely unecessary

## Initializing Worktree
1. Create an empty folder ex: /path/to/myWorktree
2. execute `qibuild init`
3. **NOTE: The folder should remain empty**

## NAOqi SDK Setup
*the following requires you to have created a worktree folder if not see above step*
1. Download the naoqi-sdk from https://developer.softbankrobotics.com/nao6/downloads/nao6-downloads-mac
2. extract the folder and rename to **naoqi-sdk** \
   ***Location of this folder does not matter*** 
3. execute `qitoolchain create mytoolchain /path/to/naoqi-sdk/toolchain.xml` to create a toolchain from the C++ SDK
4. cd into your worktree `/path/to/myWorktree`
5. execute `qibuild add-config myconfig -t mytoolchain --default`

## Confirm Setup
Follow this tutorial to make sure everything was configured correctly: \
https://developer.softbankrobotics.com/nao6/naoqi-developer-guide/sdks/c-sdk/c-sdk-hello-world-step-step

# ROBOT SETUP
## Robot Settings for MacOS
https://community-static.aldebaran.com/resources/2.8.5/robot-settings-2.8.5.10-mac64-setup.dmg (download on actual website doens't work so use this link which I found by making a deal with the documentation devil)
