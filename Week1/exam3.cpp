#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

// 평균 문자열 개수 / 평균 모음 개수

// java의 split 구현
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

// 모음인지 확인
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
    // 입력
    string text;
    getline(cin, text, '\n');

    // 구분문자로 자른 문자열이 들어있는 vector
    vector<string> vText = split(text, " ");

    // 반복자 생성
    vector<string>::iterator iter;

    // 모음의 최대 개수 / 가장 긴 문자열 index번호
    int vectorIndex = 0;
    int maxGather = 0;

    // 평균 문자열 길이 변수 / 평균 모음 개수
    double averageLength = 0;
    double averageGather = 0;

    // 출력
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

        // 최대 길이 문자열 index 갱신
        if (vText[vectorIndex].length() < t.length())
        {
            vectorIndex = index;
        }

        // 최대 모음개수 갱신
        if (maxGather < maxGather2)
        {
            maxGather = maxGather2;
        }

        averageLength += t.length();
        averageGather += maxGather2;
        index++;
    }
    // 평균 갱신
    averageLength = averageLength / vText.size();
    averageGather = averageGather / vText.size();

    cout << "가장 긴 문자열 : " << vText[vectorIndex] << endl;
    cout << "가장 많은 모음의 개수 : " << maxGather << endl;

    cout << "평균 문자열 길이 : " << averageLength << endl;
    cout << "평균 모음 개수 : " << averageGather << endl;
}