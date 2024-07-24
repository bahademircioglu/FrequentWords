#include "StopWatcher.h"


StopWatcher::StopWatcher()
{
	startTime = clock();//clock anl�k zaman� veriyor. ba�lang�� zaman�na kaydediyoruz.
}

clock_t StopWatcher::getCurrentTimeSecond()
{
	clock_t time = (clock() - startTime);//anl�k zaman ile ba�lang�� zaman� aras�nda fark=ge�en zaman
	clock_t second = (time / CLOCKS_PER_SEC);// ge�en s�reyi saniyeye �eviriyoruz.
	return second;
}

clock_t StopWatcher::getCurrentTimeRest()
{
	clock_t time = (clock() - startTime);// yukar�daki ile ayn� i�lem
	clock_t milisecond = (time % CLOCKS_PER_SEC);// saniniye b�l�mden kalan (mod) bize milisaniyeyi veriyor.
	return milisecond;
}

StopWatcher::~StopWatcher()//destr
{
}