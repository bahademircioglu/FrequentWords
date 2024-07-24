#include "TextReader.h"


wstring TextReader::startingDirectory() {

	wchar_t exePath[MAX_PATH];// max_path deafult olarak 260 karakter. dosya yolunu alýrken kullanýyoruz.
	GetModuleFileName(nullptr, exePath, MAX_PATH);
	auto pos = wstring(exePath).find_last_of('\\');//en son \\ bulunuyor dosya yolu posa kaydediliyor.
	return wstring(exePath).substr(0, pos);
}


TextReader& TextReader::operator = (TextReader & obj)//dosya yoluyla dosyayý açma
{
	_path = obj.getPath();
	readFile.open(_path);
	return (*this);
}

wstring TextReader::getPath()// get dosya yolu
{
	return _path;
}

TextReader::TextReader()//empty const
{
	_path = L"";
}

TextReader::TextReader(wstring path)//real const. pathi alýp ilk ':'ni belirliyoruz. bu max pathden büyük ise yukarýdaki startingDirectoryi kullanarak ekliyoruz.
{
	_path = path;
	auto index = _path.find_first_of(':');
	if (index > MAX_PATH)
		_path = startingDirectory() + wchar_t('\\') + _path;
	readFile.open(_path);// en sonunda dosyayý açýyoruz.
}

bool TextReader::ReadLetter(wchar_t & _letter)
{
	_letter = readFile.get();// get fonk karakterleri okumamýzý saðlýyor, lettera ekliyoruz.
	return readFile.good();//hatasýz okunduysa ture yolluyoruz.
}

bool TextReader::Exists()// dosyayý açabiliyorsak sadosya var demek, true yolluyoruz.
{
	return readFile.is_open();
}

TextReader::~TextReader()//destr
{
}