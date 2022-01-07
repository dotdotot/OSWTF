#include <iostream>
using namespace std;

int algorithm()
{   
    int maxNum = 100;
    int count = 0;
    for (int i = 1; i <= maxNum; i++)
    {
        int totalSquareNum = i*i;
        if(totalSquareNum > maxNum){
            break;
        }
        count++;
    }

    return count;
}

int main()
{
    int count = algorithm();
    cout << count;
    return 0;
}