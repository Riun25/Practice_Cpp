#include "FireFighterBase.h"
#include "FireFighter.h"
#include "FireCheif.h"
#include "TraineeFirefigter.h"

#include "FireStation.h"
#include "Administrator.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// �ҹ��� ����
	FireTruck* truckOne = new FireTruck();
	FirefighterBase* riun = new Firefighter("Riun");
	FirefighterBase* ronnie = new Firefighter("�δ�");

    // �ҹ漭 ����
    FireStation* fireStation = new FireStation();

    // ������ ����
    Administrator* teajun = new Administrator("������", "����", "��");

    // ���� �ҹ�� ���� �� �׽�Ʈ
    FirefighterBase* bill = new TraineeFirefigter("��");
    bill->ExtinguishFire();

    // �ҹ漭��
    FireChief* harry = new FireChief("�ظ�", ronnie);
    truckOne->SetDriver(harry);
    harry->Drive(truckOne, Point(200, 300));

    // ���
    fireStation->ClockIn(riun);
    fireStation->ClockIn(ronnie);
    fireStation->ClockIn(teajun);
    fireStation->ClockIn(bill);
    fireStation->ClockIn(harry);

    // �̸� Ȯ��
    fireStation->RollCall();

    // �Ҳ��� ����
    FirefighterBase* stillHarry = harry;
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

    delete truckOne;
    delete ronnie;
    delete riun;
    delete bill;
    delete harry;

    delete fireStation;
    delete teajun;

    std::cin.get();
}