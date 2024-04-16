# Setting up naoqi SDKs on MacOS
Note: This guide is intended for ARM based macs but should apply to Intel x86 macs as well
### Table of Contents
-[C++ SDK Guide](#c-sdk-setup-on-macos) \
-[Python SDK Guide](#naoqi-python-27-sdk-setup) (recommended if you have never programmed with the Nao before) \
-[Connecting via Robot Settings](#robot-settings-installation) \
-[API Reference](#api-reference-page)

## C++ SDK Setup on MacOS 

### Environment Setup
1. Install CMake, I recommend installing using `brew install cmake` (*requires homebrew [https://brew.sh](https://brew.sh)*) to avoid path issues but you can manually install CMake from here as well: \
[http://www.cmake.org/cmake/resources/software.html](http://www.cmake.org/cmake/resources/software.html)
2. Install python `2.7.18` [here](https://www.python.org/downloads/release/python-2718/), we will need to create a virtual environment to ensure qibuild functions properly
3. Create an empty folder ex: /path/to/myWorktree and `cd` into your worktree directory
4. Now create a virtual environment using python 2.7.18:
```
virtualenv -p /Library/Frameworks/Python.framework/Versions/2.7/bin/python2.7 venv_py2.7
``` 
*Note that you should also be able to use `/usr/local/bin/python` as your python`2.7.18` path

5. Activate your virtual environment using: 
```
source venv_py2.7/bin/activate
``` 
type `python --version` you should see 2.7.18

6. Install qibuild using `pip install qibuild`
7. Run `qibuild config --wizard` if this errors restart your terminal
    1. Cmake should be found automatically, if not specify the path
    2. For Cmake generator specify **Unix Makefiles**
    3. Dont specify an IDE, completely unecessary
8. Run `qibuild init` the folder should remain empty

### C++ SDK and Toolchain Linking
*the following requires you to have created a worktree folder as per previous section*
1. Download the C++ SDK from [https://developer.softbankrobotics.com/nao6/downloads/nao6-downloads-mac](https://www.aldebaran.com/en/support/nao-6/downloads-softwares)
2. extract the folder and rename to **naoqi-sdk** 
   1. Create a new directory `NAO6-I` and copy `naoqi-sdk` into it
   2. You should have `/path/to/NAO6-I/naoqi-sdk` this is the path you will use to link the SDK
3. execute the following command to create a toolchain from the C++ SDK:
```
qitoolchain create mytoolchain /path/to/naoqi-sdk/toolchain.xml
```

4. cd into your worktree `/path/to/myWorktree` (if not already there)
5. Add your toolchain to your config using: 
```
qibuild add-config myconfig -t mytoolchain --default
```

6. Lastly run `qibuild configure`

### Confirm Setup
Follow this tutorial to make sure everything was configured correctly: \
[c-sdk-hello-world-step-step](http://doc.aldebaran.com/2-8/dev/cpp/helloworld_auto.html)

### Executable Permissions
Once you have compiled your first program you may run into a permission error on macos when trying to run it, \
in order to fix this you must disable Gatekeeper. Please make sure you know what you are doing prior to executing this command. \
`sudo spctl --master-disable` \
Of course when you are finished working with the NAO it is recommended to re-enable Gatekeeper: \
`sudo spctl --master-enable`

## NAOqi Python 2.7 SDK Setup
1. Download python 2.7 here: [https://www.python.org/downloads/release/python-2718/](https://www.python.org/downloads/release/python-2718/)
    1. Make sure to use Python from /usr/local/bin/python, not /usr/bin/python
2. Download the python SDK here: [https://www.aldebaran.com/en/support/nao-6/downloads-softwares](https://www.aldebaran.com/en/support/nao-6/downloads-softwares)
3. Add the following to your zshrc or bash_profile (if you dont know which you are using use zshrc) replace the paths with your actual path to the sdk:
   ```
   export PYTHONPATH=${PYTHONPATH}:/path/to/python-sdk/lib/python2.7/site-packages
   export QI_SDK_PREFIX=/path/to/python-sdk
    ```
4. (Optional but I cannot recommend it enough) Create a virtual environment
   ```
   virtualenv -p /Library/Frameworks/Python.framework/Versions/2.7/bin/python2.7 venv_py2.7
    ```
   *Note that you should also be able to use /usr/local/bin/python as your python`2.7.18` path \
   \
   And activate your virtual environment using:
    ```
    source venv_py2.7/bin/activate
    ```
6. To confirm setup:
    1. `python` && `import naoqi`
    2. If there are no errors you're done!

## Robot Settings Installation
In order to connect to the NAO6 robot we need to install robot settings \
Download the application here and follow the GUI steps to install: \
[https://community-static.aldebaran.com/resources/2.8.5/robot-settings-2.8.5.10-mac64-setup.dmg](https://community-static.aldebaran.com/resources/2.8.5/robot-settings-2.8.5.10-mac64-setup.dmg) \
The official download link does not work, this is the ONLY version that works on ARM-macs

## API Reference Page
Refer to the api page to get started (*note: most examples are written in python*) \
When searching for documentation ensure that your are looking at naoqi version `2.8` \
[http://doc.aldebaran.com/2-8/dev/libqi/api/cpp/index.html](http://doc.aldebaran.com/2-8/dev/libqi/api/cpp/index.html)
