#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

int map[51][51];
bool visited[51][51];
int t;	//테스트케이스 개수
int m, n, k;	//가로, 세로, 배추위치개수
int x, y;
int dx[4] = { 1,0,-1,0 };	//상,하,좌,우 탐색
int dy[4] = { 0,1,0,-1 };
vector<int>answer;


void bfs(int stx, int sty)
{
	queue<pair<int, int>>que;
	que.push({ stx,sty });
	visited[stx][sty] = true;

	while (!que.empty())
	{
		int qx = que.front().first;
		int qy = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++)	//4방향탐색
		{
			int qqx = qx + dx[i];
			int qqy = qy + dy[i];

			if (map[qqx][qqy] != 1)continue;	//배추가없는경우와 이미 방문한 경우 생략
			if (visited[qqx][qqy] == true)continue;

			que.push({ qqx,qqy });
			visited[qqx][qqy] = true;

		}

	}
}

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	for (int i = 0; i < t; i++)
	{	
		fill(&map[0][0], &map[50][51], 0);	//배열초기화
		fill(&visited[0][0], &visited[50][51], false);

		cin >> m >> n >> k;

		for (int j = 0; j < k; j++)
		{
			cin >> x >> y;
			map[y][x] = 1;	//배추위치저장
		}

		int cnt = 0;

		for (int q = 0; q < n; q++)
		{
			for (int w = 0; w < m; w++)
			{
				if (map[q][w] == 1 && visited[q][w] == false)	//방문하지않았으며, 배추가있는위치일경우 탐색
				{
					bfs(q, w);
					cnt++;	//지렁이 개수증가
				}
			}
		}
		answer.push_back(cnt);	//vector에 저장

	}
	


	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << '\n';	//결과출력

	return 0;
}