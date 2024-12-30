#include <iostream>
#include "Entity.h"
#include "Player.h"

int main()
{
	// Entity 按眉 积己
	//Entity* entity = new Entity();
	//std::cout << entity->GetName() << "\n";

	// Player 按眉 积己
	//Player* player = new Player("Riun");
	IEntity* player = new Player("Riun");
	//std::cout << player->GetName() << "\n";

	//皋葛府 秦力
	delete player;
	//delete entity;

	std::cin.get();
}