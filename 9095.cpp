#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int t, n;
vector<int>result;	//결과를 저장할 vector
int arr[3] = { 1,2,3 };	//1,2,3을 더할때 사용될 배열
int num;	//각케이스별 방법의 수를 저장할 변수

int dfs(int a, int r)
{	
	num = 0;	//방법의수 초기화
	stack<int>s;	//stack 선언
	s.push(a);	

	while (!s.empty())
	{
		int x = s.top();	//stack의 top 값 저장
		s.pop();	//저장한값 삭제

		if (x == r)	//x가 입력받은 숫자일 경우 방법의수 증가
		{
			num++;
		}

		for (int i = 0; i < 3; i++)	//1,2,3을 각각 더하고 stack에 push
		{
			int ax = x + arr[i];	

			if (ax<0 || ax>r)continue;	//0보다 작거나 입력받은수보다 클경우 continue

			s.push(ax);
		}
	}
	return num;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;	//테스트케이스의 개수 입력
	
	for (int i = 0; i < t; i++)
	{
		cin >> n;	//정수 n 입력
		result.push_back(dfs(0, n));	//함수 호출후 반환되는 결과를 result에 push
	}

	for (int i = 0; i < t; i++)	//결과출력
		cout << result[i] << '\n';

	return 0;
}