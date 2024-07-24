#pragma once
#include "Headers.h"

class Word
{
private:
	int _frequency;
	wstring _word;
public:
	Word(void);
	Word(wstring&);
	bool IsEqual(wstring&);
	wstring Print() const;
	wstring getWord() const;
	int Size() const;

	~Word(void);
};

