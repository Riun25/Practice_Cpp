#include <iostream>

int main()
{
	// �о�� �����
	char buffer[256];

	FILE* file = nullptr;

	// ���� ����
	fopen_s(&file, "Test.txt", "rt");
	if (file != nullptr)
	{
		// ���� �б�
		while (true)
		{
			// ���ۿ� ���� �о���̱�.
			if (fgets(buffer, 256, file) == nullptr)
			{
				break;
			}

			// ���
			std::cout << buffer;
		}
	}

	// ���� �ݱ�
	fclose(file);
}