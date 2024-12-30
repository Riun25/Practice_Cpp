#include <iostream>

class Player
{
public:
	Player()
		: x(0), y(0)
	{
		std::cout << "Player contructor call\n";
	}

	Player(int inX, int inY)
		: x(inX), y(inY)
	{
	}

	void ShowPosition()
	{
		std::cout << "x: " << x << "  " << "y: " << y << "\n";
	}

	int GetX() { return x; }
	int GetY() { return y; }
	void SetX(const int inX) { x = inX; }
	void SetY(const int inY) { y = inY; }

private:
	int x;
	int y;
};

int main()
{
	Player players[5];

	for (int ix = 0; ix < 5; ++ix)
	{
		players[ix].SetX(ix * 2);
		players[ix].SetY(ix * 3);
	}

	for (Player& player : players) // 순서 보장을 하지 않지만.. 항상 순서 보장이 되는 거 같다(?)
	{
		player.ShowPosition();
	}
}