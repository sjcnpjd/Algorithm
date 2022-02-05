#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

long long a, b;	
int cnt = 1;	//연산의 최솟값을 저장할 변수

void dfs(long long num)
{
	stack<pair<long, int>>s;	//stack 선언
	s.push(make_pair(num, cnt));	//stack에 a와 cnt를 push

	while (!s.empty())	//stack이 비어있지않다면 반복
	{	
		long long x = s.top().first;	//stack의 top을 각각 저장
		int y = s.top().second;
		s.pop();	//저장한 값 stack에서 삭제

		long long x1 = x * 2;	//2를 곱하는 변수
		long long x2 = x * 10 + 1;	//1을 수의 가장 오른쪽에 추가하는 변수

		if (x1 == b || x2 == b)	//b와 같은 경우 출력후 종료
		{	
			cout << y+1;
			return;
		}

		if (x1 < b)	//b보다 작다면	stack에 2를 곱한 값 및 cnt 변수에 1을 더한 후 push
		{
			s.push(make_pair(x1, y + 1));
		}
		if (x2 < b)
		{
			s.push(make_pair(x2, y + 1));
		}

	}

	cout << -1;	//d
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> a >> b;	//a와 b입력

	dfs(a);	//dfs함수에 a를 매개변수로 전달

	return 0;
}