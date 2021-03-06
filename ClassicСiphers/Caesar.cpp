#include "Caesar.h"

int Caesar::index(char a)
{
	for (size_t letter = 0; letter < alphabet.size(); letter++)
	{
		if (alphabet[letter] == a)
			return letter;
	}
	return NULL;
}
void Caesar::SetOffset(int offset)
{
	this->offset = offset;
}
int Caesar::GetOffset()
{
	return offset;
}
void Caesar::ReadFile(string& text, string file)
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
string Caesar::Encrypted(string file)
{
	ReadFile(text, file);
	textEntropy = ent.EntropyCalculation(text);
	encText.clear();
	int loop;
	transform(text.begin(), text.end(), text.begin(), tolower);
	for (size_t letter = 0; letter < text.size(); letter++)
	{
		loop = 0;
		if (index(text[letter]) + GetOffset() >= alphabet.size())
			loop = alphabet.size();
		encText += alphabet[index(text[letter]) + GetOffset() - loop];
	}
	encEntropy = ent.EntropyCalculation(encText);
	ofstream out(encFile);
	out << encText;
	out.close();
	return encText;
}
string Caesar::Decrypted()
{
	ReadFile(text, encFile);
	if (text.empty())
		return "EncryptedCaesar.txt is empty . . .";
	int loop;
	transform(text.begin(), text.end(), text.begin(), tolower);
	for (size_t letter = 0; letter < text.size(); letter++)
	{
		loop = 0;
		if (index(text[letter]) - GetOffset() < 0)
			loop = alphabet.size();
		decText += alphabet[index(text[letter]) - GetOffset() + loop];
	}
	ofstream out(decFile);
	out << decText;
	out.close();
	return decText;
}