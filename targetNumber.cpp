#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

int res = 0;  //결과값 저장할 배열

typedef struct
{
    int num;    //현재값을 저장할 변수
    int cnt;    //현재 인덱스를 저장할 변수
}node;

void func(int start, vector<int> v, int t)
{
    stack<node>s;
    s.push({ start,0 });  //첫번째값 앞에 -,+ 가 있는 경우를 각각 push, 인덱스는 0부터
    s.push({ start * -1,0 });

    while (!s.empty())
    {
        int snum = s.top().num;
        int scnt = s.top().cnt;
        s.pop();

        if (scnt >= v.size()) //인덱스가 vector의 사이즈와 같거나 큰 경우 continue
            continue;

        //cout<<snum<<" "<<scnt<<'\n';

        if (snum == t && scnt == v.size() - 1)  //target과 현재값이 동일하고 마지막 인덱스까지 계산한 경우
        {
            res++;  //결과값 증가
            continue;
        }


        scnt++; //인덱스 증가
        s.push({ snum + v[scnt], scnt });   //다음인덱스의 값을 더하기 및 빼기
        s.push({ snum - v[scnt], scnt });

    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    func(numbers[0], numbers, target); //첫번째 인덱스의 값 부터 탐색시작

    answer = res;    //결과 저장

    return answer;
}

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	


	return 0;
}