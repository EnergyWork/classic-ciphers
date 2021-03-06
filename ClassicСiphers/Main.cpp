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
		cout << "   ���� ������" << endl
			<< "1. ���������� ������ �� ����� Text.txt" << endl
			<< "2. ����������� ������ �� ����� EncryptedCaesar.txt" << endl
			<< "3. �������� ��������" << endl
			<< "0. ������� ����" << endl << endl;
		do
		{
			act = _getch();
			switch (act)
			{
			case '1':
				cout << caesarCipher.Encrypted(file) << endl << endl;
				cout << "��������" << endl
					<< "������� �����: " << caesarCipher.GetTextEntropy() << endl
					<< "������������� �����: " << caesarCipher.GetEncEntropy() << endl;
				endcase;
			case '2':
				cout << caesarCipher.Decrypted() << endl;
				endcase;
			case '3':
				cout << "������� ����� ��������: ";
				cin >> tmpOffset;
				caesarCipher.SetOffset(tmpOffset);
				cout << "�������� ��������: " << endl << endl;
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
		cout << "   ���� ��������" << endl
			<< "1. ���������� ������ �� ����� Text.txt" << endl
			<< "2. ����������� ������ �� ����� EncryptedVigenere.txt" << endl
			<< "3. �������� ���� ����������" << endl
			<< "0. ������� ����" << endl << endl;
		do
		{
			act = _getch();
			switch (act)
			{
			case '1':
				cout << vigenereCipher.Encrypted(file) << endl;
				cout << "��������" << endl
					<< "������� �����: " << vigenereCipher.GetTextEntropy() << endl
					<< "������������� �����: " << vigenereCipher.GetEncEntropy() << endl;
				endcase;
			case '2':
				cout << vigenereCipher.Decrypted() << endl;
				endcase;
			case '3':
				cout << "������� ����� ���� ����������: ";
				cin >> newKey;
				vigenereCipher.SetKey(newKey);
				cout << "���� ��������!" << endl << endl;
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
		cout << "   ���� ��������" << endl
			<< "1. ���������� ������ �� ����� Text.txt" << endl
			<< "2. ����������� ������ �� ����� EncryptedPlayfir.txt" << endl
			//<< "3. �������� ���� ����������" << endl
			<< "0. ������� ����" << endl << endl;
		do
		{
			act = _getch();
			switch (act)
			{
			case '1':
				cout << playfirCipher.Encrypted(file) << endl;
				cout << "��������" << endl
					 << "������� �����: " << playfirCipher.GetTextEntropy() << endl
					 << "������������� �����: " << playfirCipher.GetEncEntropy() << endl;
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
		cout << "�������� ����� ����������: " << endl
			<< "-----------------------------" << endl
			<< "1. ���� ������" << endl
			<< "2. ���� ��������" << endl
			<< "3. ���� ��������" << endl
			//<< "4. ���� �����"					<< endl
			<< "-----------------------------" << endl
			<< "0. �����" << endl;
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