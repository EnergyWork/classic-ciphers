#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

class Caesar //A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
{
	string alphabet;
	string text, encText, decText;
	int offset;
	size_t index(char a);
public:
	Caesar()
	{
		alphabet = "abcdefghijklmnopqrstuvwxyz";
		offset = 3;
	}
	void SetOffset(int offset);
	int GetOffset();
	string Encrypted(string text);
	string Decrypted();
};