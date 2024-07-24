#pragma once
#include "WordHashList.h"
#include "StopWatcher.h"

class WordTopList
{
	WordHashList * _list;
	Word * _orderList;
	int getIndex(wchar_t &);
	int getSize();
	StopWatcher _watcher;
public:
	WordTopList();
	void Print();
	void Order();
	void Merge(Word * a, int low, int mid, int high);
	void Merge_sort(Word * a, int low, int high);
	void Insert(wstring &);
	~WordTopList();
};

