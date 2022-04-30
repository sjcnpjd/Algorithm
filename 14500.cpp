#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int n, m;
int map[501][501];
bool visited[501][501];
int result = 0;
int dx[4] = { -1,0,0,1 };	//상하좌우탐색을 위한 배열
int dy[4] = { 0,-1,1,0 };

int func2(int x, int y)	//func 함수들은 ㅗ,ㅏ,ㅓ,ㅜ 모양의 테트로미노의 값을 확인
{
	return map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y - 1];
}

int func3(int x, int y)
{
	return map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y + 1];
}

int func4(int x, int y)
{
	return map[x][y] + map[x][y + 1] + map[x][y - 1] + map[x - 1][y];
}

int func5(int x, int y)
{
	return map[x][y] + map[x][y + 1] + map[x][y - 1] + map[x + 1][y];
}

void dfs(int x, int y, int cnt, int num)
{	
	visited[x][y] = true;

	if (cnt == 4)	//cnt가 4일경우 테트로미노 하나만큼 탐색한 것이기에 값을 확인
	{
		if (result < num)
			result = num;

		return;
	}
	
	for (int i = 0; i < 4; i++)
	{	
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;	//범위를 벗어난 경우
		if (visited[nx][ny])continue;	//이미 방문한 경우

		visited[nx][ny] = 1;
		dfs(nx, ny, cnt + 1, num + map[nx][ny]);	//재귀
		visited[nx][ny] = 0;
	}

	int s2, s3, s4, s5;

	if (x + 2 < n && y - 1 >= 0)
	{
		s2 = func2(x, y);

		if (result < s2)
			result = s2;
	}

	if (x + 2 < n && y + 1 < m)
	{
		s3 = func3(x, y);

		if (result < s3)
			result = s3;
	}

	if (x - 1 >= 0 && y - 1 >= 0 && y + 1 < m)
	{
		s4 = func4(x, y);

		if (result < s4)
			result = s4;
	}

	if (x + 1 < n && y + 1 < m && y - 1 >= 0)
	{
		s5 = func5(x, y);

		if (result < s5)
			result = s5;
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;	//세로,가로 크기 입력

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];	//map의 숫자 입력

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = 1;	
			dfs(i, j,1,map[i][j]);	//재귀함수를 활용하여 탐색
			visited[i][j] = 0;	
		}
	}

	cout << result;	//결과출력

	return 0;
}