//
//Project Name: FastFingersTest
//Author: Nguyen Ho Toan Thu
//Function.cpp
//

#include "Header.h"

//Goto x y
void gotoXY(int x, int y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };
	SetConsoleCursorPosition(hStdout, position);
}

//Read string from file
string readFile(string FileName)
{
	ifstream f;
	string Para;
	f.open(FileName);
	if (!f.fail())
	{
		getline(f, Para);
		f.close();
		return Para;
	}
	else cout << "Fail to read file" << endl;
	return Para;
}

//Random FileName
string ranDomFileName()
{
	string FileName = "Para";
	int id = 0;
	srand(time(NULL));
	id = rand() % 10;
	switch (id)
	{
	case 0: FileName += "01.txt";
		break;
	case 1: FileName += "02.txt";
		break;
	case 2: FileName += "03.txt";
		break;
	case 3: FileName += "04.txt";
		break;
	case 4: FileName += "05.txt";
		break;
	case 5: FileName += "06.txt";
		break;
	case 6: FileName += "07.txt";
		break;
	case 7: FileName += "08.txt";
		break;
	case 8: FileName += "09.txt";
		break;
	case 9: FileName += "10.txt";
		break;
	}
	return FileName;
}

//Interface
void interfaceBox(string Para)
{
	setTextColor();
	int x, y;
	stringstream ss;
	string FirstWord;
	x = 10, y = 4;
	gotoXY(x - 9, y + 1);
	cout << "Type in:";
	gotoXY(x, y);
	cout << (char)201;
	for (int i = 11; i < 65; i++)
		cout << (char)205;
	cout << (char)187;
	gotoXY(x, y + 1);
	cout << (char) 186 << "                                                      " << (char)186;
	gotoXY(x, y + 2);
	cout << (char)200;
	for (int i = 11; i < 65; i++)
		cout << (char)205;
	cout << (char)188;
	gotoXY(0, y + 6);
	
	textColor(8);
	cout << Para;
	
	ss.str(Para);
	getline(ss, FirstWord, ' ');

	gotoXY(0, y + 6);
	textColor(15);
	cout << FirstWord;
	gotoXY(0, y + 20);
}

//Clock
void clockOut(int start)
{
	int x, y;
	x = 15;
	y = 8;
	if (clock() / 1000 > 50)
	{
		gotoXY(x + 15, y);
		cout << " ";
	}
	if (clock() / 1000 <= 60)
	{
		gotoXY(x + 14, y);
		cout << (int)(60 + start - clock() / 1000);
	}
}

//Main function
CorrectRate mainFunc(string Para)
{
	setTextColor();
	CorrectRate Player;
	int buffer = -1;
	string Word;
	string Typein;
	string temp;
	stringstream ss;
	int nParaWord = 1;
	int x = 0, y = 10, xs = x, ys = y, nhap = 11;
	
	for (int i = 0; i < Para.size(); i++)
	{
		if (Para[i] == ' ')
			nParaWord++;
	}

	ss.str(Para);

	////Clock
	gotoXY(15, 8);
	cout << "Remaing time: ";

	clock_t start = clock() / 1000;
	
	while (60 + start - clock() / 1000 >= 0 && buffer != 27 && Player.Total < nParaWord)
	{
		//Tach chu
		getline(ss, Word, ' ');
		
		////Clock
		textColor(15);
		clockOut(start);

		gotoXY(x, y);
		textColor(15);
		cout << Word;
		x += Word.size() + 1;
		if (x > 79)
		{
			x = x - 80;
			y++;
		}

		//xoa o input
		gotoXY(11, 5);
		cout << "                                                      ";
		nhap = 11;

		Typein.clear();

		//Input
		while (buffer != ' ' || buffer != 27)
		{
			
			fflush(stdin);
			if (buffer != 224)
			{
				buffer = getch();
				////Clock
				textColor(15);
				clockOut(start);
			}
			else
			{
				buffer = -1;
				getch();
				////Clock
				textColor(15);
				clockOut(start);
				continue;
			}
			if (!kbhit())
			{
				
				if (buffer == 8 && Typein.length() > 0)
				{
					nhap--;
					gotoXY(nhap, 5);
					cout << ' ';
					Typein.pop_back();
					continue;
				}
				if (buffer == 8 && Typein.length() == 0)
					continue;
				if (buffer == ' ' || buffer == 13 || 60 + start - clock() / 1000 < 0)
					break;
				if (buffer == 27)
				{
					Player.Correct = -1;
					return Player;
				}
				if (((buffer >= 'A' && buffer <= 'Z') || (buffer >= 'a' && buffer <= 'z') || buffer == '~' || buffer == '`' || buffer == '!' || buffer == '@' || buffer == '#' || buffer == '$' || buffer == '%' || buffer == '^' || buffer == '&' || buffer == '*' || buffer == '(' || buffer == ')' || buffer == '-' || buffer == '_' || buffer == '=' || buffer == '+' || (buffer >= 0 && buffer <= 9) || buffer == '{' || buffer == '}' || buffer == '[' || buffer == ']' || buffer == '|' || buffer == '\\' || buffer == ';' || buffer == ':' || buffer == '\"' || buffer == '\'' || buffer == ',' || buffer == '<' || buffer == '.' || buffer == '>' || buffer == '/' || buffer == '?') && nhap < 64)
				{
					gotoXY(nhap, 5);
					temp = (char)buffer;
					cout << temp;
					Typein += temp;
					nhap++;
					continue;
				}
				else continue;
			}
		}
		(Player.Total)++;
		if (Typein == Word)
		{
			gotoXY(xs, ys);
			textColor(10);
			cout << Word;
			(Player.Correct)++;
			xs = x;
			ys = y;
		}
		else
		{
			gotoXY(xs, ys);
			textColor(12);
			cout << Word;
			xs = x;
			ys = y;
		}	
	}
	system("cls");
	gotoXY(35, 10);
	textColor(15);
	cout << "Time up!!!";
	Sleep(1000);
	return Player;
}

//Color:
// 10 : green
// 12 : red
// 15 : white
// 8  : grey

//x <= 79
//box x <= 64