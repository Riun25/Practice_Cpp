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

	testBase4->Func(); // <- �����ߴµ� �� �۵���?
	//testBase4->VirtualFunc(); // <- �̰� �� �۵� ����?
	testBase4 = nullptr;
	testBase4->Func(); // nullptr �ص� �۵���

	// 4. diamone Inheritance!
	//Base* testBase4 = new DrivedDown; // �Ұ� : "Base�� ��ȣ�մϴ�."
	
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
	std::cout << "Drived�� vptr �ּ�: " << reinterpret_cast<void**>(testBase7)[0] << '\n';	// ù ��° ��ӹ��� Ŭ������ vPtr

	DrivedB* Drivedtest8 = dynamic_cast<DrivedB*>(testBase7);
	Drivedtest8->Func();		// �� ����?
	//Drivedtest8->VirtualFunc(); // �� �Ұ�? bad_cast�� �Ǿ Drivedtest8�� nullptr�� ���� ���� �ȴ�. nullptr�̸� vPtr�� ����.
	//std::cout << "DrivedB�� vptr �ּ�: " << reinterpret_cast<void**>(Drivedtest8)[0] << '\n';	// �Ұ�
	//dynamic_cast�� ���� Ư�� �θ� Ŭ���� Ÿ������ ��ȯ�ϸ�, �ش� �θ� Ŭ������ ����� vptr�� �����ϰ� �ȴ�.�̷� ����, ��ȯ�� �����Ϳ����� �ٸ� �θ� Ŭ������ ���õ� vptr(�� vtable)�� ������ �� ���� �ȴ�.

	Drivedtest8 = (DrivedB*)(testBase7);
	Drivedtest8->Func();		// �� ����?
	Drivedtest8->VirtualFunc();	// �� ����?
	std::cout << "DrivedB�� vptr �ּ�: " << reinterpret_cast<void**>(Drivedtest8)[0] << '\n';	// ù ��° ��ӹ��� Ŭ������ vPtr

	Drivedtest8 = reinterpret_cast<DrivedB*>(testBase7);
	Drivedtest8->Func();		// �� ����?
	Drivedtest8->VirtualFunc();	// �� ����?
	std::cout << "DrivedB�� vptr �ּ�: " << reinterpret_cast<void**>(Drivedtest8)[0] << '\n';	// ù ��° ��ӹ��� Ŭ������ vPtr

	// 7. vPtr & vfTable
	DrivedDown* drivedDown = new DrivedDown;
	Drived* brotherTest = drivedDown;
	DrivedB* brotherTestB = drivedDown;

	brotherTest->VirtualDrived();
	brotherTestB->VirtualDrivedB();

	std::cout << "Drived�� vptr �ּ�: " << reinterpret_cast<void**>(drivedDown)[0] << '\n';	// ù ��° ��ӹ��� Ŭ������ vPtr
	std::cout << "DrivedB�� vptr �ּ�: " << reinterpret_cast<void**>(drivedDown)[1] << '\n';	// �� ��° ��ӹ��� Ŭ������ vPtr
	std::cout << sizeof(*drivedDown) << "\n"; // �� ���� ����� �ޱ� ������ 64��Ʈ �������� vPtr�� 2������ ��ü drivedDown ũ��� 16�� �ȴ�.

}