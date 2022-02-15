#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define MAX 8

int n, m;
vector<int>v;	//결과를 저장할 vector

void dfs(int cnt)	//매개변수는 한줄마다 자연수의 개수
{
	if (cnt == m)	//cnt가 m이랑 같은 경우,자연수 m개를 고른경우
	{
		for (int i = 0; i < m; i++)	//vector에 저장된 결과 출력
			cout << v[i] << " ";

		cout << '\n';
	}
	else
	{
		for (int i = 1; i <= n; i++)	//1부터 n까지 반복문
		{	
			v.push_back(i);	//vector에 push
			dfs(cnt + 1);	//cnt증가후 재귀
			v.pop_back();	//vector값 삭제
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;	//자연수 n, m 입력

	dfs(0);	//dfs함수호출

	return 0;
}