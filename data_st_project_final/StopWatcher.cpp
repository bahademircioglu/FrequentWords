#include "StopWatcher.h"


StopWatcher::StopWatcher()
{
	startTime = clock();//clock anlýk zamaný veriyor. baþlangýç zamanýna kaydediyoruz.
}

clock_t StopWatcher::getCurrentTimeSecond()
{
	clock_t time = (clock() - startTime);//anlýk zaman ile baþlangýç zamaný arasýnda fark=geçen zaman
	clock_t second = (time / CLOCKS_PER_SEC);// geçen süreyi saniyeye çeviriyoruz.
	return second;
}

clock_t StopWatcher::getCurrentTimeRest()
{
	clock_t time = (clock() - startTime);// yukarýdaki ile ayný iþlem
	clock_t milisecond = (time % CLOCKS_PER_SEC);// saniniye bölümden kalan (mod) bize milisaniyeyi veriyor.
	return milisecond;
}

StopWatcher::~StopWatcher()//destr
{
}