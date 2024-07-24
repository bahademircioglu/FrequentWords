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
	WordsList(int maxSize = 1000000);//ilk baþta kafadan bir deðer vererek wordslistimizi oluþturuyoruz. genellikle kullanýlacak dosyalarýn boyutuna baðlý olarak daha büyük veya daha küçük bir deðer yazabiliriz.
	void Insert(wstring &);
	void Print();
	void Expand();
	void Swap(Word*, Word*);
	~WordsList(void);
};

