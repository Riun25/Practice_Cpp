#include <iostream>
#include "Entity.h"
#include "Player.h"

int main()
{
	// Entity ��ü ����
	//Entity* entity = new Entity();
	//std::cout << entity->GetName() << "\n";

	// Player ��ü ����
	//Player* player = new Player("Riun");
	IEntity* player = new Player("Riun");
	//std::cout << player->GetName() << "\n";

	//�޸� ����
	delete player;
	//delete entity;

	std::cin.get();
}