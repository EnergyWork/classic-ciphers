#pragma once
#include <vector>
#include <string>
#include <fstream>
using namespace std;

typedef pair<int, int> Pair;

class Playfir
{
	vector<string> cipherMatr;
	string text, encText, decText;
	pair<int, int> index(char a);
	string encFile = "EncryptedPlayfir.txt", decFile = "DecryptedPlayfir.txt";
	void ReadFile(string& text, string file);
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