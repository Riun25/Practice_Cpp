#include <iostream>

struct Monster
{
	int HP;
	int MP;
	int ST;
	float Speed;
	int Exp;
};

void Print(Monster& _monster)
{
	std::cout << "HP: " << _monster.HP << "\n";
	std::cout << "MP: " << _monster.MP << "\n";
	std::cout << "ST: " << _monster.ST << "\n";
	std::cout << "Speed: " << _monster.Speed << "\n";
	std::cout << "Exp: " << _monster.Exp << "\n";
}

int main()
{
	Monster monster = { 100, 30, 20, 2.0f, 1234 };

	Print(monster);
}