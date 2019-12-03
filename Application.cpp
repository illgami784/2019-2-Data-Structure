#include "Application.h"

Application::Application()
{
    m_Command = 0;
    OpenTime = 0;
    CloseTime = 0;
    isOpen = false;
}

void Application::run()
{
    while (true) {
        if (isOpen)
        {
            open();
        }
        else
        {
            close();
        }
    }
}

void Application::open()
{
    while (true) {
        cout << "\n\t 종료를 위해서는 ~를 입력하세요";

    }
    isOpen = false;
    return;
}

void Application::close()
{
    while (true) {
        getCloseCommand();
        switch (m_Command)
        {
            case 1:
                printTodayInfo();
                break;
            case 2:
                printAllRideInfo();
                break;
            case 3:
                searchRide();
                break;
            case 4:
                addRide();
                break;
            case 5:
                updateRide();
                break;
            case 6:
                deleteRide();
                break;
            case 7:
                isOpen = true;
                return;
            default:
                cout << "\n\t입력 오류입니다. 다시 입력해주세요.";
                break;
        }
    }
}

bool Application::getCloseCommand()
{
    cout << "\n\t폐장 상태";
    cout << "\n\t1. 놀이공원 통계 보기";
    cout << "\n\t2. 전체 놀이기구 정보 보기";
    cout << "\n\t3. 상세 놀이기구 정보 보기";
    cout << "\n\t4. 놀이기구 추가 하기";
    cout << "\n\t5. 놀이기구 수정 하기";
    cout << "\n\t6. 놀이기구 삭제 하기";
    cout << "\n\t7. 개장하기";
    cout << "\n\t0. 프로그램 종료";
    cin >> m_Command;
    return true;
}

bool Application::getOpenCommand()
{
    cout << "\n\t안녕";
}


bool Application::isItOpen() const
{

}

bool Application::searchAllUser()
{

}

void Application::printRideInfo(int _id) const
{

}

void Application::printAllRideInfo() const
{

}



bool Application::searchRide()
{

}


bool Application::addRide()
{

}


bool Application::deleteRide()
{

}

bool Application::updateRide()
{

}


void Application::printTodayInfo()
{

}