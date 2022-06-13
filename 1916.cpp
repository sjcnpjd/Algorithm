#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>


using namespace std;

//백준 1916 - 다익스트라

int n, m;	//도시의개수, 버스의개수
int map[1001][1001];	//이동 비용 저장
vector<vector<int>>v(1001);
int start, des;	//출발도시, 도착도시
int t1, t2, t3;
int answer = 987654321;	//결과
bool visited[1001][1001];	//방문확인할 배열


typedef struct
{
	int x;	//현재도시위치
	int num;	//비용
}node;

struct cmp
{
	bool operator()(node n1, node n2)
	{
		return n1.num > n2.num;	//작은값이 top을 유지
	}
};

void func()
{
	priority_queue<node,vector<node>,cmp>s;	//우선순위큐 선언, 작은값 top
	s.push({start,0});	//시작위치 및 시작비용은 0
	visited[start][0] = true;

	while (!s.empty())
	{
		int qx = s.top().x;
		int qnum = s.top().num;
		s.pop();

		if (qx == des && qnum < answer)	//목적지에 도달하였으며, answer 값보다 현재 비용이적은 경우 비용저장
			answer = qnum;
		
		for (int i = 0; i<v[qx].size(); i++)	//현재위치에서 연결된 경로 탐색
		{
			int qqx = v[qx][i];

			if (visited[qx][qqx])continue;	//방문여부확인

			s.push({ qqx, qnum + map[qx][qqx] });	//현재 비용(qnum)에서 이동하며 추가되는 비용(map[qx][qqx])추가
			visited[qx][qqx] = true;
		}
	}

}


int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;	//도시
	cin >> m;	//버스

	fill(&map[0][0],&map[1000][1001],100000000);	//큰값으로 초기화
	
	for (int i = 0; i < m; i++)
	{
		cin >> t1 >> t2 >> t3;
		v[t1].push_back(t2);	//버스 경로 저장

		if (t3 < map[t1][t2])	
		{
			map[t1][t2] = t3;	//비용 저장
		}
	}

	cin >> start >> des;

	func();	//탐색

	cout << answer;	//결과출력

	
	return 0;
}