#include <iostream>
#include <Windows.h>
#include <conio.h>

/*Only people that like Hatsune Miku can use this Code*/

using namespace std;


int chooseClicks();
void clearKeyboardBuffer();

int cps;

int main() {
    chooseClicks();


    while (true) {
        Sleep(50);

        if (GetAsyncKeyState(VK_NUMPAD0)) {
            return 0;
        }

        if (GetAsyncKeyState(VK_NUMPAD1)) {

            while (true) {
                Sleep(cps);
                INPUT key = { 0 };
                key.type = INPUT_MOUSE;
                key.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
                SendInput(1, &key, sizeof(key));
                ZeroMemory(&key, sizeof(key));

                key.type = INPUT_MOUSE;
                key.mi.dwFlags = MOUSEEVENTF_LEFTUP;
                SendInput(1, &key, sizeof(key));
                if (GetAsyncKeyState(VK_NUMPAD2)) {
                    break;
                }
                if (GetAsyncKeyState(VK_NUMPAD3)) {
                    chooseClicks();
                }
            }

        }
        if (GetAsyncKeyState(VK_NUMPAD3)) {
            chooseClicks();
        }

    }
}

int chooseClicks() {
    clearKeyboardBuffer();
    system("CLS");

    cout << "Press Numpad 0 to close, Numpad 1 to start the autoclicker, press Numpad 2 to stop it and Numpad 3 to choose other cps" << endl;
    cout << endl << endl << "How many clicks per second do you want?: ";
    cin.clear();
    cin >> cps;

    if (cps <= 0) {
        cps = 1;
    }
    cps = 1000 / cps;
    return 0;
}

void clearKeyboardBuffer()
{
    while (_kbhit())
    {
        _getche();
    }
}