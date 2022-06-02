#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <deque>


using namespace std;

int map[101][101];
bool visited[101][101];
int m, n, k;	//세로,가로,직사각형 개수
vector<int>v;
int answer = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int check = 2;


int t1, t2, t3, t4;	//왼쪽아래 xy, 오른쪽위 xy
//ex 왼쪽(0,2) , 오른쪽(4,4) -> 0,2 - 0,3 - 1,2 -1,3 - 2,2 - 2,3 - 3,2 - 3,3

typedef struct
{
	int tx;
	int ty;
}node;


void bfs(int x, int y)
{
	queue<node>q;
	q.push({ x,y});
	visited[x][y] = true;	//방문표시
	map[x][y] = check;	//map에 분리된영역표시

	while (!q.empty())
	{
		int qx = q.front().tx;
		int qy = q.front().ty;
		q.pop();

		for (int i = 0; i < 4; i++)	//상,하,좌,우 탐색
		{
			int qqx = qx + dx[i];
			int qqy = qy + dy[i];

			if (visited[qqx][qqy])continue;	//방문한경우
			if (qqx < 0 || qqx >= m || qqy < 0 || qqy >= n)continue;	//map를 벗어난 경우

			if (map[qqx][qqy] == 0)	
			{
				q.push({ qqx,qqy});
				visited[qqx][qqy] = true;
				map[qqx][qqy] = check;

			}

		}

	}
	int cnt = 0;

	for (int i = 0; i < m; i++)	//넓이 확인
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == check)
				cnt++;
		}
	}
	
	v.push_back(cnt);	//저장 후 check 값 증가
	check++;

}

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> m >> n >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> t1 >> t2 >> t3 >> t4;	//직사각형의 꼭짓점 입력

		for (int j = t2; j < t4; j++)	//직사각형 영역을 1로 저장
		{
			for (int k = t1; k < t3; k++)
			{
				map[j][k] = 1;
			}
		}
	}


	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 0 && !visited[i][j])	//직사각형 영역이 아니면서 방문하지 않은 좌표일 경우
			{
				answer++;	//분리된 영역의 개수 증가
				bfs(i, j);	//bfs탐색
			}
		}
	}

	cout << answer << '\n';	//분리된 영역의 개수

	sort(v.begin(), v.end());	//오름차순정렬

	for (int i = 0; i < v.size(); i++)	//분리된영역의 넓이 출력
		cout << v[i] << " ";

	return 0;
}