#include <iostream>
using namespace std;
// ������������ �����ϴ� �Լ� (��������)
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
    // ¦��
    int sales = 0;
    if (agencyNum % 2 == 0)
    {
        sales = (arr[agencyNum / 2 - 1] + arr[agencyNum / 2]) / 2;
    }
    // Ȧ��
    else
    {
        sales = arr[agencyNum / 2];
    }

    return sales;
}

int main()
{
    int agencyNum = 0;
    cout << "�븮���� �� : ";
    cin >> agencyNum;

    int *arr = new int[agencyNum];
    for (int i = 0; i < agencyNum; i++)
    {
        int sales = 0;
        cout << i + 1 << "��° �븮���� ���� : " << endl;
        cin >> sales;
        arr[i] = sales;
    }

    cout << "���� �� �� : ";
    for (int i = 0; i < agencyNum; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // �������� ����
    arr = numSort(arr, agencyNum);

    cout << "���� �� �� : ";
    for (int i = 0; i < agencyNum; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n�߾Ӱ� : " << centerSales(arr, agencyNum);

    return 0;
}