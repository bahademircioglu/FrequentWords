#include "WordGenerator.h"

WordGenerator::WordGenerator()
{
	_word = L"";//L"" kullan�l�yor ��nk�: nvarchar (wchar)dan dolay�.-ekstra bilgi: 8 bit yerine 16 bit yer kapl�yor.- 
}

wstring WordGenerator::getWord()
{
	wstring temp = _word;
	_word = L"";
	return temp;
}

bool WordGenerator::Create(wchar_t _letter)//kelime olu�turma detaylar�.
{
	if (_letter == ' ' || _letter == '\n')
		return !_word.empty();
	if (_letter == '\'')
	{
		if (!_word.empty())// empty basit�e stringin bo� olup olmad���n� kontrol ediyor, de�ilse ekleme i�lemini ger�ekle�tiriyor
			_word += _letter;//
	}
	else
		_word += _letter;

	return false;
}

wchar_t WordGenerator::CheckPunctuationMarks(wchar_t _letter)//b�y�k k���k kontrol�, okunan her 'harf' i�in
{
	if ((_letter >= 'A' && _letter <= 'Z') || (_letter >= 'a' && _letter <= 'z') || (_letter >= '0' && _letter <= '9'))//herbir harf ve say�
		return tolower(_letter);//tamam�n� lower case yap�yoruz.
	if (_letter == '\'')
		return _letter;
	return ' ';
}

WordGenerator::~WordGenerator()//destructor
{
}