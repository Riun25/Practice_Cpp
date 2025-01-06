// 스마트 포인터 사용을 위한 헤더 추가
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
		std::cout << "생성자 호출\n";
	}
	~Resource()
	{
		std::cout << "소멸자 호출\n";
	}

	void Use()
	{
		std::cout << "자원 사용\n";
	}
};


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::unique_ptr<Resource> pResource = std::make_unique<Resource>();
	//Resource* resource = new Resource();

	pResource->Use();

	// 복사 생성자를 삭제했기 때문에 포인터 복사가 불가하다.
	//std::unique_ptr<Resource> resource = pResource;

	std::unique_ptr<Resource> pResource2 = std::move(pResource);
	
	pResource->Use(); // 컴파일이 될 수도, 안 될 수도 있다. 소유권을 이전하면 반드시 이전한 객체로 사용하도록 한다.
	// 이렇게 이전하게 됐을 때 pResource를 댕글링 포인터(Dangling Pointer)라고 한다.

	// Raw 포인터 가져오기
	Resource* rawPtr = pResource2.get();
	rawPtr->Use(); // delete를 안하게 주의해야 한다.


	// 스마트 포인터는 객체가 없어질 때 삭제가 된 것을 확인할 수 있다. 종료시 삭제되는 것이 아니다.
	{
		std::unique_ptr<Resource> pResourceInFuction = std::make_unique<Resource>();
		pResourceInFuction->Use();
	}
	
	// 어딘가에 전달할 때는 참조 형식으로 전달하는 것이 좋다.
	Resource& refResource = *pResource2;

	return 0;
}