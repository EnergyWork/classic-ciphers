#include <iostream>
#include <conio.h>
#include "Caesar.h"
#include "Vigenere.h"
#include "Playfir.h"
#include "Hill.h"
using namespace std;
#define CLEAR system("cls")
#define PAUSE system("pause")
#define endcase PAUSE; CLEAR; break;

bool UnknownCommand(char act, string list)
{
	for (auto c : list)
		if (c == act)
			return false;
	return true;
}

void CaesarCipher(string file)
{
	CLEAR;
	char act;
	int tmpOffset;
	Caesar caesarCipher;
	string tmp;
	while (true)
	{
		cout << "   ШИФР ЦЕЗАРЯ" << endl
			<< "1. Зашифровка текста из файла Text.txt" << endl
			<< "2. Расшифровка текста из файла EncryptedCaesar.txt" << endl
			<< "3. Изменить смещение" << endl
			<< "0. Главное меню" << endl << endl;
		do
		{
			act = _getch();
			switch (act)
			{
			case '1':
				cout << caesarCipher.Encrypted(file) << endl << endl;
				cout << "Энтропия" << endl
					<< "Исходый текст: " << caesarCipher.GetTextEntropy() << endl
					<< "Зашифрованный текст: " << caesarCipher.GetEncEntropy() << endl;
				endcase;
			case '2':
				cout << caesarCipher.Decrypted() << endl;
				endcase;
			case '3':
				cout << "Введите новое смещение: ";
				cin >> tmpOffset;
				caesarCipher.SetOffset(tmpOffset);
				cout << "Смещение изменено: " << endl << endl;
				endcase;
			case '0': return;
			default: cout << "Unknown command . . ." << endl; break;
			}
		} while (UnknownCommand(act, "1230"));
	}
}
void VigenereCipher(string file)
{
	CLEAR;
	char act;
	string newKey;
	Vigenere vigenereCipher;
	while (true)
	{
		cout << "   ШИФР ВИЖЕНЕРА" << endl
			<< "1. Зашифровка текста из файла Text.txt" << endl
			<< "2. Расшифровка текста из файла EncryptedVigenere.txt" << endl
			<< "3. Изменить ключ шифрования" << endl
			<< "0. Главное меню" << endl << endl;
		do
		{
			act = _getch();
			switch (act)
			{
			case '1':
				cout << vigenereCipher.Encrypted(file) << endl;
				cout << "Энтропия" << endl
					<< "Исходый текст: " << vigenereCipher.GetTextEntropy() << endl
					<< "Зашифрованный текст: " << vigenereCipher.GetEncEntropy() << endl;
				endcase;
			case '2':
				cout << vigenereCipher.Decrypted() << endl;
				endcase;
			case '3':
				cout << "Введите новый ключ шифрования: ";
				cin >> newKey;
				vigenereCipher.SetKey(newKey);
				cout << "Ключ обновлен!" << endl << endl;
				endcase;
			case '0': return;
			default: cout << "Unknown command . . ." << endl; break;
			}
		} while (UnknownCommand(act, "1230"));
	}
}
void PlayfirCipher(string file)
{
	CLEAR;
	char act;
	string newKey;
	Playfir playfirCipher;
	while (true)
	{
		cout << "   ШИФР ПЛЕЙФИРА" << endl
			<< "1. Зашифровка текста из файла Text.txt" << endl
			<< "2. Расшифровка текста из файла EncryptedPlayfir.txt" << endl
			//<< "3. Изменить ключ шифрования" << endl
			<< "0. Главное меню" << endl << endl;
		do
		{
			act = _getch();
			switch (act)
			{
			case '1':
				cout << playfirCipher.Encrypted(file) << endl;
				cout << "Энтропия" << endl
					 << "Исходый текст: " << playfirCipher.GetTextEntropy() << endl
					 << "Зашифрованный текст: " << playfirCipher.GetEncEntropy() << endl;
				endcase;
			case '2':
				cout << playfirCipher.Decrypted() << endl;
				endcase;
			case '3':

				endcase;
			case '0': return;
			default: cout << "Unknown command . . ." << endl; break;
			}
		} while (UnknownCommand(act, "120"));
	}
}
void HillCipher(string file)
{

}

int main()
{
	setlocale(0, "rus");
	string file = "Text.txt";
	char act;

	while (true)
	{
		cout << "Выбирете метод шифрования: " << endl
			<< "-----------------------------" << endl
			<< "1. Шифр Цезаря" << endl
			<< "2. Шифр Виженера" << endl
			<< "3. Шифр Плейфера" << endl
			//<< "4. Шифр Хилла"					<< endl
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
				//case '4': HillCipher(file);		CLEAR; break;
			case '0': return EXIT_SUCCESS;
			default: cout << "Unknown command . . ." << endl; break;
			}
		} while (UnknownCommand(act, "1230"));
	}
}