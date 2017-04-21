//
//Project Name: FastFingersTest
//Author: Nguyen Ho Toan Thu
//Header.h
//

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <sstream>

using namespace std;

//Macro set text's colors
#define setTextColor() HANDLE Color; Color = GetStdHandle(STD_OUTPUT_HANDLE);
#define textColor(...) SetConsoleTextAttribute(Color, __VA_ARGS__);

//struct CorrectRate
struct CorrectRate
{
	int Correct = 0;
	int Total = 0;
};

//Goto x y
void gotoXY(int x, int y);

//Read string from file
string readFile(string FileName);

//Random filename
string ranDomFileName();

//Interface
void interfaceBox(string Para);

//clock
void clockOut(int);

//Main function
CorrectRate mainFunc(string);