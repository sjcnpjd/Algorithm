#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, k;
bool visited[100001];
int result=0;

void bfs()
{
	queue < pair<int, int>>q;
	q.push(make_pair(n, 0));
	visited[n] = true;

	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		visited[a] = true;

		if (a == k && result == 0)
		{
			result = b;
		}
		else if (a == k && result != 0)
			result = min(result, b);	//기존의 시간과 비교했을때 더 작은 값을 result에 저장

		if (a + 1 <= 100001 && visited[a + 1] != true)
			q.push(make_pair(a + 1, b + 1));
		if (a - 1 >= 0 && visited[a - 1] != true)
			q.push(make_pair(a - 1, b + 1));
		if (a * 2 <= 100001 && visited[a *2] != true)
			q.push(make_pair(a * 2, b));	//순간이동을 하는경우 0초 이기때문에 시간 증가 X
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	bfs();
	
	cout << result;
	
	return 0;
}