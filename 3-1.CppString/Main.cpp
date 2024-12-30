#include <iostream>
//#include <string>
#include <array>

void TestFunction(char* array, int length)
{
    //size_t length = strlen(string);
    int count = sizeof(array) / sizeof(array[0]);
    std::cout << "count : " << count << "\n";
}

// ������(Entry Point).
int main()
{
    {
        //auto testString = "Riun";
        const char* testString = "Riun";
        char charArray[] = "Hello";

        // ���� �Ҵ�
        // long long -> __int64 : ���� Ÿ��

        size_t length = strlen("Riun") + 1; //strlen�� null ���ڸ� �����ϰ� ���� 1�� ������ ���̴�.
        char* name = new char[length];
        strcpy_s(name, length, "Riun");

        // �׽�Ʈ ���
        std::cout << testString << "\n";
        std::cout << charArray << "\n";
        std::cout << name << "\n";

        //delete testString;
        delete[] name;

        // �ǹ̴� �����ϴ�.
        std::cin.get();

        return 0;
    }

    // ����(char -> character).
    char character = 'a';

    // ���ڿ�(string - ��/��). ���� �迭.
    char charArray[] = "Hello";

    // List(���� �迭) std::vector / HashTable(Hash/�ؽ�).
    // �˻�.

    //auto rawString = "Hello";
    const char* rawString = "Hello C++";

    //char chars[100];
    char* chars = new char[100];
    std::cin >> chars;
    delete[] chars;

    // c-library.
    // ���� ���ϱ�.
    //int length = 0;
    // ���� ����.
    //while (true)
    //{
    //    // ���� ����(Ż�� ����).
    //    // Todo: �������� ����.

    //    if (rawString[length] == '\0')
    //    {
    //        break;
    //    }

    //    ++length;
    //}

    // �Լ��� ���� ���ϱ�.
    size_t length = strlen(rawString);
    // string.Length() string.Size() Count().

    // ��(Heap) - ���� �޸� - å��.
    char* heapString = new char[length + 1];

    // ���ڿ� ����.
    strcpy_s(heapString, length + 1, rawString);

    // �޸� ����.
    //memcpy(heapString, rawString, sizeof(char) * length + 1);
    //heapString[length] = '\0';

    // C# Array.Copy.
    //std::cout << heapString << std::endl;
    std::cout << charArray[3] << "\n";
    std::cout << *(rawString + 3) << "\n";

    std::cout << sizeof(rawString) << "\n";

    // ����.
    delete[] heapString;

    std::cin.get();
}