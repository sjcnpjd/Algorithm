#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int n;
int temp;
vector<int>v[101];
bool visited[101];

void dfs(int start)
{
	stack<int>s;
	s.push(start);

	while (!s.empty())
	{
		int x = s.top();
		s.pop();

		for (int i = 0; i < v[x].size(); i++)	
		{
			int xx = v[x][i];	

			if (xx == 0)continue;	//xx의 값이 1인경우가 연결된 정점
			if (visited[i])continue;

			s.push(i);	//연결된 인덱스 push 및 방문 표시
			visited[i] = true;

		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;	//정점의 개수 입력

	for (int i = 0; i < n; i++)	//그래프의 인접행렬 입력
	{
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			v[i].push_back(temp);
		}
	}

	for (int i = 0; i < n; i++)	//각인덱스별로 탐색을 하고 방문한 정점을 1로 저장
	{	
		fill(visited, visited+101, false);	//방문을 확인하는 배열 초기화

		dfs(i);	//dfs 탐색

		for (int j = 0; j < n; j++)
		{
			if (visited[j])	//방문한경우
			{
				v[i][j] = 1;	//1저장
			}
		}
	}

	cout << '\n';

	for (int i = 0; i < n; i++)	//결과출력
	{
		for (int j = 0; j < n; j++)
		{
			cout << v[i][j] << " ";
		}
		cout << '\n';
	}


	return 0;
}