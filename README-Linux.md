Upgraded Keylogger :keyboard: :lock:

Welcome to the upgraded version of a basic keylogger program, crafted meticulously in C++. This enhanced keylogger captures all keystrokes made on the target computer and secures them using a simple XOR cipher. The encrypted data is then inconspicuously stored in a file, tucked away in a hidden location.
Requirements :clipboard:

To run the upgraded keylogger, you need the following:

    A computer running Windows (Windows 7 or later) or Linux
    A C++ compiler (such as Visual Studio or MinGW for Windows, and g++ for Linux)
    The windows.h header file for Windows or the linux/input.h and fcntl.h header files for Linux

Usage :gear:

To deploy the upgraded keylogger, follow these steps:

    Compile the upgraded_keylogger.c file using your preferred C++ compiler. For example, if you're using MinGW on Windows, you can run the following command in the terminal:

bash

i686-w64-mingw32-g++ upgraded_keylogger.c -o keylogger-upgraded.exe

For Linux users, you can use the g++ compiler:

bash

g++ upgraded_keylogger.c -o keylogger-upgraded

    Once the program is compiled, run the keylogger-upgraded.exe file on the target computer for Windows or ./keylogger-upgraded for Linux.

The keylogger will spring into action, capturing all keystrokes made on the computer, including passwords and other sensitive information. The captured data will be encrypted and stored in a harmless-looking file in a hidden location.

To halt the keylogger, press Ctrl + C in the terminal where the program is running.
Disclaimer :warning:

This keylogger is intended for educational purposes only. Use of this keylogger without the explicit consent of the target computer owner is illegal and unethical. The author of this keylogger takes no responsibility for any damages or harm caused by the use or misuse of this program. Please use responsibly.
