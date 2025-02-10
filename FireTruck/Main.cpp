#include "FireFighter.h"
#include "FireCheif.h"

int main()
{
	// 소방차 생성
	FireTruck* truckOne = new FireTruck();
	Firefighter* riun = new Firefighter("Riun");
	Firefighter* ronnie = new Firefighter("로니");

    // 소방서장
    FireChief* harry = new FireChief("해리", ronnie);
    truckOne->SetDriver(harry);
    harry->Drive(truckOne, Point(200, 300));

    // 불끄기 위힘
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

    std::cin.get();

}