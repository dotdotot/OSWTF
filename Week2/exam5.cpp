#include <iostream>
#include <string>
#include <vector>
using namespace std;

// �տ��� ������ �ڿ��� ������ ���� ���� �ȸ���� �� ��� �Ѵ�.
// ���� �� �� �ڸ��� �̷���� �ȸ���� ���� 11, 22, 33, 44, 55, 66, 77, 88, 99�� 9���� �ִ�.
// A�̻� B������ ���� �߿��� �ȸ���� ���� ��ο� �Ѱ����� ����ϴ� ���α׷��� �ۼ��϶�.
// A�� B�� �Է��� �޴´�.

// �Ӹ������ ���� ���ϴ� �Լ�
vector<int> palindromeNum(int a, int b)
{
    vector<int> num;
    // a~b���� �ݺ�
    for (int i = a; i <= b; i++)
    {
        // i�� ���ڿ��� ����� text�� ����
        string text = to_string(i);
        vector<char> vectorText;

        for (int ii = 0; ii < text.length(); ii++)
        {
            vectorText.push_back(text[ii]);
        }

        bool check = false;

        // ���ڸ� ������ ��� �Ӹ���� ��
        if (vectorText.size() == 1)
        {
            check = true;
        }
        // ���ڸ� �̻� ������ �˻�
        else
        {   
            // vectorText.size() / 2��ŭ�� �ݺ��ϴ� ���� -> �߾ӿ� �ִ� ���ڴ� �ݴ뿡�� �о ������ ��ġ�� ����
            // �׷��Ƿ� size / 2��ŭ�� �ݺ�(������ ��ȯ�ǹǷ� �Ҽ����� �ڵ����� �߷�����)
            for (int ii = 0; ii < vectorText.size() / 2; ii++)
            {
                if (vectorText[ii] == vectorText[vectorText.size() - (1 + ii)])
                {
                    check = true;
                }
                else
                {
                    check = false;
                    break;
                }
            }
        }

        if (check)
        {
            num.push_back(i);
        }
    }

    return num;
}

int main()
{
    // �ּҰ� a�� �ִ밪 b�Է�
    int A, B;
    cin >> A >> B;

    // v���� �Ӹ������ ������ ���ԵǾ�����
    vector<int> v = palindromeNum(A, B);
    // �ݺ��� ����
    vector<int>::iterator iter;

    // a�̻� b������ �Ӹ������ �� ���
    for (iter = v.begin(); iter != v.end(); iter++)
    {
        cout << *iter << " ";
    }

    // �� ���� ���
    cout << endl
         << "�Ӹ���� ���� �� ���� : " << v.size() << endl;
    return 0;
}