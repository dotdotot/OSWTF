// 대학생대상 창업경진대회에 다섯 명이 출전하였다.
// 창업을 위한 계획서를 발표하고 네 명의 심사위원으로부터 1점부터 5점까지의 점수를 받을 수 있다.
// 네 명의 심사위원으로부터 받은 점수의 합이 가장 많은 출전자가 대회의 우승자가 되는 경우 우승자는 누구인지와 우승자가 받은 점수의 총합을 구하여라

#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    srand(time(NULL));

    // 5명의 학생 점수를 0으로 초기화
    int student[5] = {0};

    // 5명 학생의 심사
    for (int i = 0; i < 5; i++)
    {   
        // 각 학생당 4명의 심사위원이 점수 부여
        int score = 0;
        for (int ii = 0; ii < 4; ii++)
        {
            // 결과물을 모르는 상태이기에 랜덤으로 점수부여
            score += rand() % 5 + 1;
        }
        // 학생의 점수를 심사위원 점수의 총합으로 갱신
        student[i] = score;
    }

    // 점수, 인덱스 변수
    int score = 0;
    int index = -1;

    // 5명의 학생들 중 우승자 선별
    for (int i = 0; i < 5; i++)
    {
        if (score < student[i])
        {
            score = student[i];
            index = i;
        }
    }

    // 우승한 학생의 순서와 점수의 총합 출력
    cout << index + 1 << "번째 학생 우승 (" << score << ")";

    return 0;
}