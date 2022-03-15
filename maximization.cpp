#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

long long cal(long long lla, long long llb, char op)    // +, -, *
{
    if (op == '+')
        return lla + llb;
    else if (op == '*')
        return lla * llb;
    else if (op == '-')
        return lla - llb;

}

long long solution(string expression) {
    long long answer = 0;

    string temp = "";
    vector<long long>sum;   //우선순위에 따른 계산후 각 결과값들 저장할 배열
    bool check[3] = { false,false,false };

    for (int i = 0; i < expression.size(); i++) //연산문자 종류 저장
    {
        if (expression[i] == '*' && !check[0])
        {
            temp += "*";
            check[0] = true;
        }
        else if (expression[i] == '+' && !check[1])
        {
            temp += "+";
            check[1] = true;
        }
        else if (expression[i] == '-' && !check[2])
        {
            temp += "-";
            check[2] = true;
        }
    }

    sort(temp.begin(), temp.end()); //연산기호 저장문자열 오름차순정렬
    //next_permutation함수는 오름차순으로 정렬된 배열,문자열을 순열을 출력하며, 내림차순으로정렬

    do {
        queue<char>q_num;   //숫자저장을 위한 큐

        vector<char>v_op;   //연산문자 저장
        vector<long long> vecll;    //숫자저장
        long long ans_num = 0;  //결과값 저장

        for (int i = 0; i < expression.size(); i++) //문자열의 숫자와 연산을 분리하여 vector에 저장
        {
            if (isdigit(expression[i])) //숫자일 경우
                q_num.push(expression[i]);

            else if (!isdigit(expression[i]))   //숫자가아닌 경우
            {
                long long templl;
                string tempStr = "";
                v_op.push_back(expression[i]);  //연산문자저장

                while (!q_num.empty())
                {
                    tempStr += q_num.front();
                    q_num.pop();
                }
                templl = stoll(tempStr);    //long long으로 변환 후 저장
                vecll.push_back(templl);
            }

            if (i == expression.size() - 1) //마지막 인덱스인 경우, 숫자저장
            {
                long long templl2;
                string tempStr2 = "";

                while (!q_num.empty())
                {
                    tempStr2 += q_num.front();
                    q_num.pop();
                }
                templl2 = stoll(tempStr2);
                vecll.push_back(templl2);
            }
        }

        for (int i = 0; i < temp.size(); i++)   //우선순위에 따라 계산
        {

            for (int j = 0; j < v_op.size(); j++)
            {
                if (v_op[j] == temp[i]) //우선연산문자와 현재 연산문자가 같은경우
                {   
                    vecll[j] = cal(vecll[j], vecll[j + 1], temp[i]);    //계산후 값을 vector의 j인덱스에 저장
                    vecll.erase(vecll.begin() + (j + 1));   //vector의 j+1 삭제
                    v_op.erase(v_op.begin() + j);   //사용한 연산문자 삭제
                    j--;    //v_op의 개수가 줄었기때문에 j값 감소, 안하면 이후의 연산이 있음에도 반복문이 종료되는 경우발생 
                }
                
            }
        }

        ans_num = llabs(vecll[0]);
        sum.push_back(ans_num);

    } while (next_permutation(temp.begin(), temp.end()));

    sort(sum.begin(), sum.end());   //오름차순정렬
    answer = sum[sum.size() - 1];   //최대값 answer저장

    return answer;
}



int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    string resu = "100-200*300-500+20";

    long long sol = solution(resu);

    cout << sol;


    return 0;
}