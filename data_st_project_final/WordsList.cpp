#include "WordsList.h"


Word* WordsList::First()//ilk kelime
{
	return &_list[0];
}

Word* WordsList::End()//son kelime
{
	return &_list[_size];
}

WordsList::WordsList(int maxSize)//constr.
{
	_maxSize = maxSize;
	_size = 0;
	_list = new Word[_maxSize];
	_watcher = StopWatcher();
}

void WordsList::Insert(wstring & word)// kelime ekleme
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


void WordsList::Swap(Word* value1, Word* value2)//basically swapping
{
	auto temp = *value1;
	*value1 = *value2;
	*value2 = temp;
}

void WordsList::Expand()//yeni bir word oluþturuyoruz(2 kat büyük). eski worddeki kelimeleri buna atýyoruz.
{
	Word *start = First();
	Word *end = End();
	_maxSize *= 2;
	_list = new Word[_maxSize];

	auto *temp = _list;

	while (start != end)
		*temp++ = *start++;


}


void WordsList::Print()
{
	wprintf(L"\nInserting takes %d second %d millisecond passed.\n", _watcher.getCurrentTimeSecond(), _watcher.getCurrentTimeRest());

	auto word = First();
	int counter = 10;

	while (counter > 0) {//ilk 10 kelimeyi yazdýrýyoruz, stopwords kontrolü.
		if (word->getWord() == L"utc"/* || L"able" || L"about" ||  L"above" ||   L"abroad" ||   L"according" ||   L"accordingly" ||   L"across" ||
			  L"ahead" ||   L"ago" ||   L"against" ||   L"again" ||   L"afterwards" ||   L"after" ||   L"adj" ||   L"actually" ||
			  L"ain't" ||   L"all" ||   L"allow" ||   L"allows" ||   L"aalmost" ||   L"alone" ||   L"along" ||   L"alongside" ||
			  L"among" ||   L"amidst" ||   L"amid" ||   L"am" ||   L"always" ||   L"although" ||   L"also" ||   L"already" ||
			  L"amongst" ||   L"an" ||   L"and" ||   L"another" ||   L"anybody" ||   L"any" ||   L"anyhow" ||   L"anyone" ||
			  L"anyways" ||   L"anywhere" ||   L"apart" ||   L"appear" ||   L"appreciate" ||   L"appropriate" ||   L"are" ||   L"aren't" ||
			  L"at" ||   L"associated" ||   L"asking" ||   L"ask" ||   L"aside" ||   L"a's" ||   L"as" ||   L"around" ||
			  L"available" ||   L"away" ||   L"awfully" ||   L"b" ||   L"back" ||   L"backwards" ||   L"be" ||   L"became" ||
			  L"become" ||   L"becomes" ||   L"becoming" ||   L"been" ||   L"before" ||   L"beforehand" ||   L"begin" ||   L"behind" ||
			  L"among" ||   L"amidst" ||   L"amid" ||   L"am" ||   L"always" ||   L"although" ||   L"also" ||   L"being" ||
			  L"beyond" ||   L"between" ||   L"better" ||   L"best" ||   L"besides" ||   L"beside" ||   L"below" ||   L"believe" ||
			  L"both" ||   L"brief" ||   L"but" ||   L"buy" ||   L"c" ||   L"appropriate" ||   L"are" ||   L"aren't" ||
			  L"among" ||   L"amidst" ||   L"amid" ||   L"am" ||   L"always" ||   L"although" ||   L"also" ||   L"already" ||
			  L"amongst" ||   L"an" ||   L"and" ||   L"another" ||   L"anybody" ||   L"any" ||   L"anyhow" ||   L"anyone" ||
			  L"anyways" ||   L"anywhere" ||   L"apart" ||   L"appear" ||   L"appreciate" ||   L"appropriate" ||   L"are" ||   L"aren't"
			  L"2009" || L"utc"*/)
		{
		}
		else {
			word->Print();
			counter--;
		}
		word++;
	}

	wprintf(L"\nAll actions take %d second %d millisecond passed.\n", _watcher.getCurrentTimeSecond(), _watcher.getCurrentTimeRest());

}

WordsList::~WordsList(void)
{
}
