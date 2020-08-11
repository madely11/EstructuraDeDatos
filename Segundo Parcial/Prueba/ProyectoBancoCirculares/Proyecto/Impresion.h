#pragma once
#include <windows.h> 
#include <fstream> 
#include <string> 
#include <iostream> 
using namespace std;

typedef std::basic_ifstream<TCHAR> tifstream;
typedef std::basic_string<TCHAR> tstring;

class Impresion
{
public:
	void PrintFile(tifstream&);
	void ShowInformation(tstring);
	void ShowError(tstring);
	void Outtextxy(HDC, int, int, tstring);
};

