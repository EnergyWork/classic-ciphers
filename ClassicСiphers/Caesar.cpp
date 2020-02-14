#include "Caesar.h"

size_t Caesar::index(char a)
{
	for (size_t i = 0; i < alphabet.size(); i++)
	{
		if (alphabet[i] == a)
			return i;
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
string Caesar::Encrypted(string text)
{
	ofstream out("EncryptedCaesar.txt", std::ios::app);
	int loop;
	transform(text.begin(), text.end(), text.begin(), tolower);
	for (size_t letter = 0; letter < text.size(); letter++)
	{
		loop = 0;
		if (index(text[letter]) + GetOffset() >= alphabet.size())
			loop = alphabet.size();
		encText += alphabet[index(text[letter]) + GetOffset() - loop];
	}
	out << encText << endl;
	return encText;
}
string Caesar::Decrypted()
{

	return "NULL";
}