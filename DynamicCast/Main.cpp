#include <iostream>

// 타입 정보를 위한 매크로.
#define RTTI(name) \
public:			\
	virtual const char* ClassName() const {return #name;}

class Actor
{
	RTTI(Actor)

public:
	// 가상 함수(Virtual Fuction)
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
	// 객체 생성
	Actor* actor = new Actor();
	Player* player = new Player();

	// 업 캐스팅
	// Actor* actorPoint = reinterpret_cast<Actor*>(player); 같은 의미
	// Actor* actorPoint = (Actor*)player;
	Actor* actorPoint = player;

	// Ok.
	Player* playerPointer = static_cast<Player*>(actorPoint);

	// Not ok.
	Player* player2 = dynamic_cast<Player*>(actor);


	// 다운 캐스팅 한 후에는 꼭 예외처리 해줘야 한다. 
	// + 다운 캐스팅을 사용하기 위해서는 가상함수 테이블에 저장이 되어서 추가 정보가 저장되어 있어야 한다.
	if (player2)
	{
		// 함수 호출
		player2->PrintValue();
	}
	else
	{
		std::cout << "형변환 실패.\n";
	}

	// typeid
	/*const type_info& info = typeid(actorPoint);
	std::cout << "타입 이름 : " << info.name() << "\n";*/

	std::cout << "Actor 타입: " << actor->ClassName() << "\n";
	std::cout << "Player 타입: " << player->ClassName() << "\n";
	std::cout << "ActorPointer 타입: " << actorPoint->ClassName() << "\n";

	// 타입 비교.
	if (strcmp(actor->ClassName(), player->ClassName()) == 0)
	{
		std::cout << "타입 동일\n";
	}
	else
	{
		std::cout << "타입 다름\n";
	}
}