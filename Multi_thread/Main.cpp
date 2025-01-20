#include <iostream>
#include <windows.h>

long gCount = 0;

DWORD WINAPI Thread1(LPVOID _lpParameta)
{
	while (true)
	{
		// InterlockedIncrement�� ����� ���������� ����
		long count = InterlockedIncrement(&gCount);
		printf("Thread #1 (%d)\n", count);
		Sleep(10);
	}
}

DWORD WINAPI Thread2(LPVOID _lpParameta)
{
	while (true)
	{
		// InterlockedIncrement�� ����� ���������� ����
		long count = InterlockedIncrement(&gCount);
		printf("Thread #2 (%d)\n", count);
		Sleep(10);
	}
}

int main()
{
	// ������ �ڵ� ����
	HANDLE hThread1, hThread2;

	// ������ ����
	hThread1 = CreateThread(nullptr, 0, Thread1, nullptr, 0, nullptr);
	if (hThread1 == nullptr)
	{
		std::cerr << "Thread 1 ���� ����!" << std::endl;
		return 1;
	}

	hThread2 = CreateThread(nullptr, 0, Thread2, nullptr, 0, nullptr);
	if (hThread2 == nullptr)
	{
		std::cerr << "Thread 2 ���� ����!" << std::endl;
		CloseHandle(hThread1);
		return 1;
	}

	// ���� �����忡�� �� �����带 ��ٸ�
	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);

	// ������ �ڵ� �ݱ�
	CloseHandle(hThread1);
	CloseHandle(hThread2);

	return 0;
}