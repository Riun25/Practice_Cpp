#include <iostream>
#include <fstream>

int main()
{
	// �׽�Ʈ ���ڿ�
	//const char* stringValue = "id : 10 name: chaeyunHuh balance: 1000000";

	//// ���ڿ����� Ư�� �� ��������
	//int id = 0;
	//char name[256];
	//int balance = 0;
	//sscanf_s(stringValue, "id: %d name: %s balance: %d", &id, name, 256, &balance);

	//std::cout << "id: " << id << "\n";
	//std::cout << "name: " << name << "\n";
	//std::cout << "balance: " << balance << "\n";

	// ������ ����
	int id = 10;
	const char* name = "hariunYun";
	int balance = 50000000;

	// ���ڿ��� �����
	// ������ ����
	char data[1024] = {};
	snprintf(data, 1024, "id: %d name: %s balance: %d", id, name, balance);

	// �׽�Ʈ ���
	std::cout << data << "\n";

	// ���Ϸ� ����
	/*FILE* file = nullptr;
	fopen_s(&file, "AccountData.txt", "wb");
	size_t length = strlen(data);
	if (file != nullptr)
	{
		fwrite(data, length, 1, file);
		fclose(file);
	}*/

	// ��ü ���ڿ� ����
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

			// ���ڿ� ��ġ��
			strcat_s(total, buffer);
		}
		std::cout << total;

		// �� ��������
		int id1 = 0;
		char nameBuffer[256] = {};
		int balance1 = 0;

		// %d : decimal (����)
		// %f: float (�Ǽ�/RealNumber)
		// %s: string
		// %c: char
		sscanf_s(total, "id: %d, name: %s, balance: %d", &id1, nameBuffer, 256, &balance1);
		
		std::cin.get();
	}


	//std::ofstream output;
	//std::ifstream input;

	//// ���� ����
	//FILE* file = nullptr;

	//// ���� ����
	//fopen_s(&file, "Test.txt", "rt");

	//// ����ó��
	//if (file != nullptr)
	//{
	//	// ���� ����(Random Access)
	//	// ó������ 10����Ʈ �̵�
	//	fseek(file, 24, SEEK_SET);

	//	// ����
	//	char buffer[256];

	//	while (!feof(file))
	//	{
	//		// ������ �б�
	//		if(fgets(buffer, 256, file) != nullptr);
	//		{
	//			//���
	//			std::cout << buffer;
	//		}
	//	}

	//	// ���� �ݱ�
	//	fclose(file);
	//}
	//else
	//{
	//	std::cout << "������ ã�� �� �����ϴ�.\n";
	//}
}