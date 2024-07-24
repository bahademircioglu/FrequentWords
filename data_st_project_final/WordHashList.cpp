#include "WordHashList.h"


WordHashList::WordHashList()
{
	_maxSize = 10000;
	_size = 0;
	_list = new Word[_maxSize];
}


void WordHashList::Expand()//geniþletme iþlemi, doldukça listemizin boyutunu 2ye katlýyoruz.
{
	Word *start = First();
	Word *end = End();
	_maxSize *= 2;
	_list = new Word[_maxSize];

	auto *temp = _list;

	while (start != end)
		*temp++ = *start++;

}

int WordHashList::getSize()
{
	return _size;
}

Word* WordHashList::getSeries()
{
	return _list;
}

void WordHashList::Insert(wstring & word)
{

	auto current = First();
	auto last = End();
	while (current != last)
	{
		if (current->IsEqual(word))
		{
			auto pre = current - 1;

			while (pre != First())
			{
				if (pre->Size() >= current->Size())
				{
					Swap(current, pre + 1);
					return;
				}
				pre--;
			}

			Swap(current, First());
			return;
		}
		current++;
	}


	*last = Word(word);

	_size += 1;

	if (_size == _maxSize)
		Expand();


}


void WordHashList::Swap(Word* value1, Word* value2)
{
	auto temp = *value1;
	*value1 = *value2;
	*value2 = temp;
}

Word* WordHashList::First()
{
	return &_list[0];
}

Word* WordHashList::End()
{
	return &_list[_size];
}

WordHashList::~WordHashList()
{
}
