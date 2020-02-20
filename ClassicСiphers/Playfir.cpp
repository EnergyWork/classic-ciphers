#include "Playfir.h"

Pair Playfir::index(char a)
{
	for (size_t row = 0; row < cipherMatr.size(); row++)
	{
		for (size_t letter = 0; letter < cipherMatr[row].size(); letter++)
		{
			if (cipherMatr[row][letter] == a)
				return make_pair(row, letter);
		}
	}
	return make_pair(NULL, NULL);
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
void Playfir::ReadFile(string& text, string file)
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
	Pair indL = index(l), indR = index(r);
	string encText;
	if (indL.first == indR.first) // если в одно строке
	{
		if (indL.second >= cipherMatr[indL.first].size() - 1)
			encText += cipherMatr[indL.first][0];
		else
			encText += cipherMatr[indL.first][indL.second + 1];

		if (indR.second >= cipherMatr[indR.first].size() - 1)
			encText += cipherMatr[indR.first][0];
		else
			encText += cipherMatr[indR.first][indR.second + 1];
	}
	else if (indL.second == indR.second) // если в одном столбце
	{
		if (indL.first >= cipherMatr.size() - 1)
			encText += cipherMatr[0][indL.second];
		else
			encText += cipherMatr[indL.first + 1][indL.second];

		if (indR.first >= cipherMatr.size() - 1)
			encText += cipherMatr[0][indR.second];
		else
			encText += cipherMatr[indR.first + 1][indR.second];
	}
	else // если в разных столбцах и строках 
	{
		encText += cipherMatr[indL.first][indR.second];
		encText += cipherMatr[indR.first][indL.second];
	}
	ofstream out(encFile);
	out << encText;
	out.close();
	return encText;
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