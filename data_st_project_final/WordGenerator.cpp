#include "WordGenerator.h"

WordGenerator::WordGenerator()
{
	_word = L"";//L"" kullanılıyor çünkü: nvarchar (wchar)dan dolayı.-ekstra bilgi: 8 bit yerine 16 bit yer kaplıyor.- 
}

wstring WordGenerator::getWord()
{
	wstring temp = _word;
	_word = L"";
	return temp;
}

bool WordGenerator::Create(wchar_t _letter)//kelime oluşturma detayları.
{
	if (_letter == ' ' || _letter == '\n')
		return !_word.empty();
	if (_letter == '\'')
	{
		if (!_word.empty())// empty basitçe stringin boş olup olmadığını kontrol ediyor, değilse ekleme işlemini gerçekleştiriyor
			_word += _letter;//
	}
	else
		_word += _letter;

	return false;
}

wchar_t WordGenerator::CheckPunctuationMarks(wchar_t _letter)//büyük küçük kontrolü, okunan her 'harf' için
{
	if ((_letter >= 'A' && _letter <= 'Z') || (_letter >= 'a' && _letter <= 'z') || (_letter >= '0' && _letter <= '9'))//herbir harf ve sayı
		return tolower(_letter);//tamamını lower case yapıyoruz.
	if (_letter == '\'')
		return _letter;
	return ' ';
}

WordGenerator::~WordGenerator()//destructor
{
}