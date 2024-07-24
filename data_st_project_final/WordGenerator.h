#pragma once
#include "Headers.h"
class WordGenerator
{
private:
	wstring _word;
public:
	WordGenerator(void);
	wstring getWord();
	bool Create(wchar_t _letter);
	wchar_t CheckPunctuationMarks(wchar_t _letter);
	~WordGenerator();
};

