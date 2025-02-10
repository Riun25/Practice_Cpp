#include <iostream>

class Base 
{
public:
	Base() 	{std::cout << "Base()\n";}
	virtual ~Base()	{std::cout << "~Base()\n";}

	//virtual void Abstract() abstract;
	virtual void VirtualFunc()	{std::cout << "Base VirtualFunc()\n";}
	void Func()	{std::cout << "Base Func()\n";}

private:
};

class Drived :public Base
{
public:
	Drived(){std::cout << "Drived()\n";	}
	~Drived(){std::cout << "~Drived()\n";}

	//virtual void Abstract() override{std::cout << "Drived Abstract()\n";}
	virtual void VirtualFunc(){std::cout << "Drived VirtualFunc()\n";	}
	void Func()	{std::cout << "Drived Func()\n";}
	virtual void VirtualDrived(){std::cout << "VirtualDrived()\n";	}

private:
};

class DrivedB :public Base
{
public:
	DrivedB()	{std::cout << "DrivedB()\n";}
	~DrivedB()	{std::cout << "~DrivedB()\n";}

	//virtual void Abstract() override{std::cout << "DrivedB Abstract()\n";}
	virtual void VirtualFunc(){std::cout << "DrivedB VirtualFunc()\n";	}
	void Func()	{std::cout << "DrivedB Func()\n";}
	virtual void VirtualDrivedB(){std::cout << "VirtualDrivedB()\n";	}

private:
};

class DrivedDown : public Drived, public DrivedB
{
public:
	DrivedDown() { std::cout << "DrivedDown()\n"; }
	~DrivedDown() { std::cout << "~DrivedDown()\n"; }

	//virtual void Abstract() override { std::cout << "DrivedDown Abstract()\n"; }
	virtual void VirtualFunc() { std::cout << "DrivedDown VirtualFunc()\n"; }
	void Func() { std::cout << "DrivedDown Func()\n"; }
	virtual void VirtualDrived() override {std::cout << "VirtualDrived()\n";	}
	virtual void VirtualDrivedB() override {std::cout << "VirtualDrivedB()\n";	}


private:
};

int main()
{
	//1. Base
	Base* testBase = new Drived;
	Base* testBase2 = new DrivedB;

	testBase->Func();
	testBase->VirtualFunc();

	testBase2->Func();
	testBase2->VirtualFunc();

	delete testBase;
	delete testBase2;

	//2. dynamic cast
	Base* testBase3 = new Drived;

	testBase3->Func();
	testBase3->VirtualFunc();
	Drived* downDrivedtest = dynamic_cast<Drived*>(testBase3);
	downDrivedtest->VirtualFunc();

	delete testBase3;
	
	// 3. after delete, why operation?
	Base* testBase4 = new DrivedB;
	testBase4->Func();
	testBase4->VirtualFunc();
	delete testBase4;

	testBase4->Func(); // <- 삭제했는데 왜 작동해?
	//testBase4->VirtualFunc(); // <- 이건 왜 작동 안해?
	testBase4 = nullptr;
	testBase4->Func(); // nullptr 해도 작동함

	// 4. diamone Inheritance!
	//Base* testBase4 = new DrivedDown; // 불가 : "Base가 모호합니다."
	
	// 5. cast & cast!
	Base* testBase5 = new Drived;
	Base* testBase6 = new DrivedB;

	Drived* downDrivedtest5 = dynamic_cast<Drived*>(testBase5);
	DrivedB* downDrivedtest6 = dynamic_cast<DrivedB*>(testBase6);
	downDrivedtest5->Func();
	downDrivedtest6->Func();
	downDrivedtest5->VirtualFunc();
	downDrivedtest6->VirtualFunc();

	downDrivedtest5 = (Drived*)(testBase5);
	downDrivedtest6 = (DrivedB*)(testBase6);
	downDrivedtest5->Func();
	downDrivedtest6->Func();
	downDrivedtest5->VirtualFunc();
	downDrivedtest6->VirtualFunc();

	downDrivedtest5 = reinterpret_cast<Drived*>(testBase5);
	downDrivedtest6 = reinterpret_cast<DrivedB*>(testBase6);
	downDrivedtest5->Func();
	downDrivedtest6->Func();
	downDrivedtest5->VirtualFunc();
	downDrivedtest6->VirtualFunc();

	// 6. Brother cast
	Drived* testBase7 = new Drived;
	DrivedB* testBase8 = new DrivedB;
	std::cout << "Drived의 vptr 주소: " << reinterpret_cast<void**>(testBase7)[0] << '\n';	// 첫 번째 상속받은 클래스의 vPtr

	DrivedB* Drivedtest8 = dynamic_cast<DrivedB*>(testBase7);
	Drivedtest8->Func();		// 왜 가능?
	//Drivedtest8->VirtualFunc(); // 왜 불가? bad_cast가 되어서 Drivedtest8가 nullptr의 값을 갖게 된다. nullptr이면 vPtr도 없다.
	//std::cout << "DrivedB의 vptr 주소: " << reinterpret_cast<void**>(Drivedtest8)[0] << '\n';	// 불가
	//dynamic_cast를 통해 특정 부모 클래스 타입으로 변환하면, 해당 부모 클래스에 연결된 vptr만 참조하게 된다.이로 인해, 변환된 포인터에서는 다른 부모 클래스와 관련된 vptr(및 vtable)에 접근할 수 없게 된다.

	Drivedtest8 = (DrivedB*)(testBase7);
	Drivedtest8->Func();		// 왜 가능?
	Drivedtest8->VirtualFunc();	// 왜 가능?
	std::cout << "DrivedB의 vptr 주소: " << reinterpret_cast<void**>(Drivedtest8)[0] << '\n';	// 첫 번째 상속받은 클래스의 vPtr

	Drivedtest8 = reinterpret_cast<DrivedB*>(testBase7);
	Drivedtest8->Func();		// 왜 가능?
	Drivedtest8->VirtualFunc();	// 왜 가능?
	std::cout << "DrivedB의 vptr 주소: " << reinterpret_cast<void**>(Drivedtest8)[0] << '\n';	// 첫 번째 상속받은 클래스의 vPtr

	// 7. vPtr & vfTable
	DrivedDown* drivedDown = new DrivedDown;
	Drived* brotherTest = drivedDown;
	DrivedB* brotherTestB = drivedDown;

	brotherTest->VirtualDrived();
	brotherTestB->VirtualDrivedB();

	std::cout << "Drived의 vptr 주소: " << reinterpret_cast<void**>(drivedDown)[0] << '\n';	// 첫 번째 상속받은 클래스의 vPtr
	std::cout << "DrivedB의 vptr 주소: " << reinterpret_cast<void**>(drivedDown)[1] << '\n';	// 두 번째 상속받은 클래스의 vPtr
	std::cout << sizeof(*drivedDown) << "\n"; // 두 개의 상속을 받기 때문에 64비트 기준으로 vPtr이 2개여서 객체 drivedDown 크기는 16이 된다.

}