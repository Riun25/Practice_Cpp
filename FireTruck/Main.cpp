#include "FireFighter.h"
#include "FireCheif.h"

int main()
{
	// �ҹ��� ����
	FireTruck* truckOne = new FireTruck();
	Firefighter* riun = new Firefighter("Riun");
	Firefighter* ronnie = new Firefighter("�δ�");

    // �ҹ漭��
    FireChief* harry = new FireChief("�ظ�", ronnie);
    truckOne->SetDriver(harry);
    harry->Drive(truckOne, Point(200, 300));

    // �Ҳ��� ����
    //harry->TellFirefighterToExtinguishFire(ronnie);
    harry->ExtinguishFire();

	// ������ ����
    truckOne->SetDriver(ronnie);

    // �ҹ��� �̵�.
    ronnie->Drive(truckOne, Point(10, 5));

    // ������ ����.
    truckOne->SetDriver(riun);

    // �ҹ��� �̵�.
    riun->Drive(truckOne, Point(20, -3));

    std::cin.get();

}