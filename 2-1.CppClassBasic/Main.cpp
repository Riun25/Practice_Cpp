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

// Ŭ���� ����
class Player
{
public:
	// Ŭ���� �̸��� �Ȱ��� ���� ������
	Player()
		: mX(0), mY(0), mSpeed(1)
	{
		std::cout << "������ ȣ��\n";
	}
	~Player()
	{
		std::cout << "�Ҹ��� ȣ��\n";
	}

	// �̵��� ��ŭ�� �Ÿ��� �Է� �޾Ƽ� ��ǥ�� �̵���Ű�� �Լ�
	void Move(int _x, int _y)
	{
		this->mX += _x;
		this->mY += _y;
	}

	// ����
private:
	int mX;
	int mY;
	int mSpeed;
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(158);

	// ��ü/��ü/������Ʈ/�ν��Ͻ� ����
	// Player player;
	Player player = Player();
	player.Move(10, 20);

	// ���� �Ҵ�
	Player* player2 = new Player();
	// delete player2;
	//player2 = nullptr;

	std::cin.get();

	return 0;
}