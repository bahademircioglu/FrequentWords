#include "Word.h"


Word::Word(void)//1. constructor, bo�
{
	_frequency = 0;
	_word = L"";
}

Word::Word(wstring & word)//2. constructor, dolu, kelimeyi al�yor.
{
	_frequency = 1;
	_word = word;
}

bool Word::IsEqual(wstring & word)//ayn� kelime mi kontrol�, ayn�ysa freqi 1 artt�r�p ayn� d�nd�r�yoruz, de�ilse ayn� d�eil-false d�nd�r�yoruz.
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
	return to_wstring(_frequency) + L" " + _word + L"\n";//freq, ka� tane oldu�unu ve kelimeyi yazd�r�yoruz.
}

Word::~Word(void)// destr
{
}
