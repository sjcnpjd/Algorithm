#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

#define INF 1000000

int v, e;   //정점, 간선
int start;  //시작정점
int t1, t2, t3;
int result[20001];  //최단경로값 저장할 배열
vector<pair<int, int>>map[300001];

void func(int s)
{
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>>q;   //우선순위큐, 내림차순으로 선언, 가중치가 작은 순으로 정렬
    q.push({ 0,s });
    result[s] = 0;  //시작점은 0

    while (!q.empty())
    {
        int num = q.top().second;   // 1 2 3 4 
        int len = q.top().first;    //0 2 3 7
        q.pop();

        if (result[num] < len)continue; //현재 저장된 경로값보다 크다면 continue

        for (int i = 0; i < map[num].size(); i++)
        {
            int des = map[num][i].second;   //num과 연결된 정점
            int dis = map[num][i].first + len;  //현재까지경로값 + 연결된 정점의 가중치

            if (dis < result[des])  //기존 경로값보다 작은 경우
            {
                result[des] = dis;  //경로값 갱신
                q.push({ dis,des });    //연결된 정점 및 가중치를 push
            }
        }

    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> v >> e;
    cin >> start;

    for (int i = 0; i < e; i++)
    {
        cin >> t1 >> t2 >> t3;
        map[t1].push_back({ t3,t2 });
    }

    for (int i = 1; i <= v; i++)
        result[i] = INF;

    func(start);

    for (int i = 1; i <= v; i++)
    {
        if (result[i] == INF)
            cout << "INF" << '\n';
        else
            cout << result[i] << '\n';
    }

    return 0;
}