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
