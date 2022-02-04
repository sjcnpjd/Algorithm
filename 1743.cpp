#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int n, m, k;
char map[101][101];	//map을 저장할 배열
bool visited[101][101];	//방문여부를 저장할 배열
int xarr[4] = { 1,0,-1,0 };	//북,동,남,서 방향을 탐색할때 사용될 배열
int yarr[4] = { 0,1,0,-1 };
int x, y;	//쓰레기 위치를 입력받은 변수
int result;	//쓰레기 수를 count할 변수
int maxnum=0;	//가장 큰 쓰레기수를 저장할 변수


void dfs(int a, int b)	//dfs 함수
{	
	result = 1;	//쓰레기가 있는 좌표일 경우 이 함수가 시작되기에 쓰레기수는 1부터 시작
	char temp = map[a][b];	

	visited[a][b] = true;	//현재위치 방문 표시
	stack<pair<int, int>>s;	//stack 선언
	s.push(make_pair(a, b));	//stack에 현재위치 push

	while (!s.empty())	//stack이 비어있지않다면 반복
	{
		int xpos = s.top().first;	//stack의 top 값을 각각 저장
		int ypos = s.top().second;
		s.pop();	//저장한 값 stack에서 삭제

		for (int i = 0; i < 4; i++)	//4가지방향을 탐색하는 반복문
		{
			int xpos2 = xpos + xarr[i];
			int ypos2 = ypos + yarr[i];

			if (0 <= xpos2 && xpos2 <= n && 0 <= ypos2 && ypos2 <= m)	//map을 벗어나지않는 경우
			{
				if (visited[xpos2][ypos2] == false && map[xpos2][ypos2] == temp)	//방문하지않은 좌표이며, x가 저장된 좌표일경우
				{
					visited[xpos2][ypos2] = true;	//방문표시
					result++;	//쓰레기수 1을더한다
					s.push(make_pair(xpos2, ypos2));	//stack에 push
				}
				
			}
		}
	}

	if (result > maxnum)	//maxnum보다 현재 쓰레기 수가 더 많은경우
			maxnum = result;	//maxnum에 result저장

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;	//세로길이 n, 가로길이 m, 쓰레기의 개수 k를 입력


	for (int i = 0; i < k; i++)	//쓰레기 개수만큼 좌표를 입력받는 반복문
	{
		cin >> x >> y;
		map[x][y] = 'x';	//쓰레기가 있는 좌표에 x를 저장
	}

	for (int i = 0; i <= n; i++)	//map의 모든 좌표를 확인하는 반복문
	{
		for (int j = 0; j <= m; j++)
		{	
			if (visited[i][j] == false)	//아직 방문하지 않은 좌표일경우
			{
				if (map[i][j] == 'x')	//map의 좌표에 x가 저장되어 있다면
				{
					dfs(i, j);	//dfs 탐색
				}
			}
		}
	}

	cout << maxnum;	//결과값 출력

	return 0;
}