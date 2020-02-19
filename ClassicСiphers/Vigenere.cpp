#include "Vigenere.h"

int Vigenere::index(char a)
{
	for (size_t letter = 0; letter < alphabet.size(); letter++)
	{
		if (alphabet[letter] == a)
			return letter;
	}
	return NULL;
}
void Vigenere::ReadFile(string &text, string file)
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
void Vigenere::SetKey(string newKey)
{
	key = newKey;
}
string Vigenere::GetKey()
{
	return key;
}
string Vigenere::Encrypted(string file)
{
	ReadFile(text, file);
	int loop = 0;
	for (size_t letter = 0, l = 0; letter < text.size(); letter++, l++)
	{
		loop = 0;
		if (l >= key.size())
			l = 0;
		if (index(text[letter]) + index(key[l]) >= alphabet.size())
			loop = alphabet.size();
		encText += alphabet[index(text[letter]) + index(key[l]) - loop];
	}
	ofstream out(encFile);
	out << encText;
	out.close();
	return encText;
}
string Vigenere::Decrypted()
{
	ReadFile(text, encFile);
	if (text.empty())
		return "EncryptedVigenere.txt is empty . . .";
	int loop;
	for (size_t letter = 0, l = 0; letter < text.size(); letter++, l++)
	{
		loop = 0;
		if (l >= key.size())
			l = 0;
		if (index(text[letter]) - index(key[l]) < 0)
			loop = alphabet.size();
		decText += alphabet[index(text[letter]) - index(key[l]) + loop];
	}
	ofstream out(decFile);
	out << decText;
	out.close();
	return decText;
}
