#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int>v1 = { 1,2,3,4,5 };    //1번 수포자 방식
    vector<int>v2 = { 2, 1, 2, 3, 2, 4, 2, 5 };   //2번 수포자 방식
    vector<int>v3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 }; //3번 수포자 방식

    int count[3] = { 0,0,0 };   //맞힌 문제수 저장할 배열

    int maxNum = 0;   //최대점수저장할 변수

    for (int i = 0; i < answers.size(); i++)
    {
        if (i >= v1.size())    //각 vector의 사이즈를 넘어갈 경우 vector의 마지막에 해당 vector를 추가로 삽입
            v1.insert(v1.end(), v1.begin(), v1.end());

        if (i >= v2.size())
            v2.insert(v2.end(), v2.begin(), v2.end());

        if (i >= v3.size())
            v3.insert(v3.end(), v3.begin(), v3.end());


        if (answers[i] == v1[i])   //정답과 일치하는지확인하고, 일치한다면 정답 수 증가
            count[0]++;
        if (answers[i] == v2[i])
            count[1]++;
        if (answers[i] == v3[i])
            count[2]++;
    }

    for (int i = 0; i < 3; i++)    //최대 점수값 저장하는 반복문
    {
        if (maxNum < count[i])
            maxNum = count[i];
    }

    for (int i = 0; i < 3; i++)    //각 학생들의 점수와 비교하여 answer에 저장
    {
        if (maxNum == count[i])
            answer.push_back(i + 1);
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);


    return 0;
}