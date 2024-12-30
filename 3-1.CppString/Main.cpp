#include <iostream>
//#include <string>
#include <array>

void TestFunction(char* array, int length)
{
    //size_t length = strlen(string);
    int count = sizeof(array) / sizeof(array[0]);
    std::cout << "count : " << count << "\n";
}

// 진입점(Entry Point).
int main()
{
    {
        //auto testString = "Riun";
        const char* testString = "Riun";
        char charArray[] = "Hello";

        // 동적 할당
        // long long -> __int64 : 같은 타입

        size_t length = strlen("Riun") + 1; //strlen은 null 문자를 제외하고 세서 1을 더해준 것이다.
        char* name = new char[length];
        strcpy_s(name, length, "Riun");

        // 테스트 출력
        std::cout << testString << "\n";
        std::cout << charArray << "\n";
        std::cout << name << "\n";

        //delete testString;
        delete[] name;

        // 의미는 없습니다.
        std::cin.get();

        return 0;
    }

    // 문자(char -> character).
    char character = 'a';

    // 문자열(string - 줄/열). 문자 배열.
    char charArray[] = "Hello";

    // List(동적 배열) std::vector / HashTable(Hash/해시).
    // 검색.

    //auto rawString = "Hello";
    const char* rawString = "Hello C++";

    //char chars[100];
    char* chars = new char[100];
    std::cin >> chars;
    delete[] chars;

    // c-library.
    // 길이 구하기.
    //int length = 0;
    // 무한 루프.
    //while (true)
    //{
    //    // 종료 조건(탈출 조건).
    //    // Todo: 종료조건 없음.

    //    if (rawString[length] == '\0')
    //    {
    //        break;
    //    }

    //    ++length;
    //}

    // 함수로 길이 구하기.
    size_t length = strlen(rawString);
    // string.Length() string.Size() Count().

    // 힙(Heap) - 자유 메모리 - 책임.
    char* heapString = new char[length + 1];

    // 문자열 복사.
    strcpy_s(heapString, length + 1, rawString);

    // 메모리 복사.
    //memcpy(heapString, rawString, sizeof(char) * length + 1);
    //heapString[length] = '\0';

    // C# Array.Copy.
    //std::cout << heapString << std::endl;
    std::cout << charArray[3] << "\n";
    std::cout << *(rawString + 3) << "\n";

    std::cout << sizeof(rawString) << "\n";

    // 해제.
    delete[] heapString;

    std::cin.get();
}