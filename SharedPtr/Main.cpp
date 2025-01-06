#include <memory>
#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

class Resource
{
public:
	Resource()
	{
		std::cout << "������ ȣ��\n";
	}
	~Resource()
	{
		std::cout << "�Ҹ��� ȣ��\n";
	}

	void Use()
	{
		std::cout << "�ڿ� ���\n";
	}
};


int main()
{
	std::shared_ptr<Resource> pResource1 = std::make_shared<Resource>();

	{
		std::shared_ptr<Resource> pResource2 = pResource1;
		std::cout << "���Ƚ��: " << pResource1.use_count() << "\n";
	}


	//pResource2 = nullptr;

	std::cout << "���Ƚ��: " << pResource1.use_count() << "\n";


	return 0;
}