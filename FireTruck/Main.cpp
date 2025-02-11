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

	// 소방차 생성
	FireTruck* truckOne = new FireTruck();
	FirefighterBase* riun = new Firefighter("Riun");
	FirefighterBase* ronnie = new Firefighter("로니");

    // 소방서 생성
    FireStation* fireStation = new FireStation();

    // 관리자 생성
    Administrator* teajun = new Administrator("관리자", "태준", "장");

    // 수습 소방관 생성 및 테스트
    FirefighterBase* bill = new TraineeFirefigter("빌");
    bill->ExtinguishFire();

    // 소방서장
    FireChief* harry = new FireChief("해리", ronnie);
    truckOne->SetDriver(harry);
    harry->Drive(truckOne, Point(200, 300));

    // 출근
    fireStation->ClockIn(riun);
    fireStation->ClockIn(ronnie);
    fireStation->ClockIn(teajun);
    fireStation->ClockIn(bill);
    fireStation->ClockIn(harry);

    // 이름 확인
    fireStation->RollCall();

    // 불끄기 위힘
    FirefighterBase* stillHarry = harry;
    //harry->TellFirefighterToExtinguishFire(ronnie);
    harry->ExtinguishFire();

	// 운전자 설정
    truckOne->SetDriver(ronnie);

    // 소방차 이동.
    ronnie->Drive(truckOne, Point(10, 5));

    // 운전자 설정.
    truckOne->SetDriver(riun);

    // 소방차 이동.
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