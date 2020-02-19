#pragma once
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Playfir
{
	vector<string> cipherMatr;
	string text, encText, decText;
	int indexRow(char a, string str);
	void ReadFile(string &text, string file);
	string EncryptedPairLetters(char l, char r);
	void Analyze();
public:
	Playfir()
	{
		cipherMatr =
		{
			"playf",
			"irbcd",
			"eghkm",
			"noqst",
			"uvwxz"
		};
	}
	string Encrypted(string file);
	string Decrypted();
};