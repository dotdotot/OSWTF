// �Ѻ��� ���̰� ���� ������ ���簢���� �Ѻ��� ���� N�� �־�����, �� ���� ���̰� ���� ������ ũ�� ���� ���簢���� ��� �� ���� �ִ��� ��ü ������ ���ϴ� ���α׷��� �ۼ��Ͽ���.
// �Ѻ��� ���̰� 4�� ���簢������ 30���� ���簢���� �ִ�.(1-16��, 2-9��, 3-4��, 4-1��)
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
    cout << "���簢���� �� ���� ���� : ";
    cin >> len;

    cout << RectangerSahpe(len);
    return 0;
}