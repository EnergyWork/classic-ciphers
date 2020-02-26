#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Entropy.h"
using namespace std;
constexpr int ENCRYPTED = 0;
constexpr int DECRYPTED = 1;
typedef pair<int, int> Pair;

class Playfir
{
	vector<string> cipherMatr;
	string text, encText, decText;
	string encFile = "EncryptedPlayfir.txt", 
		   decFile = "DecryptedPlayfir.txt";
	double textEntropy, encEntropy;
	Entropy ent;
	Pair index(char a);
	void ReadFile(string& text, string file);
	void WriteFile(string text, string file);
	void EncryptedPairLetters(char l, char r);
	void DecryptedPairLetters(char l, char r);
	void AnalyzeEnc();
	void AnalyzeDec();
	void Analyze(int);
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
	double GetTextEntropy() { return textEntropy; }
	double GetEncEntropy() { return encEntropy; };
};