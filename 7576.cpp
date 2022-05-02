#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <deque>

using namespace std;

int n, m;
int map[1001][1001];	//map
bool visited[1001][1001];	//방문여부배열
vector<pair<int, int>>start;	//익은 토마토 저장하는 vector
int answer = 0;	//정답저장할 변수

int dx[4] = { 1,0,-1,0 };	//상하좌우탐색을 위한 배열
int dy[4] = { 0,1,0,-1 };
bool check = true;

void bfs()
{
	queue<pair<int, int>>q;
	
	for (int i = 0; i < start.size(); i++)	//익은 토마토들의 좌표 queue에 push
	{
		int x = start[i].first;
		int y = start[i].second;

		q.push({ x,y });
		visited[x][y] = true;
	}

	while (!q.empty())
	{
		int qx = q.front().first;
		int qy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int qqx = qx + dx[i];
			int qqy = qy + dy[i];

			if (visited[qqx][qqy])continue;	//이미 방문한경우
			if (qqx < 0 || qqy < 0 || qqx >= n || qqy >= m)continue;	//범위를 벗어난경우
			if (map[qqx][qqy] != 0)continue;	//익지않은토마토가 아닌경우

			q.push({ qqx,qqy });
			map[qqx][qqy] += map[qx][qy]+1;	//날짜를 구해야하기때문에 다음범위로 이동할때마다 이전값에서 1씩증가한 값 저장
			visited[qqx][qqy] = true;
		}

		//cout << '\n';

		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < m; j++)
		//	{
		//		cout << map[i][j] << " ";
		//	}
		//	cout << '\n';
		//}

	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;	//가로,세로칸의 수

	int cnt = 0;	//익은토마토칸 개수저장
	int cnt2 = 0;	//토마토가들어있지않은칸 개수저장

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];	//토마토 정보입력

			if (map[i][j] == 1)
			{
				start.push_back({ i,j });	//익은토마토 vector에 저장
				cnt++;
			}
			else if (map[i][j] == -1)
				cnt2++;

		}
	}

	if ((m * n) - cnt2 == cnt)	//저장될때부터 모든토마토가 익어있는 상태인지 확인
		cout << "0";
	else
	{
		bfs();	//bfs탐색

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{	
				if (map[i][j] == 0)	//탐색후 익지않은 토마토가 존재한다면 모두 익지 못하는 상태
					check = false;
				else
				{
					if (answer < map[i][j])	//모든토마토가 익는데 걸린날짜는 map에 저장된값 중 가장 큰값
						answer = map[i][j];
				}
			}
		}
		if (check)
			cout << answer - 1;	//배열내에서 시작값이 0이 아닌1임으로 -1을 한 결과 출력
		else
			cout << "-1";	//모두 익지 못하는 상태

	}

	

	return 0;
}