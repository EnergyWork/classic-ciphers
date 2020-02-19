#include "Playfir.h"

int Playfir::indexRow(char a, string str)
{
	for (size_t letter = 0; letter < str.size(); letter++)
	{
		if (str[letter] == a)
			return letter;
	}
	return NULL;
}
void Playfir::Analyze()
{
	bool flag = false;
	while (!flag)
	{
		for (size_t i = 0; i < text.size() - 1; i++)
		{
			if (text[i] == text[i + 1])
			{
				text.insert(text.begin() + i + 1, 'x');
			}	
		}
		flag = true;
		if (text.size() % 2 != 0)
		{
			text += 'x';
			flag = false;
		}
	}
}
void Playfir::ReadFile(string &text, string file)
{
	ifstream in(file);
	string tmp;
	text.clear();
	while (!in.eof())
	{
		in >> tmp;
		text += tmp;
	}
	in.close();
}
string Playfir::EncryptedPairLetters(char l, char r)
{

	return string();
}
string Playfir::Encrypted(string file)
{
	ReadFile(text, file);
	Analyze();
	for (size_t letter = 0; letter < text.size() - 1; letter++)
	{
		encText += EncryptedPairLetters(text[letter], text[letter + 1]);
	}
	return encText;
}
string Playfir::Decrypted()
{
	return string();
}