#pragma once
#include "Headers.h"
#include "Word.h"
#include "StopWatcher.h"

class WordsList
{
private:
	int _size, _maxSize;
	Word * _list;
	Word * First();
	Word * End();
	StopWatcher _watcher;
public:
	WordsList(int maxSize = 1000000);//ilk ba�ta kafadan bir de�er vererek wordslistimizi olu�turuyoruz. genellikle kullan�lacak dosyalar�n boyutuna ba�l� olarak daha b�y�k veya daha k���k bir de�er yazabiliriz.
	void Insert(wstring &);
	void Print();
	void Expand();
	void Swap(Word*, Word*);
	~WordsList(void);
};

