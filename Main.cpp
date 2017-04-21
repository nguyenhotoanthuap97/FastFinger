//
//Project Name: FastFingersTest
//Author: Nguyen Ho Toan Thu
//Main.cpp
//

#include "Header.h"

//Main
void main()
{
	CorrectRate P;
	int id = -1;
	string FileName;
	string Para;

	gotoXY(32, 10);
	cout << "FAST FINGERS TEST";
	gotoXY(25, 11);
	cout << "Nhan 1 de bat dau. 0 de thoat";
	fflush(stdin);
	id = getch();
	if (!kbhit())
	{
		while (id != 48 && id != 49)
		{
			id = getch();
		}
		if (id == 49)
		{
			FileName = ranDomFileName();
			Para = readFile(FileName);
			interfaceBox(Para);
			P = mainFunc(Para);
			if (P.Correct >= 0)
			{
				gotoXY(35, 10);
				cout << "                  ";
				gotoXY(30, 10);
				cout << "Errors: " << P.Total - P.Correct;
				gotoXY(30, 11);
				cout << "Total words typed: " << P.Total;
				gotoXY(30, 12);
				cout << "Correct rate: " << P.Correct * 100.0 / P.Total << "%";
				gotoXY(30, 13);
				cout << "Speed: " << P.Correct;
				gotoXY(30, 15);
				cout << "Nhan phim bat ky de thoat...";
				fflush(stdin);
				getch();
			}
		}
	}
	gotoXY(25, 20);
}