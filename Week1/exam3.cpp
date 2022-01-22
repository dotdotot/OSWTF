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
bool vowel(char text)
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

    // ���� �� ���ڿ� index��ȣ / ������ �ִ� ���� 
    int vectorLongIndex = 0;
    int maxVowel = 0;

    // ���� ª�� ���ڿ� index ��ȣ / ������ �ּ� ����
    int vectorShortIndex = 0;
    int minVowel = 0;

    // ���
    int index = 0;
    for (iter = vText.begin(); iter != vText.end(); iter++)
    {
        int g = 0;
        string t = (string)*iter;
        for (int i = 0; i < t.length(); i++)
        {
            if (vowel(t[i]))
            {
                g++;
            }
        }

        // �ִ� ���� ���ڿ� index ����
        if (vText[vectorLongIndex].length() < t.length())
        {
            vectorLongIndex = index;
        }

        // �ּ� ���� ���ڿ� index ����
        if(vText[vectorShortIndex].length() > t.length()){
            vectorShortIndex = index;
        }

        // �ִ� �������� ����
        if (maxVowel < g)
        {
            maxVowel = g;
        }
        // �ּ� �������� ����
        if(minVowel > g){
            minVowel = g;
        }
        index++;
    }
    cout << "���� �� ���ڿ� : " << vText[vectorLongIndex] << endl;
    cout << "���� ª�� ���ڿ� : " << vText[vectorShortIndex] << endl;
    cout << "���� ���� ������ ���� : " << maxVowel << endl;
    cout << "���� ���� ������ ���� : " << minVowel << endl;
}