#include <iostream>

int main()
{
	// 읽어올 저장소
	char buffer[256];

	FILE* file = nullptr;

	// 파일 열기
	fopen_s(&file, "Test.txt", "rt");
	if (file != nullptr)
	{
		// 파일 읽기
		while (true)
		{
			// 버퍼에 내용 읽어들이기.
			if (fgets(buffer, 256, file) == nullptr)
			{
				break;
			}

			// 출력
			std::cout << buffer;
		}
	}

	// 파일 닫기
	fclose(file);
}