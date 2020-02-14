#include <iostream>
#include <fstream>
#include <conio.h>
#include "Caesar.h"
using namespace std;
#define CLEAR system("cls")
#define PAUSE system("pause")

bool UnknownCommand(char act, string list)
{
	for (auto c : list)
	{
		if (c == act)
			return false;
	}
	return true;
}

void CaesarCipher(string file)
{
	CLEAR;
	char act;
	Caesar caesarCipher;
	while (true)
	{
		cout << "ШИФР ЦЕЗАРЯ" << endl
			<< "1. Зашифровка текста из файла Text.txt" << endl
			<< "2. Расшифровка текста из файла EncryptedCaesar.txt" << endl
			<< "0. Главное меню" << endl << endl;
		do
		{
			act = _getch();
			switch (act)
			{
				case '1':
					cout << caesarCipher.Encrypted(file) << endl;
					PAUSE;
					CLEAR;
					break;
				case '2':
					cout << caesarCipher.Decrypted() << endl;
					PAUSE;
					CLEAR;
					break;
				case '0': return;
				default: cout << "Unknown command . . ." << endl; break;
			}
		} while (UnknownCommand(act, "120"));
	}
	PAUSE;
}
void VigenereCipher(string file)
{
	PAUSE;
}
void PlayfirCipher(string file)
{
	PAUSE;
}
void HillCipher(string file)
{
	PAUSE;
}

int main()
{
	setlocale(0, "rus");
	string file = "Text.txt";
	char act;

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
		do
		{
			act = _getch();
			switch (act)
			{
				case '1': CaesarCipher(file);	CLEAR; break;
				case '2': VigenereCipher(file); CLEAR; break;
				case '3': PlayfirCipher(file);	CLEAR; break;
				case '4': HillCipher(file);		CLEAR; break;
				case '0': return EXIT_SUCCESS;
				default: cout << "Unknown command . . ." << endl; break;
			}
		} while (UnknownCommand(act, "12340"));
	}
}