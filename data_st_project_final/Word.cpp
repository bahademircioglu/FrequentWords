#include "Word.h"


Word::Word(void)//1. constructor, boþ
{
	_frequency = 0;
	_word = L"";
}

Word::Word(wstring & word)//2. constructor, dolu, kelimeyi alýyor.
{
	_frequency = 1;
	_word = word;
}

bool Word::IsEqual(wstring & word)//ayný kelime mi kontrolü, aynýysa freqi 1 arttýrýp ayný döndürüyoruz, deðilse ayný dðeil-false döndürüyoruz.
{
	if (word != _word)
		return false;
	_frequency++;
	return true;

}

wstring Word::getWord() const 
{
	return _word;
}

int Word::Size() const//size=bir kelimenin frequencysi, totali
{
	return _frequency;
}

wstring Word::Print() const
{
	return to_wstring(_frequency) + L" " + _word + L"\n";//freq, kaç tane olduðunu ve kelimeyi yazdýrýyoruz.
}

Word::~Word(void)// destr
{
}
