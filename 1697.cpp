#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100001

int n, k;
int map[MAX];	
bool visited[MAX];


void bfs(int a)
{
	queue<pair<int,int>>q;	//queue선언
	q.push(make_pair(a, 0));	//매개변수 및 시간을 push
	visited[a] = true;	//방문표시

	while (!q.empty())
	{
		int x = q.front().first;	//queue의 front 값 저장
		int cnt = q.front().second;

		q.pop();	//삭제

		visited[x] = true;	//방문표시

		if (map[x] == 1)	//map의 해당 인덱스의 값이 1이라면 시간출력후 종료
		{
			cout << cnt;
			break;
		}

		if (x + 1 >= 0 && x + 1 < MAX && !visited[x + 1])	//x+1이 범위를 벗어나지 않고 방문하지 않은 경우
			q.push(make_pair(x + 1, cnt + 1));	//x+1과 시간 증가후 push

		if (x - 1 >= 0 && x - 1 < MAX && !visited[x - 1])
			q.push(make_pair(x - 1, cnt + 1));
		
		if (x * 2 >= 0 && x * 2 < MAX && !visited[x * 2])
			q.push(make_pair(x * 2, cnt + 1));

	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;	//n, k 입력
	map[k] = 1;	//map배열의 k인덱스에 1 저장
	bfs(n);	//함수호출

	return 0;
}