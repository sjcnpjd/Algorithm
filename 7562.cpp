#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t;	//테스트 케이스 개수
int n;	//한변의 길이
int nx, ny;	//나이트의 위치
int rx, ry;	//목적지의 위치
int map[301][301];
bool visited[301][301];
vector<int>v;
int dx[8] = { 2,1,-1,-2,-2,-1,1,2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };

typedef struct
{
	int tx;
	int ty;
	int tcnt;
}node;


int func(int x, int y)
{
	queue<node>q;
	q.push({ x,y,0 });
	visited[x][y] = true;

	while (!q.empty())
	{
		int qx = q.front().tx;
		int qy = q.front().ty;
		int qcnt = q.front().tcnt;
		q.pop();


		if (qx == rx && qy == ry)
			return qcnt;


		for (int i = 0; i < 8; i++)
		{
			int qqx = qx + dx[i];
			int qqy = qy + dy[i];

			if (qqx < 0 || qqx >= n || qqy < 0 || qqy >= n)continue;
			if (visited[qqx][qqy])continue;

			q.push({ qqx,qqy,qcnt + 1 });
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
		fill(&map[0][0], &map[300][301], 0);
		fill(&visited[0][0], &visited[300][301], false);

		cin >> n;
		cin >> nx >> ny;
		cin >> rx >> ry;

		map[rx][ry] = 1;

		if (nx == rx && ny == ry)
		{
			v.push_back(0);
			continue;
		}
		else
		{
			int temp = func(nx, ny);
			v.push_back(temp);

		}
		
	}

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';

	return 0;
}