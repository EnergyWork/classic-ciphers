#include <string>
#include <vector>
using namespace std;

struct LetterFreq
{
	char letter;
	double freq;
};

class Entropy
{
	vector<LetterFreq> LettersFreq;
	void InitAlphabet()
	{
		LettersFreq = {
				{ 'a', 0 }, { 'b', 0 }, { 'c', 0 },
				{ 'd', 0 }, { 'e', 0 }, { 'f', 0 },
				{ 'g', 0 }, { 'h', 0 }, { 'i', 0 },
				{ 'j', 0 }, { 'k', 0 }, { 'l', 0 },
				{ 'm', 0 }, { 'n', 0 }, { 'o', 0 },
				{ 'p', 0 }, { 'q', 0 }, { 'r', 0 },
				{ 's', 0 }, { 't', 0 },	{ 'u', 0 },
				{ 'v', 0 },	{ 'w', 0 },	{ 'x', 0 },
				{ 'y', 0 },	{ 'z', 0 }
		};
	}
public:
	Entropy()
	{
		InitAlphabet();
	}
	Entropy(string text)
	{
		InitAlphabet();
	}
	double EntropyCalculation(string text);
};
double Entropy::EntropyCalculation(string text)
{
	for (size_t i = 0; i < text.size(); i++)
		for (size_t j = 0; j < LettersFreq.size(); j++)
			if (text[i] == LettersFreq[j].letter)
				LettersFreq[j].freq++;
	for (size_t j = 0; j < LettersFreq.size(); j++)
		LettersFreq[j].freq /= LettersFreq.size();
	double entropy = 0;
	for (auto let : LettersFreq)
		entropy += let.freq * log2(let.freq);
	return entropy;
}