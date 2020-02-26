#include "Playfir.h"

Pair Playfir::index(char a)
{
	for (size_t row = 0; row < cipherMatr.size(); row++)
		for (size_t letter = 0; letter < cipherMatr[row].size(); letter++)
			if (cipherMatr[row][letter] == a)
				return make_pair(row, letter);
	return make_pair(NULL, NULL);
}
void Playfir::AnalyzeEnc()
{
	bool flag = false;
	while (!flag)
	{
		for (size_t i = 0; i < text.size() - 1; i++)
			if (text[i] == text[i + 1])
				text.insert(text.begin() + i + 1, 'x');
			else if (text[i] == 'j')
				text[i] = 'i';
			else continue;
		flag = true;
		if (text.size() % 2 != 0)
		{
			text += 'x';
			flag = false;
		}
	}
}
void Playfir::AnalyzeDec()
{
	for (size_t i = 1; i < decText.size() - 1; i++)
		if (decText[i - 1] == decText[i + 1] && decText[i] == 'x')
			decText.erase(decText.begin() + i);
}
void Playfir::Analyze(int target)
{
	switch (target)
	{
		case ENCRYPTED: AnalyzeEnc(); break;
		case DECRYPTED: AnalyzeDec(); break;
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
void Playfir::WriteFile(string text, string file)
{
	ofstream out(file);
	out << text;
	out.close();
}
void Playfir::EncryptedPairLetters(char l, char r)
{
	Pair indL = index(l), indR = index(r);
	if (indL.first == indR.first) // если в одно строке
	{
		// шифр левой
		if (indL.second >= cipherMatr[indL.first].size() - 1)
			encText += cipherMatr[indL.first][0];
		else
			encText += cipherMatr[indL.first][indL.second + 1];
		//шифр правой
		if (indR.second >= cipherMatr[indR.first].size() - 1)
			encText += cipherMatr[indR.first][0];
		else
			encText += cipherMatr[indR.first][indR.second + 1];
	}
	else if (indL.second == indR.second) // если в одном столбце
	{
		//шифр левой
		if (indL.first >= cipherMatr.size() - 1)
			encText += cipherMatr[0][indL.second];
		else
			encText += cipherMatr[indL.first + 1][indL.second];
		//шифр правой
		if (indR.first >= cipherMatr.size() - 1)
			encText += cipherMatr[0][indR.second];
		else
			encText += cipherMatr[indR.first + 1][indR.second];
	}
	else // если в разных столбцах и строках
	{
		encText += cipherMatr[indL.first][indR.second]; //левой
		encText += cipherMatr[indR.first][indL.second]; //правой
	}
	return;
}
string Playfir::Encrypted(string file)
{
	ReadFile(text, file);
	textEntropy = ent.EntropyCalculation(text);
	encText.clear();
	Analyze(ENCRYPTED);
	for (size_t letter = 0; letter < text.size() - 1; letter += 2)
		EncryptedPairLetters(text[letter], text[letter + 1]);
	encEntropy = ent.EntropyCalculation(encText);
	WriteFile(encText, encFile);
	return encText;
}
void Playfir::DecryptedPairLetters(char l, char r)
{
	Pair indL = index(l), indR = index(r);
	if (indL.first == indR.first) // если в одно строке
	{
		//расшифр левой
		if (indL.second == 0)
			decText += cipherMatr[indL.first][cipherMatr[indL.first].size() - 1];
		else
			decText += cipherMatr[indL.first][indL.second - 1];
		//расшифр правой
		if (indR.second == 0)
			decText += cipherMatr[indR.first][cipherMatr[indL.first].size() - 1];
		else
			decText += cipherMatr[indR.first][indR.second - 1];
	}
	else if (indL.second == indR.second) // если в одном столбце TODO
	{
		//расшифр левой
		if (indL.first == 0)
			decText += cipherMatr[cipherMatr.size() - 1][indL.second];
		else
			decText += cipherMatr[indL.first - 1][indL.second];
		//шифр правой
		if (indR.first == 0)
			decText += cipherMatr[cipherMatr.size() - 1][indR.second];
		else
			decText += cipherMatr[indR.first - 1][indR.second];
	}
	else //если в разных столбцах и строках
	{
		decText += cipherMatr[indL.first][indR.second]; //расшифр правой
		decText += cipherMatr[indR.first][indL.second]; //расшифр левой
	}
	return;
}
string Playfir::Decrypted()
{
	ReadFile(text, encFile);
	decText.clear();
	for (size_t letter = 0; letter < text.size() - 1; letter += 2)
		DecryptedPairLetters(text[letter], text[letter + 1]);
	Analyze(DECRYPTED);
	WriteFile(decText, decFile);
	return decText;
}