#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

char map[101][101];	//미로를 입력받을 배열
bool visited[101][101] = {false,};	//방문을 확인하는 배열
int check[101][101] = {0,};	//칸을세기위한 배열
int n, m;
int xp[4] = { 1,-1,0,0 };	//서로인접한 칸들을 탐색하기 위한 배열 남,북,동,서 순서
int yp[4] = { 0,0,1,-1 };


void bfs(int a, int b)	//bfs
{	
	visited[a][b] = true;	//시작점인 0,0을 방문
	queue<pair<int, int>>q;	//queue 선언
	q.push(make_pair(a, b));	//시작점을 큐에 push

	while (!q.empty())	//queue가 빌때까지 반복
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();	//x,y에 넣은 값들을 가지고 있던 queue를 삭제

		for (int i = 0; i < 4; i++)	//인접한 주변칸 4칸씩 탐색
		{
			int nx = x + xp[i];
			int ny = y + yp[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m)	//미로를 벗어나는지 확인하는 조건문
			{
				if (map[nx][ny] == '1' && visited[nx][ny] == 0)	//미로에서 갈 수있는 칸 즉 '1' 이면서, 방문하지 않은 칸이라면
				{
					check[nx][ny] = check[x][y] + 1;	//check[x][y]에 1을 더한 값을 현재 탐색하는 칸인 [nx][ny]에 더한다.
					visited[nx][ny] = 1;	//방문표시
					q.push(make_pair(nx, ny));	//큐에 현재 칸을 push 한다
				}
			}

		}

	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;	//n과 m 입력받기 n * m 의 배열로 표현되는 미로

	char temp;
	string str;

	for (int i = 0; i < n; i++)	//배열입력을 위한 반복문
	{	
		cin >> str;	//수들이 붙어서 입력되기때문에 문자열로 받은후
		for (int j = 0; j < m; j++)	// 각각 저장
		{
			temp = str[j];
			map[i][j] = temp;
		}
	}


	bfs(0, 0);	//bfs

	cout << check[n - 1][m - 1] + 1;	//결과값출력

	return 0;
}
