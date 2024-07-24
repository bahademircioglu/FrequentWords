#pragma once
#include "Word.h"

class WordHashList
{
private:
	int _size, _maxSize;
	Word * _list;
	Word * First();
	Word * End();
public:
	WordHashList();
	void Expand();
	int getSize();
	Word * getSeries();
	void Insert(wstring &);
	void Swap(Word*, Word*);
	~WordHashList();
};
