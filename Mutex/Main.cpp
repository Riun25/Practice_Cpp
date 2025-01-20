#include <iostream>
#include <windows.h>

void ErrorExit(const char* msg)
{
	// 에러 메시지를 출력하고 프로그램 종료
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

	// 실행할 프로세스의 명령어 설정
	wchar_t  command[] = L"Multi_thread.exe";

	// 새로운 프로세스 생성
	if (!CreateProcess(
		NULL,				// 애플리케이션 이름
		command,    // 명령줄
		NULL,				// 프로세스 보안 속성
		NULL,				// 스레드 보안 속성
		FALSE,				// 자식 프로세스에 핸들을 상속할지 여부
		0,					// 생성 옵션
		NULL,				// 환경 변수
		NULL,				// 현재 디렉토리
		&si,				// STARTUPINFO 구조체
		&pi))				// PROCESS_INFORMATION 구조체
	{
		ErrorExit("CreateProcess failed.");
	}

	// 자식 프로세스가 종료될 때까지 대기
	WaitForSingleObject(pi.hProcess, INFINITE);	// <- 대기

	// 스레드 핸들 닫기
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	return 0;
}