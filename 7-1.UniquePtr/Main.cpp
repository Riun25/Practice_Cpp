// ����Ʈ ������ ����� ���� ��� �߰�
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
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::unique_ptr<Resource> pResource = std::make_unique<Resource>();
	//Resource* resource = new Resource();

	pResource->Use();

	// ���� �����ڸ� �����߱� ������ ������ ���簡 �Ұ��ϴ�.
	//std::unique_ptr<Resource> resource = pResource;

	std::unique_ptr<Resource> pResource2 = std::move(pResource);
	
	pResource->Use(); // �������� �� ����, �� �� ���� �ִ�. �������� �����ϸ� �ݵ�� ������ ��ü�� ����ϵ��� �Ѵ�.
	// �̷��� �����ϰ� ���� �� pResource�� ��۸� ������(Dangling Pointer)��� �Ѵ�.

	// Raw ������ ��������
	Resource* rawPtr = pResource2.get();
	rawPtr->Use(); // delete�� ���ϰ� �����ؾ� �Ѵ�.


	// ����Ʈ �����ʹ� ��ü�� ������ �� ������ �� ���� Ȯ���� �� �ִ�. ����� �����Ǵ� ���� �ƴϴ�.
	{
		std::unique_ptr<Resource> pResourceInFuction = std::make_unique<Resource>();
		pResourceInFuction->Use();
	}
	
	// ��򰡿� ������ ���� ���� �������� �����ϴ� ���� ����.
	Resource& refResource = *pResource2;

	return 0;
}