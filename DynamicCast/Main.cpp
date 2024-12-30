#include <iostream>

// Ÿ�� ������ ���� ��ũ��.
#define RTTI(name) \
public:			\
	virtual const char* ClassName() const {return #name;}

class Actor
{
	RTTI(Actor)

public:
	// ���� �Լ�(Virtual Fuction)
	virtual void PrintValue()
	{
		std::cout << "Value: " << a << "\n";
	}

protected:
	int a = 2;
};

class Player :public Actor
{
	RTTI(Player)
};

int main()
{
	// ��ü ����
	Actor* actor = new Actor();
	Player* player = new Player();

	// �� ĳ����
	// Actor* actorPoint = reinterpret_cast<Actor*>(player); ���� �ǹ�
	// Actor* actorPoint = (Actor*)player;
	Actor* actorPoint = player;

	// Ok.
	Player* playerPointer = static_cast<Player*>(actorPoint);

	// Not ok.
	Player* player2 = dynamic_cast<Player*>(actor);


	// �ٿ� ĳ���� �� �Ŀ��� �� ����ó�� ����� �Ѵ�. 
	// + �ٿ� ĳ������ ����ϱ� ���ؼ��� �����Լ� ���̺� ������ �Ǿ �߰� ������ ����Ǿ� �־�� �Ѵ�.
	if (player2)
	{
		// �Լ� ȣ��
		player2->PrintValue();
	}
	else
	{
		std::cout << "����ȯ ����.\n";
	}

	// typeid
	/*const type_info& info = typeid(actorPoint);
	std::cout << "Ÿ�� �̸� : " << info.name() << "\n";*/

	std::cout << "Actor Ÿ��: " << actor->ClassName() << "\n";
	std::cout << "Player Ÿ��: " << player->ClassName() << "\n";
	std::cout << "ActorPointer Ÿ��: " << actorPoint->ClassName() << "\n";

	// Ÿ�� ��.
	if (strcmp(actor->ClassName(), player->ClassName()) == 0)
	{
		std::cout << "Ÿ�� ����\n";
	}
	else
	{
		std::cout << "Ÿ�� �ٸ�\n";
	}
}