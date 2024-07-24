#include "TextReader.h"
#include "WordsList.h"
#include "WordGenerator.h"
#include "WordTopList.h"


int wmain(int argc, wchar_t * argv[])//wchar vb kullan�mlar g�rece�iz. bunlar unicode deste�i i�in kullan�ld�. her ne kadar 8 yerine 16 bit yer kaplasa da program�n t�m dillerde kullan�labilmesi daha ho� diye d���nd�k.
{
	
	int file_count = 1, i;
	wstring path;
	TextReader * readers;
	if (argc == 1)//program itself is a argument so argument count=1. 
	{
		wcout << "Please enter the file name or full path :" << endl;

		getline(wcin, path);
		readers = new TextReader[1];//dosya bilgisini al�yoruz.
		readers[0] = TextReader(path);
	}
	else
	{
		file_count = argc - 1;
		readers = new TextReader[file_count];
		for (i = 1; i < argc; i++)
			readers[i - 1] = TextReader(argv[i]);
	}

	for (i = 0; i < file_count; i++)
	{
		TextReader  * reader = &readers[i];

		if (reader->Exists())
		{
			wcout << endl << "File path: \n" << reader->getPath() << endl;
			WordTopList wordList;
			WordGenerator generator;
			wchar_t _letter;
			cout << endl << "Inserting..." << endl;

			while (reader->ReadLetter(_letter))
			{
				if (generator.Create(generator.CheckPunctuationMarks(_letter)))
					wordList.Insert(generator.getWord());
			}
			wordList.Order();
			wordList.Print();
		}
		else
		{
			cout << "The file you entered is not exists.\n";
		}

	}

	system("pause");

	return 0;
}