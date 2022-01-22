#include <iostream>
using namespace std;

// 1) 양의 정수 N이 주어지면  (1 x N) + (2 x (N-1)) + (3x(N-2))+ ... + ((N-1)x2) + (Nx1)을 계산하는 프로그램을 작성하라
int main()
{
    int input;
    cin >> input;

    int sum = 0;
    for (int i = 1; i <= input; i++)
    {
        sum += i * (input - i + 1);
    }

    cout << sum;
}