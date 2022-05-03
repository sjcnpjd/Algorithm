#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int n;	//지도의크기, 지도는 정사각형
int map[26][26];
bool visited[26][26];
int dx[4] = { 1,0,-1,0 };	//상하좌우탐색
int dy[4] = { 0,1,0,-1 };
int cnt = 0;	//총 단지 수
vector<int>v;	//단지내 집의 수

void bfs(int x,int y)
{
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = true;
	map[x][y] = -1;

	int temp = 1;	//입력받은 좌표값부터 시작함으로 temp는 1부터시작, temp는 단지내 집의 수

	while (!q.empty())
	{
		int qx = q.front().first;
		int qy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int qqx = qx + dx[i];
			int qqy = qy + dy[i];

			if (qqx < 0 || qqy < 0 || qqx >= n || qqy >= n)continue;	//범위벗어난경우
			if (visited[qqx][qqy])continue;	//방문한경우
			if (map[qqx][qqy] != 1)continue;	//집이아닌경우

			q.push({ qqx,qqy });
			visited[qqx][qqy] = true;
			map[qqx][qqy] = -1;	//방문한집의 경우 -1로 저장
			temp++;	//집의수 증가

		}

	}

	v.push_back(temp);	//vector에 집의 수 저장
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;	//지도크기입력
	string str;

	for (int i = 0; i < n; i++)	//지도자료입력
	{	
		cin >> str;
		for (int j = 0; j < n; j++)
		{
			map[i][j] = str[j] - '0';	//숫자가연결되어 입력됨으로 string으로 받아서 각각 저장
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1)	//1을만날경우 단지수 증가 및 bfs탐색
			{	
				cnt++;
				bfs(i,j);	//bfs탐색을 한번 수행할때마다 현재위치와 인접한 집을 모두탐색한다.
			}
		}
	}

	cout << cnt << '\n';	//단지수 출력

	sort(v.begin(), v.end());	//오름차순정렬

	for (int i = 0; i < v.size(); i++)	//단지내의 집의 수 각각출력
		cout << v[i] << '\n';

	return 0;
}