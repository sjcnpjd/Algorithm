#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int s;
bool visited[1001][1001];	//방문을표시할 배열

typedef struct
{
	int n;	//화면에 존재하는 이모티콘 수
	int c;	//클립보드의 이모티콘 수
	int t;	//연산시간
}emt;	//queue에 사용될 구조체

void bfs()	//bfs함수
{
	queue<emt>q;	//queue 선언
	q.push({ 1,0,0 });	//이미화면에 1이 입력되어있기에 1,0,0을 push
	visited[1][0] = true;	//방문표시

	while (!q.empty())
	{
		int x = q.front().n;	//queue의 front 값 저장
		int y = q.front().c;
		int z = q.front().t;
		q.pop();	//저장한 값 queue에서 삭제


		if (x == s)	//x==s 일 경우
		{
			cout << z;	//출력후 종료
			return;
		}

		visited[x][y] = true;	//방문표시
		
		if (x < 1001 && x>0 )	//x가 0보다 크고 최대값 보다 작은경우
		{	
			if (visited[x][x] != true)	//방문여부 확인
			{
				q.push({ x,x,z + 1 });	//화면에 있는 이모티콘을 클립보드에 복사
				visited[x][x] = true;	//방문표시
			}
		}
		
		if (x < 1001 && x>0 && x + y < 1001)	//x가 0보다 크고 최대값 보다 작으며, x+y가 최대값보다 작은경우
		{
			if (visited[x + y][y] != true)	//방문여부 확인
			{
				q.push({ x + y,y,z + 1 });	//클립보드에 있는 이모티콘을 화면에 붙여넣기
				visited[x+y][x] = true;	//방문표시

			}
		}
		
		if (x - 1 > 0 || x > s)	//x에서 1을 뺀 값이 0보다 크거나 x가 0보다 큰경우
		{
			if (visited[x - 1][y] != true)	//방문확인
			{
				q.push({ x - 1,y,z + 1 });	//화면에 있는 이모티콘 하나 삭제
				visited[x -1][y] = true;	//방문표시
			}
		}
		
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;	//s입력
	bfs();	//bfs

	return 0;
}