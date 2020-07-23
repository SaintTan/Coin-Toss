#include "src/Preprocessing.cpp"

int main() {
	wchar_t addon[10] = L"\\..\\..";
	wchar_t filename[10] = L"\\..\\data";
	getFiles(*filename, *addon);
}