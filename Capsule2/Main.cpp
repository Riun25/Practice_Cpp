#include "Time.h"

int main()
{
	Time time1 = Time(10);            // 10�� 0�� 0��.
	Time time2 = Time(10, 20);        // 10�� 20�� 0��.
	Time time3 = Time(10, 20, 30);    // 10�� 20�� 30��.

	time2.ShowTime();
	time2.ShowTimeInSeconds();
}

/// ��� ���.
//[10�� 20�� 0��]
//37200��