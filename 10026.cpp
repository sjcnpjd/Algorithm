#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//R빨 G초 B파
//적록색약은 R G 똑같이

int n;
char map[101][101];
bool visited[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int answer=0;
int answer2=0;

void func(int x, int y, char color, bool check)	//첫번째 매개변수 부터 x,y좌표, 현재구역의색, 적록색약의 여부
{
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty())
	{
		int qx = q.front().first;
		int qy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)	//상하좌우탐색
		{
			int qqx = qx + dx[i];
			int qqy = qy + dy[i];

			if (!check)	//적록색약이 아닌경우
			{
				if (qqx < 0 || qqx >= n || qqy < 0 || qqy >= n)continue;
				if (map[qqx][qqy] != color)continue;
				if (visited[qqx][qqy])continue;

				q.push({ qqx,qqy });
				visited[qqx][qqy] = true;
			}
			else
			{
				if (qqx < 0 || qqx >= n || qqy < 0 || qqy >= n)continue;
				if (visited[qqx][qqy])continue;

				if (color == 'R' || color == 'G')	//적록색약인 경우 
				{
					if (map[qqx][qqy] == 'R' || map[qqx][qqy] == 'G')
					{
						q.push({ qqx,qqy });
						visited[qqx][qqy] = true;
					}
				}
				else
				{
					if (map[qqx][qqy] != color)continue;	//적록색약이지만 현재 영역의 색이 B인 경우
					q.push({ qqx,qqy });
					visited[qqx][qqy] = true;
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

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++)	//적록색약이 아닌 경우 구역의 수
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				func(i, j,map[i][j],false);
				answer++;
			}
		}
	}

	fill(&visited[0][0], &visited[100][101], false);

	for (int i = 0; i < n; i++)	//적록색약인 경우 구역의 수, R과 G를 동일한 영역으로 판단
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				func(i, j, map[i][j],true);
				answer2++;
			}
		}
	}

	cout << answer << " " << answer2;	//결과
	


	return 0;
}