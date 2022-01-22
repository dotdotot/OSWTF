#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 앞에서 읽으나 뒤에서 읽으나 같은 수를 팔린드롬 수 라고 한다.
// 예를 들어서 두 자리로 이루어진 팔린드롬 수는 11, 22, 33, 44, 55, 66, 77, 88, 99의 9개가 있다.
// A이상 B이하의 정수 중에서 팔린드롬 수를 모두와 총갯수를 출력하는 프로그램을 작성하라.
// A와 B는 입력을 받는다.

// 팰린드롬의 수를 구하는 함수
vector<int> palindromeNum(int a, int b)
{
    vector<int> num;
    // a~b까지 반복
    for (int i = a; i <= b; i++)
    {
        // i를 문자열로 만들어 text에 저장
        string text = to_string(i);
        vector<char> vectorText;

        for (int ii = 0; ii < text.length(); ii++)
        {
            vectorText.push_back(text[ii]);
        }

        bool check = false;

        // 한자리 정수는 모두 팰린드롬 수
        if (vectorText.size() == 1)
        {
            check = true;
        }
        // 두자리 이상 정수는 검사
        else
        {   
            // vectorText.size() / 2만큼만 반복하는 이유 -> 중앙에 있는 숫자는 반대에서 읽어도 동일한 위치에 존재
            // 그러므로 size / 2만큼만 반복(정수로 변환되므로 소수점은 자동으로 잘려나감)
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
    // 최소값 a와 최대값 b입력
    int A, B;
    cin >> A >> B;

    // v에는 팰린드롬의 수들이 삽입되어있음
    vector<int> v = palindromeNum(A, B);
    // 반복자 생성
    vector<int>::iterator iter;

    // a이상 b이하의 팰린드롬의 수 출력
    for (iter = v.begin(); iter != v.end(); iter++)
    {
        cout << *iter << " ";
    }

    // 총 개수 출력
    cout << endl
         << "팰린드롬 수의 총 개수 : " << v.size() << endl;
    return 0;
}