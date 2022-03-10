#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int n, m;
int u, v;
vector<int>vec[500001];
bool visited[500001];
int answer = 0;

void dfs(int start)
{
    stack<int>s;
    s.push(start);
    visited[start] = true;

    while (!s.empty())
    {
        int x = s.top();
        s.pop();

        for (int i = 0; i < vec[x].size(); i++)
        {
            if (visited[vec[x][i]])continue;    //방문한 정점일경우 continue

            s.push(vec[x][i]);  //방문하지 않았다면 stack에 push 및 방문표시
            visited[vec[x][i]] = true;
        }

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        vec[u].push_back(v);    //방향없는 그래프이기에 양뱡향 연결
        vec[v].push_back(u);
    }

    for (int i = 1; i<= n; i++) //1부터 N까지 모든 정점 탐색
    {
        if (!visited[i])    //방문하지 않은 정점 탐색
        {
            answer++;   //연결요소 개수 증가
            dfs(i); //dfs탐색
        }
    }

    cout << answer;

    return 0;
}