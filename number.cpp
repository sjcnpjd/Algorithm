#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int solution(string s) {
    int answer = 0;
    string temp = "";
    
    for (int i = 0; i < s.size(); i++)
    {
        int n;
        if (!isdigit(s[i]))  //문자열에 숫자가 아닌 문자가 존재한다면, find를 사용하여 어떤 영단어가 존재하는지 확인
        {                       //존재한다면 영단어는 문자열에서 삭제하고 영단어의 시작위치에 해당 숫자를 추가
            if (s.find("zero") != -1)
            {
                n = s.find("zero");
                s.erase((s.begin() + n), (s.begin() + n + 3));
                s[n] = '0';
            }
            if (s.find("one") != -1)
            {
                n = s.find("one");
                s.erase((s.begin()+n), (s.begin() + n+2));
                s[n] = '1';
            }
            if (s.find("two") != -1)
            {
                n = s.find("two");
                s.erase((s.begin() + n), (s.begin() + n + 2));
                s[n] = '2';
            }
            if (s.find("three") != -1)
            {
                n = s.find("three");
                s.erase((s.begin() + n), (s.begin() + n + 4));
                s[n] = '3';
            }
            if (s.find("four") != -1)
            {
                n = s.find("four");
                s.erase((s.begin() + n), (s.begin() + n + 3));
                s[n] = '4';
            }
            if (s.find("five") != -1)
            {
                n = s.find("five");
                s.erase((s.begin() + n), (s.begin() + n + 3));
                s[n] = '5';
            }
            if (s.find("six") != -1)
            {
                n = s.find("six");
                s.erase((s.begin() + n), (s.begin() + n + 2));
                s[n] = '6';
            }
            if (s.find("seven") != -1)
            {
                n = s.find("seven");
                s.erase((s.begin() + n), (s.begin() + n + 4));
                s[n] = '7';
            }
            if (s.find("eight") != -1)
            {
                n = s.find("eight");
                s.erase((s.begin() + n), (s.begin() + n + 4));
                s[n] = '8';
            }
            if (s.find("nine") != -1)
            {
                n = s.find("nine");
                s.erase((s.begin() + n), (s.begin() + n + 3));
                s[n] = '9';
            }

        }
    }

    answer = stoi(s);

   
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    string t = "one23";
    int sol = solution(t);

    cout << sol;

    return 0;
}