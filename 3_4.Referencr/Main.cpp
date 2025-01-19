#include <iostream>

int main()
{
	int* array = new int[5];

	for (int i = 0; i < 5; i++)
	{
		array[i] = i + 1;
	}

	for (int i = 0; i < 5; i++)
	{
		std::cout << array[i] << " ";
	}

	delete[] array;
}