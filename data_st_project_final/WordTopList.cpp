#include "WordTopList.h"


int WordTopList::getIndex(wchar_t& letter)
{
	letter = tolower(letter);//stringin tamamýný küçük harfe çeviriyoruz.
	if (letter <= 'z' && letter >= 'a')
		return letter % 97;//ascii to string
	return 29;
}

int WordTopList::getSize()// her bir wordhashlistin sizeýný toplayarak totalsize'ý buluyoruz.
{
	int totalSize = 0;
	for (size_t i = 0; i < 30; i++)
		totalSize += _list[i].getSize();
	return totalSize;
}

WordTopList::WordTopList()//constr.
{
	_list = new WordHashList[30];
	_watcher = StopWatcher();//for timer
}

void WordTopList::Print()
{
	//int size = getSize();
	wstring output = L"";

	for (size_t i = 0; i < 10; i++)//i deðiþtirilerek basýlacak kelime sayýsý da deðiþtirilebilir. size yaparak bütün sayýlarý da basabiliriz.
		output += _orderList[i].Print();

	wprintf(L"%ls \n", output.c_str());//%ls: wide char stringi stdout'a çevirerek yazdýrmayý saðlýyor.

	wprintf(L"\nAll actions take %d second %d millisecond passed.\n", _watcher.getCurrentTimeSecond(), _watcher.getCurrentTimeRest());
}

void WordTopList::Order()
{
	int size = getSize();
	_orderList = new Word[size];
	int index = 0;
	for (size_t i = 0; i < 30; i++)
	{
		auto temp = _list[i];
		auto tempSeri = temp.getSeries();
		int size2 = temp.getSize();
		for (size_t j = 0; j < size2; j++)
		{
			_orderList[index] = tempSeri[j];
			index += 1;
		}
	}

	Merge_sort(_orderList, 0, size - 1);
}

void WordTopList::Merge(Word  * merge_list, int low, int mid, int max)//(alttaki fonksiyonda)klasik recursive mergesort algoritmasý kullandýk. pivot olarak middle elementi alýp iþlemleri gerçekleþtirdik.
{
	auto _tempList = new Word[max + 1 - low];
	int _lowIndex, _index, j, k;
	_lowIndex = low;
	_index = 0;
	j = mid + 1;

	while ((_lowIndex <= mid) && (j <= max))
	{
		if (merge_list[_lowIndex].Size() >= merge_list[j].Size())
		{
			_tempList[_index] = merge_list[_lowIndex];
			_lowIndex++;
		}
		else
		{
			_tempList[_index] = merge_list[j];
			j++;
		}
		_index++;
	}

	if (_lowIndex > mid)
	{
		for (k = j; k <= max; k++)
		{
			_tempList[_index] = merge_list[k];
			_index++;
		}
	}
	else
	{
		for (k = _lowIndex; k <= mid; k++)
		{
			_tempList[_index] = merge_list[k];
			_index++;
		}
	}

	for (k = 0; k <= max - low; k++)
	{
		merge_list[k + low] = _tempList[k];
	}
	delete[] _tempList;
}

void WordTopList::Merge_sort(Word * a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		Merge_sort(a, mid + 1, high);
		Merge_sort(a, low, mid);
		Merge(a, low, mid, high);
	}
}

void WordTopList::Insert(wstring& word)
{
	_list[getIndex(word[0])].Insert(word);

}

WordTopList::~WordTopList()
{
}
