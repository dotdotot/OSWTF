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
    // 입력
    string text;
    getline(cin, text, '\n');

    // 구분문자로 자른 문자열이 들어있는 vector
    vector<string> vText = split(text, " ");

    // 반복자 생성
    vector<string>::iterator iter;

    // 가장 긴 문자열 index번호 / 모음의 최대 개수 
    int vectorLongIndex = 0;
    int maxVowel = 0;

    // 가장 짧은 문자열 index 번호 / 모음의 최수 개수
    int vectorShortIndex = 0;
    int minVowel = 0;

    // 출력
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

        // 최대 길이 문자열 index 갱신
        if (vText[vectorLongIndex].length() < t.length())
        {
            vectorLongIndex = index;
        }

        // 최소 길이 문자열 index 갱싱
        if(vText[vectorShortIndex].length() > t.length()){
            vectorShortIndex = index;
        }

        // 최대 모음개수 갱신
        if (maxVowel < g)
        {
            maxVowel = g;
        }
        // 최소 모음개수 갱신
        if(minVowel > g){
            minVowel = g;
        }
        index++;
    }
    cout << "가장 긴 문자열 : " << vText[vectorLongIndex] << endl;
    cout << "가장 짧은 문자열 : " << vText[vectorShortIndex] << endl;
    cout << "가장 많은 모음의 개수 : " << maxVowel << endl;
    cout << "가장 적은 모음의 개수 : " << minVowel << endl;
}