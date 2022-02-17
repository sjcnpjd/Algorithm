#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n;


void bfs(int x)
{
	queue<pair<int, int>>q;
	q.push({x,0});

	while (!q.empty())
	{
		int a = q.front().first;	//현재값 저장
		int c = q.front().second;	//연산회수를 저장
		q.pop();


		if (a == 1)	//1이되면 결과출력 및 종료
		{
			cout << c;
			return;
		}

		if (a < 0 || a>1000000)continue;	//범위를 벗어나면 continue
		
		if (a % 3 == 0)	//3으로 나누는 경우
			q.push({ a/3,c + 1 });
		
		if (a % 2 == 0)	//2로 나누는 경우
			q.push({ a / 2,c + 1 });
		
		if (a > 1)	//-1을 하는 경우
			q.push({ a - 1,c + 1 });

	}

}

int main()
{
	cin >> n;
	bfs(n);
	return 0;
}