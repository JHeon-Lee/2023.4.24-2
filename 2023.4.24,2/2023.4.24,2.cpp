// 2023.4.24,2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "cMainGame.h"
/*
    게임의 기본 프레임워크 프로그램

    메인 게임 클래스 - 전체 게임 클래스들을 관리해주는 클래스
    플레이어 클래스
    스톡 클래스 - 인벤토리 및 상점의 부모 클래스 - 아이템 관리를 해주는 클래스
    인벤토리 클래스(스톡) - 플레이어가 보유중인 아이템을 관리해주는 클래스
    상점 클래스(스톡) - 상점의 아이템을 관리해주는 클래스, 가상의 상점을 구현
    타운 클래스 - 가상의 마을을 구현
*/


int main()
{
    // 콘솔창 사이즈
    system("mode con: cols=96 lines=27");

    cMainGame* pMg = new cMainGame;
    bool isPlaying = true;

    while (isPlaying)
    {
        pMg->MainPlay();

        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
            isPlaying = false;
    }

    return 0;
}
