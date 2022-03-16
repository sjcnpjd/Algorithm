#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <string>


using namespace std;

int n;
pair<int, int>target;
vector<int>rel[1001];
bool visited[1001][1001];
int m;
int t1, t2;

int bfs(int start)
{
    queue<pair<int,int>>q;
    q.push({start,0});  //start는 탐색을 시작할 위치이며, 0은 탐색이 진행될때마다 증가되는 촌수이다.
    
    while (!q.empty())
    {
        int qx = q.front().first;   //현재위치
        int qcnt = q.front().second;    //촌수
        q.pop();

        if (qx == target.second)    //촌수를 계산해야하는사람에 도달한 경우
            return qcnt;    //촌수 반환
        
        for (int i = 0; i < rel[qx].size(); i++)
        {   

            if (visited[qx][rel[qx][i]])continue;   //방문한경우 continue

            q.push({ rel[qx][i],qcnt + 1 });    //queue에 push할때마다 촌수1씩 증가
            visited[qx][rel[qx][i]] = true; //방문표시
        }
    }

    return -1;  //연결되지 않은경우 -1반환
}


int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n;   //전체사람의 수
    cin >> target.first >> target.second;   //촌수를 계산해야할 사람
    cin >> m;   //관계의 개수

    for (int i = 0; i < m; i++) //관계를 입력
    {
        cin >> t1 >> t2;
        rel[t1].push_back(t2);  //양방향으로 저장
        rel[t2].push_back(t1);
    }

    int result = bfs(target.first); //target의 first에 저장된 값을 시작으로 bfs 탐색

    cout << result; //결과출력

    return 0;
}