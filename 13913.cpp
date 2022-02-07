#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, k;	//수빈이위치 n, 동생의위치 k
bool visited[100001];	//방문표시를 위한 배열
int result=0;	//빠른시간을 저장할 변수
int arr[100001];	//이동한 순서를 저장하기 위한 배열
vector<int>v;	//이동순서 출력에 사용할 vector

void bfs()
{	
	
	queue < pair<int, int>>q;	//queue 선언
	q.push(make_pair(n, 0));	//n과 0을 push
	visited[n] = true;	//방문표시

	while (!q.empty())
	{
		int a = q.front().first;	//a에는 현재위치를 저장
		int b = q.front().second;	//b에는 걸린시간을 저장
		q.pop();	//저장한 값을 queue에서 삭제

		visited[a] = true;	//방문표시
		
		if (a == k)	//현재위치가 k와 같다면 동생의 위치를 찾은 것
		{	
			result = b;	//걸린시간을 result에 저장
			int temp = a;	//현재위치를 a에 저장

			while (temp != n)	//temp가 n일때 까지 반복
			{
				v.push_back(temp);	//temp값을 v에 push
				temp = arr[temp];	//arr[temp]를 temp에저장, 이를 통해서 이전에 값을 추적
			}
			v.push_back(n);	
			break;	//종료
		}

		if (a + 1 < 100001 && visited[a + 1] != true)	//현재위치에서 1을 더한값이 최대값보다 작으며, 방문하지 않은위치일 경우
		{
			q.push(make_pair(a + 1, b + 1));	//queue에 1을 더한위치 및 시간을 push
			arr[a + 1] = a;	//배열 인덱스 a+1의 값으로 현재위치인 a를 저장
			visited[a + 1] = true;	//방문표시
		}
		if (a - 1 >= 0 && visited[a - 1] != true )
		{
			q.push(make_pair(a - 1, b + 1));
			arr[a - 1] = a;
			visited[a - 1] = true;

		}
		if (a * 2 < 100001 && visited[a * 2] != true)
		{
			q.push(make_pair(a * 2, b + 1));
			arr[a * 2] = a;
			visited[a * 2] = true;
		}
	}
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;	//n, k 입력
	bfs();	//bfs 호출
	
	cout << result << '\n';	//걸리시간 출력
	
	for (int i = v.size()-1; i >=0; i--)	//이동과정 출력, 도착위치부터 역순으로 저장되었기에 반대로 출력
		cout << v[i] << " ";
	
	
	return 0;
}