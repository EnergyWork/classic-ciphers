#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Entropy.h"
using namespace std;

class Caesar //A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
{
	string alphabet;
	string text, encText, decText;
	int offset;
	string encFile, decFile;
	double textEntropy, encEntropy;
	Entropy ent;
	int index(char a);
public:
	Caesar()
	{
		alphabet = "abcdefghijklmnopqrstuvwxyz";
		offset = 3;
		encFile = "EncryptedCaesar.txt";
		decFile = "DecryptedCaesar.txt";
	}
	void ReadFile(string& text, string file);
	void SetOffset(int offset);
	int GetOffset();
	string Encrypted(string text);
	string Decrypted();
	double GetTextEntropy() { return textEntropy; }
	double GetEncEntropy() { return encEntropy; };
};