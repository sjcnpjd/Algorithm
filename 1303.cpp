#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

char map[101][101];	//전쟁터를 입력 받을 배열
bool visited[101][101] = {false,};	//방문을 확인할 배열
int n, m;	//가로,세로의 값을 입력받은 변수
int xarr[4] = { 1,0,-1,0 };	//위,오른쪽,아래,왼쪽을 확인할 배열
int yarr[4] = { 0,1,0,-1 };


int bfs(int x, int y)	//bfs 함수
{	
	int count = 1;	//매개변수 받은 위치는 W병사 또는 B 병사이기 때문에 count는 1로 초기화
	queue<pair<int, int>>q;	//queue를 선언

	q.push(make_pair(x, y));	//입력받은 위치를 q에 push

	char temp = map[x][y];	//temp에 해당위치에 병사값을 저장
	visited[x][y] = true;	//방문을 표시

	while (!q.empty())	//queue가 비어있지않다면 반복
	{
		int a = q.front().first;	//queue의 front에 저장된 값을 a,b에 저장
		int b = q.front().second;

		q.pop();	//a,b에 저장한 queue에 값을 삭제

		for (int i = 0; i < 4; i++)	//4가지방향을 탐색하기 때문에 4번 반복하는 반복문
		{
			int na = a + xarr[i];	//4가지 방향탐색을 위해서 xarr, yarr 배열의 값을 더한다
			int nb = b + yarr[i];

			if (0 <= na && na < m && 0 <= nb && nb < n)	//map을 벗어나지않는 경우
			{
				if (visited[na][nb] == false && map[na][nb] == temp)	//방문하지않은 위치면서 매개변수로 받은 병사값과 같을경우
				{
					visited[na][nb] = true;	//방문을 표시하고
					count++;	//count에 1을더한다
					q.push(make_pair(na, nb));	//queue에 push
				}
			}

		}
	}
	return count * count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int wresult = 0;	//w병사의 합을 저장할 변수 
	int bresult = 0;	//b병사의 합을 저장할 변수
	string str;
	
	cin >> n >> m;	//전쟁터의 가로, 세로 값 입력

	for (int i = 0; i < m; i++)	//map에 W병사와 B병사를 배열로 입력받는 반복문
	{
		cin >> str;
		for (int j = 0; j < n; j++)
			map[i][j] = str[j];
	}

	for (int i = 0; i < m; i++)	//0,0위치부터 병사의 합을 구하기 위한 반복문
	{
		for (int j = 0; j < n; j++)
		{	
			if (visited[i][j] == false)	//방문하지 않은 위치일 경우 
			{
				if (map[i][j] == 'W')	//해당위치의 값이 W라면
				{
					wresult += bfs(i, j);	//bfs함수로 탐색하고 반환값을 wresult에 더한다
				}
				else if (map[i][j] == 'B')	//해당위치의 값이 B라면
				{
					bresult += bfs(i, j);	//bfs함수로 탐색하고 반환값을 bresult에 더한다
				}
			}
		}
	}

	cout << wresult << " " << bresult;	//결과값출력

	return 0;
}