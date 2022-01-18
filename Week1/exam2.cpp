// 한변의 길이가 양의 정수인 정사각형의 한변의 길이 N이 주어지면, 한 변의 길이가 양의 정수인 크고 작은 정사각형이 모두 몇 개가 있는지 전체 개수를 구하는 프로그램을 작성하여라.
// 한변의 길이가 4인 정사각형에는 30개의 정사각형이 있다.(1-16개, 2-9개, 3-4개, 4-1개)
#include <iostream>
using namespace std;

int RectangerSahpe(int num)
{
    int count = 0;
    int *len = new int[num];
    for (int i = 1; i <= num; i++)
    {
        len[i - 1] = i;
        count += len[i - 1] * len[i - 1];
    }
    return count;
}

int main()
{
    int len;
    cout << "정사각형의 한 변의 길이 : ";
    cin >> len;

    cout << RectangerSahpe(len);
    return 0;
}