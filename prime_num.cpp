#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


int solution(string numbers) {
    int answer = 0;
    int temp;
    set<int>s;  //set을 사용하여 중복되는 숫자방지

    for (int i = 0; i < numbers.size(); i++)    //numbers에서 한자리 수 이면서 소수인것을 찾는 반복문
    {
        vector<int>v;
        int n;
        temp = numbers[i] - '0';    //정수로 변환

        if (temp == 0)continue; //0,1일 경우 continue
        if (temp == 1)continue;
       
        for (int i = 2; i <= temp; i++)
        {
            if (temp % i == 0)  //2부터 temp값사이에서 나머지가 0일 경우, 반복문 종료
            {
                n = i;
                break;
            }
        }
        if (temp == n)  //나머지가 0이 되는 수가 temp값과 같다면 소수
            s.insert(n);    //set에 insert
        

    }

    sort(numbers.begin(), numbers.end());   //next_permutation을 하기전에 오름차순으로 정렬

    do
    {
        vector<int>v2;
        string str;
        v2.push_back(stoi(numbers));    //최대자리수인 값 v2에 push

        for (int i = 2; i < numbers.size(); i++)
        {
            str = numbers.substr(1, i); //각 자릿수를 별로 확인하기위해서 문자열 자르기
            temp = stoi(str);           //ex)입력값이 1234일 경우, 1234의 순열뿐만아니라 23,234와 같은 수 역시 확인해야하기때문에
            v2.push_back(temp);
        }

        for (int k = 0; k < v2.size(); k++) //v2에 저장된 각 수들이 소수인지 확인하는 반복문
        {
            temp = v2[k];
            int num;

            for (int i = 2; i <= temp; i++)
            {
                if (temp % i == 0)
                {
                    num = i;
                    break;
                }
            }

            if (temp == num)
                s.insert(num);
            
        }

    } while (next_permutation(numbers.begin(), numbers.end()));


    answer = s.size();  //set의 size가 소수의 개수

    return answer;
}


int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);


    return 0;
}