#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int n, m;	//세로, 가로
int map[51][51];	//상어 위치를 저장할 배열
bool visited[51][51];	//방문여부를 저장할 배열
int num, result;
int xarr[8] = { 1,0,-1,0,1,-1,1,-1 };	//대각선포함하여 8방향을 탐색하기위한 배열
int yarr[8] = { 0,1,0,-1,1,-1,-1,1 };

typedef struct
{
	int x;	
	int y;
	int c;
}node;	//queue에 사용할 구조체

int bfs(int a, int b)	//bfs함수
{	
	fill(&visited[0][0], &visited[50][51], false);	//방문여부를 저장하는 배열 초기화
	queue<node>q;	//queue 선언
	visited[a][b] = true;	//매개변수로 받은 위치 방문표시
	q.push({ a,b,0 });	//매개변수로 받은 a, b와 0을 push, 0은 거리

	while (!q.empty())
	{
		int qx = q.front().x;	//queue의 front 값 저장
		int qy = q.front().y;
		int qc = q.front().c;

		q.pop();	//저장한 값 queue에서 삭제

		for (int i = 0; i < 8; i++)	//8방향탐색을 위한 반복문
		{
			int qx2 = qx + xarr[i];
			int qy2 = qy + yarr[i];

			if (qx2<0 || qy2 < 0 || qx2>=n || qy2 >=m)continue;	//맵을벗어날경우 continue
			if (visited[qx2][qy2] == true)continue;	//이미 방문한 경우 continue

			if (map[qx2][qy2] == 1)	//상어위치일 경우 거리에 1을 더하고 반환
				return qc + 1;

			visited[qx2][qy2] = true;	//방문표시
			q.push({ qx2,qy2,qc + 1});	//현재위치 및 거리에 1을 더한 값을 queue에 push, 
			
		}

	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;	//n, m 입력
	num = 0;	
	result = 0;	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];	//map 입력
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)	//상어가없는 위치일경우
			{
				num = bfs(i, j);	//bfs탐색후 반환값을 num에 저장
				result = max(result, num);	//반환값중 가장 큰수 result에 저장
			}
		}
	}
	cout << result;	//결과출력

	return 0;
}