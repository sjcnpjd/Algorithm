#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <string>


using namespace std;

int n;
vector<int>vec;
vector<int>tempvec;
int temp;
int maxNum = -100000000;
int minNum = 100000000;
int pl, mi, mu,di;
string op = "";

int cal(int a, int b, char o)   //각각의 연산을하는 함수
{
    if (o == '+')
        return a + b;
    else if (o == '-')
        return a - b;
    else if (o == '*')
        return a * b;
    else if (o == '/')
        return a / b;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n;   //수의개수

    for (int i = 0; i < n; i++) //수를 입력받는 반복문
    {
        cin >> temp;
        vec.push_back(temp);    //vector에 저장
    }

    cin >> pl >> mi >> mu >> di;    //첫번째 변수부터 +, - ,* , / 연산자의 개수를 입력받음

    for (int i = 0; i < pl; i++)    //각각의 연산자를 op문자열에 저장
        op += '+';
    for (int i = 0; i < mi; i++)
        op += '-';
    for (int i = 0; i < mu; i++)
        op += '*';
    for (int i = 0; i < di; i++)
        op += '/';

    sort(op.begin(), op.end()); //op문자열 오름차순저장, next_permutation은 내림차순으로 정렬하며 수열을출력하기때문에

    //next_permutation 함수를 사용하여 op문자열의 수열을 활용

    do {
        int num = 0;
        tempvec.clear();    //임시vector 초기화

        for (int i = 0; i < vec.size(); i++)    //입력받은 정수를 tempvec에 저장
            tempvec.push_back(vec[i]);

        for (int i = 0; i < op.size(); i++) //op의 저장된 연산자들을 사용하여 계산
        { 
          if (tempvec.size() == 1)break;    //vector의 값이 한개가 남으면 계산이 끝난것이기에 종료

          tempvec[0] = cal(tempvec[0], tempvec[1], op[i]);  //0번인덱스에 저장하고
          tempvec.erase(tempvec.begin() + 1);       //1번인덱스 삭제
        }

        num = tempvec[0];

        if (num > maxNum)   //최대값보다 크다면 저장
            maxNum = num;

        if (num < minNum)   //최소값보다 작다면 저장
            minNum = num;

    } while (next_permutation(op.begin(), op.end()));


    cout << maxNum << '\n' << minNum;   //출력

    return 0;
}