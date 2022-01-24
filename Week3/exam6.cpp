#include <iostream>
using namespace std;
// 오름차순으로 정렬하는 함수 (버블정렬)
int *numSort(int *arr, int agencyNum)
{
    for (int pass = 0; pass < agencyNum - 1; pass++)
    {
        for (int i = 0; i < agencyNum - pass - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int swap = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = swap;
            }
        }
    }
    return arr;
}

int centerSales(int *arr, int agencyNum)
{
    // 짝수
    int sales = 0;
    if (agencyNum % 2 == 0)
    {
        sales = (arr[agencyNum / 2 - 1] + arr[agencyNum / 2]) / 2;
    }
    // 홀수
    else
    {
        sales = arr[agencyNum / 2];
    }

    return sales;
}

int main()
{
    int agencyNum = 0;
    cout << "대리점의 수 : ";
    cin >> agencyNum;

    int *arr = new int[agencyNum];
    for (int i = 0; i < agencyNum; i++)
    {
        int sales = 0;
        cout << i + 1 << "번째 대리점의 매출 : " << endl;
        cin >> sales;
        arr[i] = sales;
    }

    cout << "정렬 전 값 : ";
    for (int i = 0; i < agencyNum; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 오름차순 정렬
    arr = numSort(arr, agencyNum);

    cout << "정렬 후 값 : ";
    for (int i = 0; i < agencyNum; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n중앙값 : " << centerSales(arr, agencyNum);

    return 0;
}