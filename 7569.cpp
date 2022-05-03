#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

//1익은토마토, 0익지않은토마토, -1비어있는칸
//저장될때부터 익어있으면 0 출력, 모두 익지못하는 상황이면 -1 출력

typedef struct
{
	int x;
	int y;
	int z;
}node;

int n, m, h;	//세로,가로,높이 칸수
int map[101][101][101];
bool visited[101][101][101];

int dx[6] = { 0,0,0,0,1,-1 };
int dy[6] = { 0,1,0,-1,0,0 };
int dz[6] = { 1,0,-1,0,0,0 };

int answer = 0;
int num = 0;
int num2 = 0;
vector<node>start;

void bfs()
{
	queue<node>q;

	for (int i = 0; i < start.size(); i++)	//익은토마토 위치를 queue에 push
	{
		q.push({ start[i].x, start[i].y, start[i].z });
		visited[start[i].x][start[i].y][start[i].z] = true;	//방문표시
	}

	while (!q.empty())
	{
		int qx = q.front().x;
		int qy = q.front().y;
		int qz = q.front().z;
		q.pop();

		for (int i = 0; i < 6; i++)	//위,아래,앞,뒤,오른쪽,왼쪽 총 6방향 탐색
		{
			int qqx = qx + dx[i];
			int qqy = qy + dy[i];
			int qqz = qz + dz[i];

			if (visited[qqx][qqy][qqz])continue;	//방문한경우
			if (qqx < 0 || qqy < 0 || qqz < 0 || qqx >= h || qqy >= n || qqz >= m)continue;	//범위를 벗어난 경우
			if (map[qqx][qqy][qqz] != 0)continue;	//익지않은 토마토가 아닌경우

			q.push({ qqx,qqy,qqz });
			visited[qqx][qqy][qqz] = true;
			map[qqx][qqy][qqz] += map[qx][qy][qz] + 1;	//기존의 날짜에서 1을더한값 저장

		}

	}


}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> h;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> map[i][j][k];

				if (map[i][j][k] == 1)
				{
					num++;
					start.push_back({ i,j,k });	//익은토마토 위치 vector에 저장
				}
				else if (map[i][j][k] == -1)
					num2++;
			}
		}
	}

	if ((n * m * h) - num2 == num)	//저장될때부터 모든토마토가 익은경우, num2는 비어있는칸의 개수이기때문에 제외
	{
		cout << "0";
	}
	else
	{
		bfs();	//bfs탐색
		bool check = true;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < m; k++)
				{
					if (map[i][j][k] == 0)	//익지않은 토마토가 존재하는경우
					{
						check = false;
						break;
					}

					if (map[i][j][k] > answer)
						answer = map[i][j][k];	//며칠이 걸리는지 알기위해서 배열에 저장된값중 가장 큰 수 저장
				}
				
			}
		}

		if (check)	//날짜를 계산할때 1일부터 시작하였기때문에 -1 하고 출력
			cout << answer-1;
		else
			cout << "-1";	//익지않은 토마토가 존재하는 경우임으로 -1출력


	}

	//for (int i = 0; i < h; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		for (int k = 0; k < m; k++)
	//		{
	//			cout << map[i][j][k] << " ";
	//		}
	//		cout << '\n';
	//	}
	//}

	return 0;
}