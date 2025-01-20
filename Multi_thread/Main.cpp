#include <iostream>
#include <windows.h>

long gCount = 0;

DWORD WINAPI Thread1(LPVOID _lpParameta)
{
	while (true)
	{
		// InterlockedIncrement를 사용해 원자적으로 증가
		long count = InterlockedIncrement(&gCount);
		printf("Thread #1 (%d)\n", count);
		Sleep(10);
	}
}

DWORD WINAPI Thread2(LPVOID _lpParameta)
{
	while (true)
	{
		// InterlockedIncrement를 사용해 원자적으로 증가
		long count = InterlockedIncrement(&gCount);
		printf("Thread #2 (%d)\n", count);
		Sleep(10);
	}
}

int main()
{
	// 스레드 핸들 저장
	HANDLE hThread1, hThread2;

	// 스레드 생성
	hThread1 = CreateThread(nullptr, 0, Thread1, nullptr, 0, nullptr);
	if (hThread1 == nullptr)
	{
		std::cerr << "Thread 1 생성 실패!" << std::endl;
		return 1;
	}

	hThread2 = CreateThread(nullptr, 0, Thread2, nullptr, 0, nullptr);
	if (hThread2 == nullptr)
	{
		std::cerr << "Thread 2 생성 실패!" << std::endl;
		CloseHandle(hThread1);
		return 1;
	}

	// 메인 스레드에서 두 스레드를 기다림
	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);

	// 스레드 핸들 닫기
	CloseHandle(hThread1);
	CloseHandle(hThread2);

	return 0;
}