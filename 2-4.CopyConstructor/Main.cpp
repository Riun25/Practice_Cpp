#include <iostream>

class Player
{
public:
	Player()
		:mX(0), mY(0)
	{
		//std::cout << "Player() called\n";
		size_t length = strlen("Player") + 1;

		// ���� Ȯ��
		mName = new char[length];

		// ���ڿ� ����
		strcpy_s(mName, length, "Player");

	}

	//Player() = delete;

	Player(const char* _name, int _x, int _y)
		:mX(_x), mY(_y)
	{
		//std::cout << "Player(int number) called\n";
		size_t length = strlen(_name) + 1;

		// ���� Ȯ��
		this->mName = new char[length];

		// ���ڿ� ����
		strcpy_s(this->mName, length, _name);

	}

	// �Ҹ���
	~Player()
	{
		// �� �޸� ����
		if (mName)
		{
			delete[] mName;
		}
	}

	// ���� ������
	// c++ calue category.
	// lvalue/rvalue
	// int a = 10;
	// int number = a;
	// r value refernece.
	/*Player(const Player& other)
	{
		std::cout << "Player(const Player& other) called\n";

		mX = other.mX;
		mY = other.mY;
	}*/

	void Print()
	{
		std::cout << "name : " << mName << " x: " << mX << ", y : " << mY << "\n";
	}


private:
	int mX;
	int mY;
	char* mName;
};



int main()
{
	//Player player1 = Player(); // �⺻ ������ ȣ��
	//Player player2 = Player(10);
	//Player player3 = Player(player2);

	//player2.Print();
	//player3.Print();

	Player player1 = Player("Riun", 0, 0);
	Player player2 = Player(player1);

	player1.Print();
	player2.Print();

	//std::cin.get();

	return 0;
}