#include <iostream>

// 클래스 템플릿
template <typename T>
class Data
{
public:
	Data(T _newData) : mData(_newData)
	{
	}

	void SetDaya(T _newData)
	{
		mData = _newData;
	}

	T GetData() const { return mData; }


private:
	T mData;

};

// Entry Point.
int main()
{
	Data<int> data(10);
	Data<float> pi(3.141592f);
	std::cout << data.GetData() << "\n";
	std::cout << pi.GetData() << "\n";

	std::cin.get();
}