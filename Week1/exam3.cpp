#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

// ��� ���ڿ� ���� / ��� ���� ����

// java�� split ����
vector<string> split(string text, string divid)
{
    vector<string> v;
    char *c = strtok((char *)text.c_str(), divid.c_str());
    while (c)
    {
        v.push_back(c);
        c = strtok(NULL, divid.c_str());
    }
    return v;
}

// �������� Ȯ��
bool gather(char text)
{
    bool check = false;

    if (text == 'a' || text == 'e' || text == 'i' || text == 'o' || text == 'u')
    {
        check = true;
    }

    return check;
}

int main()
{
    // �Է�
    string text;
    getline(cin, text, '\n');

    // ���й��ڷ� �ڸ� ���ڿ��� ����ִ� vector
    vector<string> vText = split(text, " ");

    // �ݺ��� ����
    vector<string>::iterator iter;

    // ������ �ִ� ���� / ���� �� ���ڿ� index��ȣ
    int vectorIndex = 0;
    int maxGather = 0;

    // ��� ���ڿ� ���� ���� / ��� ���� ����
    double averageLength = 0;
    double averageGather = 0;

    // ���
    int index = 0;
    for (iter = vText.begin(); iter != vText.end(); iter++)
    {
        int maxGather2 = 0;
        string t = (string)*iter;
        for (int i = 0; i < t.length(); i++)
        {
            if (gather(t[i]))
            {
                maxGather2++;
            }
        }

        // �ִ� ���� ���ڿ� index ����
        if (vText[vectorIndex].length() < t.length())
        {
            vectorIndex = index;
        }

        // �ִ� �������� ����
        if (maxGather < maxGather2)
        {
            maxGather = maxGather2;
        }

        averageLength += t.length();
        averageGather += maxGather2;
        index++;
    }
    // ��� ����
    averageLength = averageLength / vText.size();
    averageGather = averageGather / vText.size();

    cout << "���� �� ���ڿ� : " << vText[vectorIndex] << endl;
    cout << "���� ���� ������ ���� : " << maxGather << endl;

    cout << "��� ���ڿ� ���� : " << averageLength << endl;
    cout << "��� ���� ���� : " << averageGather << endl;
}