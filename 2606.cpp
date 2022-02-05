#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int n, s;
int cnt = 0;
int map[101][101];
bool visited[101];
int num1, num2;

void dfs(int a)	//dfs, 재귀
{
	visited[a] = true;	//매개변수로 받은 a를 방문표시
	cnt++;	//컴퓨터수 증가
		
	for (int i = 1; i <= n; i++)	//컴퓨터의 총 개수 만큼 반복
	{
		if (map[a][i] == 1 && visited[i] == false)	//1이 저장되어있으며, 방문하지않은경우
		{
			dfs(i);	//재귀함수를 호출하여 반복
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> s;	//컴퓨터의수 n, 연결되어있는 쌍의 수 s

	for (int i = 0; i < s; i++)	//s만큼 반복
	{
		cin >> num1 >> num2;
		map[num1][num2] = 1;	//연결된 컴퓨터의 위치에 1을 저장
		map[num2][num1] = 1;
	}
	
	dfs(1);

	cout << cnt-1;	//결과값 출력, 1번 컴퓨터를 통해 바이러스에 걸린 컴퓨터의 수이기때문에 -1

	return 0;
}