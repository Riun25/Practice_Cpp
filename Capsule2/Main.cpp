#include "Time.h"

int main()
{
	Time time1 = Time(10);            // 10시 0분 0초.
	Time time2 = Time(10, 20);        // 10시 20분 0초.
	Time time3 = Time(10, 20, 30);    // 10시 20분 30초.

	time2.ShowTime();
	time2.ShowTimeInSeconds();
}

/// 출력 결과.
//[10시 20분 0초]
//37200초