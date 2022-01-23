#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

void bfs(vector<int> gp[], bool vt[], int start)	//bfs 함수
{	
	queue<int>q;	//queue 선언

	q.push(start);	//q에 시작 정점을 push 한다

	while (!q.empty())	//q가 empty가 아니면 반복
	{	
		int temp = q.front();	//현재 q의 front를 temp에 저장
		q.pop();	//q의 front를 삭제

		if (vt[temp])	//visited 배열인덱스에 temp를 넣어서 방문한 값인지 확인, 방문했으면 밑에 코드 건너뛰기
			continue;

		vt[temp] = true;	//방문한것이 아니면 true로 방문한것을 저장
		cout << temp << " ";	//지금 방문했음으로 출력

		for (int i = 0; i < gp[temp].size(); i++)	//그래프[temp]의 사이즈 만큼 반복 (연결된 개수 만큼 반복)
		{
			q.push(gp[temp][i]);	//그래프[temp]의 0번인덱스(오름차순으로 main에서 정렬했기에 작은수) 부터 q로 push한다.
		}

	}
}

void dfs(vector<int> gp[], bool vt[], int start)	//bfs 함수
{
	vt[start] = true;	//visited 배열 인덱스에 매개변수로 받은 인덱스를 넣고 true를 저장
	cout << start << " ";	//방문하였음으로 출력

	for (int i = 0; i < gp[start].size(); i++)	//그래프[start] 사이즈 만큼반복, (연결된 개수 만큼 반복)
	{
		int temp = gp[start][i];	//그래프[start]의 0번인덱스의 값부터 temp에 저장

		if (vt[temp] == false)	//방문한적이 없다면
			dfs(gp, vt, temp);	//재귀함수로 방문을 한다.
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, v;	//n은 정점의 개수, m은 간선의 개수, v는 시작정점의 번호
	int a, b;	//간선이 연결하는 두 정점
	cin >> n >> m >> v;	

	vector<int>* graph = new vector<int>[n + 1];	//n의개수+1 만큼 vector로 그래프 선언
	bool* visited = new bool[n + 1];	//방문을 확인할 visited 배열 선언
	
	fill(visited, visited + (n + 1), false);	//visited배열을 false로 초기화한다

	for (int i = 0; i < m; i++)	//간선의 연결을 입력받는 반복문
	{
		cin >> a >> b;
		graph[a].push_back(b);	
		graph[b].push_back(a);
	}

	for (int i = 0; i <= n; i++)	//그래프를 오름차순으로 정렬하는 반복문 
		sort(graph[i].begin(), graph[i].end());	//정점번호가 작은것을 먼저 방문해야하기 때문에

	dfs(graph, visited, v);	//dfs 탐색

	cout << '\n';
	fill(visited, visited + (n + 1), false);	//visited 배열 초기화

	bfs(graph, visited, v);	//bfs 탐색

	delete[] graph;
	delete[] visited;

	return 0;
}
