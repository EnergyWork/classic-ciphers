#pragma once
#include <fstream>
using namespace std;

class Vigenere //A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
{
	string alphabet;
	string key;
	string text, encText, decText;
	int index(char a);
	string encFile, decFile;
public:
	Vigenere()
	{
		alphabet = "abcdefghijklmnopqrstuvwxyz";
		key = "artyom";
		encFile = "EncryptedVigenere.txt";
		decFile = "DecryptedVigenere.txt";
	}
	string Encrypted(string file);
	string Decrypted();
	void SetKey(string newKey);
	string GetKey();
	void ReadFile(string &text, string file);
};