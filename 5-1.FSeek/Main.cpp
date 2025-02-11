#include <iostream>
#include <fstream>

int main()
{
	// 테스트 문자열
	//const char* stringValue = "id : 10 name: chaeyunHuh balance: 1000000";

	//// 문자열에서 특정 값 가져오기
	//int id = 0;
	//char name[256];
	//int balance = 0;
	//sscanf_s(stringValue, "id: %d name: %s balance: %d", &id, name, 256, &balance);

	//std::cout << "id: " << id << "\n";
	//std::cout << "name: " << name << "\n";
	//std::cout << "balance: " << balance << "\n";

	// 데이터 쓰기
	int id = 10;
	const char* name = "hariunYun";
	int balance = 50000000;

	// 문자열로 만들기
	// 저장할 버퍼
	char data[1024] = {};
	snprintf(data, 1024, "id: %d name: %s balance: %d", id, name, balance);

	// 테스트 출력
	std::cout << data << "\n";

	// 파일로 생성
	/*FILE* file = nullptr;
	fopen_s(&file, "AccountData.txt", "wb");
	size_t length = strlen(data);
	if (file != nullptr)
	{
		fwrite(data, length, 1, file);
		fclose(file);
	}*/

	// 전체 문자열 저장
	FILE* file = nullptr;
	fopen_s(&file, "AccountData.txt", "rb");
	size_t length = strlen(data);
	if (file != nullptr)
	{
		char total[2048] = {};
		char buffer[1024] = {};

		while (!feof(file))
		{
			fgets(buffer, 1024, file);

			// 문자열 합치기
			strcat_s(total, buffer);
		}
		std::cout << total;

		// 값 가져오기
		int id1 = 0;
		char nameBuffer[256] = {};
		int balance1 = 0;

		// %d : decimal (정수)
		// %f: float (실수/RealNumber)
		// %s: string
		// %c: char
		sscanf_s(total, "id: %d, name: %s, balance: %d", &id1, nameBuffer, 256, &balance1);
		
		std::cin.get();
	}


	//std::ofstream output;
	//std::ifstream input;

	//// 파일 열기
	//FILE* file = nullptr;

	//// 파일 열기
	//fopen_s(&file, "Test.txt", "rt");

	//// 예외처리
	//if (file != nullptr)
	//{
	//	// 임의 접근(Random Access)
	//	// 처음에서 10바이트 이동
	//	fseek(file, 24, SEEK_SET);

	//	// 버퍼
	//	char buffer[256];

	//	while (!feof(file))
	//	{
	//		// 데이터 읽기
	//		if(fgets(buffer, 256, file) != nullptr);
	//		{
	//			//출력
	//			std::cout << buffer;
	//		}
	//	}

	//	// 파일 닫기
	//	fclose(file);
	//}
	//else
	//{
	//	std::cout << "파일을 찾을 수 없습니다.\n";
	//}
}