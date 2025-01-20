#include <iostream>
#include <windows.h>

void ErrorExit(const char* msg)
{
	// ���� �޽����� ����ϰ� ���α׷� ����
	std::cerr << msg << " (Error Code: " << GetLastError() << ")" << std::endl;
	ExitProcess(1);
}

int main()
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	// ������ ���μ����� ��ɾ� ����
	wchar_t  command[] = L"Multi_thread.exe";

	// ���ο� ���μ��� ����
	if (!CreateProcess(
		NULL,				// ���ø����̼� �̸�
		command,    // �����
		NULL,				// ���μ��� ���� �Ӽ�
		NULL,				// ������ ���� �Ӽ�
		FALSE,				// �ڽ� ���μ����� �ڵ��� ������� ����
		0,					// ���� �ɼ�
		NULL,				// ȯ�� ����
		NULL,				// ���� ���丮
		&si,				// STARTUPINFO ����ü
		&pi))				// PROCESS_INFORMATION ����ü
	{
		ErrorExit("CreateProcess failed.");
	}

	// �ڽ� ���μ����� ����� ������ ���
	WaitForSingleObject(pi.hProcess, INFINITE);	// <- ���

	// ������ �ڵ� �ݱ�
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	return 0;
}