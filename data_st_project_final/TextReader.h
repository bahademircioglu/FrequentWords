#pragma once
#include  "Headers.h"


class TextReader
{
private:
	wifstream readFile;
	wstring startingDirectory();
	wstring _path;
public:
	TextReader();
	TextReader(wstring path);
	wstring getPath();
	bool ReadLetter(wchar_t & _letter);
	bool Exists();
	TextReader & operator = (TextReader & obj);

	~TextReader();
};

