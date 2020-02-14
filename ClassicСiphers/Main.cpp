#include <iostream>
#include <fstream>
#include <conio.h>
#include "Caesar.h"
using namespace std;
#define CLEAR system("cls")
#define PAUSE system("pause")

void ReadFile(string &text, string file)
{
	ifstream in(file);
	string tmp;
	while (!in.eof())
	{
		in >> tmp;
		text += tmp;
	}
}

void CaesarCipher(string text)
{
	Caesar caesarCipher;
	cout << caesarCipher.Encrypted(text) << endl;
	//caesarCipher.Decrypted();
	PAUSE;
}
void VigenereCipher(string text)
{
	PAUSE;
}
void PlayfirCipher(string text)
{
	PAUSE;
}
void HillCipher(string text)
{
	PAUSE;
}

int main()
{
	setlocale(0, "rus");
	string text;
	char act;
	ReadFile(text, "Text.txt");

	while (true)
	{
		cout << "-----------------------------" << endl
			<< "Выбирете метод шифрования: " << endl
			<< "1. Шифр Цезаря" << endl
			<< "2. Шифр Виженера" << endl
			<< "3. Шифр Плейфера" << endl
			<< "4. Шифр Хилла" << endl
			<< "-----------------------------" << endl
			<< "0. Выход" << endl;
		act = _getch();
		switch (act)
		{
			case '1': CaesarCipher(text);	CLEAR; break;
			case '2': VigenereCipher(text); CLEAR; break;
			case '3': PlayfirCipher(text);	CLEAR; break;
			case '4': HillCipher(text);		CLEAR; break;
			default: return EXIT_SUCCESS;
		}
	}
}