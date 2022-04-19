#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int>v;
    int idx = 0;  //현재숫자위치를 저장할 인덱스 변수

    for (int i = 0; i < dartResult.size(); i++)
    {
        string str = "";
        char temp = dartResult[i];  //현재 문자열값 저장

        if (isdigit(temp))   //정수인 경우
        {
            str += temp;
            if (isdigit(dartResult[i + 1]))    //정수가 2자릿수인 경우
            {
                str += dartResult[i + 1];
                i++;
                v.push_back(stoi(str)); //정수로 변환한 점수를 vector에 push
            }
            else
                v.push_back(stoi(str)); //정수가 1자릿수인 경우

        }
        else if (temp == 'S')  //single인 경우
        {
            if (dartResult[i + 1] != '*' && dartResult[i + 1] != '#') //다음 문자가 *이나 #이 아니라면 인덱스 증가
                idx++;

            continue;
        }
        else if (temp == 'D')  //double인 경우
        {
            v[idx] = v[idx] * v[idx]; //현재 인덱스값의 2제곱을 저장
            if (dartResult[i + 1] != '*' && dartResult[i + 1] != '#')
                idx++;
        }
        else if (temp == 'T')  //triple인 경우
        {
            v[idx] = v[idx] * v[idx] * v[idx];  //현재 인덱스값의 3제곱을 저장

            if (dartResult[i + 1] != '*' && dartResult[i + 1] != '#')
                idx++;
        }
        else if (temp == '*')
        {
            if (v.size() == 1) //저장된 점수가 1개인 경우 현재값만 *2
                v[idx] *= 2;
            else if (v.size() > 1) //그외에 경우 이전인덱스의 값까지 *2
            {
                v[idx] *= 2;
                v[idx - 1] *= 2;
            }
            idx++;
        }
        else if (temp == '#')  //현재인덱스의 값 *-1
        {
            v[idx] *= -1;
            idx++;
        }

    }

    for (int i = 0; i < v.size(); i++) //저장된값들의 합을 answer에 저장
        answer += v[i];

    return answer;
}

//  S -> 1제곱, D -> 2제곱, T -> 3제곱
// *현점수 및 이전 점수 *2, #은 현점수 *-1
// *앞에 점수없으면 현점수만 *2, *점수 중복가능, # 중복가능

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	return 0;
}