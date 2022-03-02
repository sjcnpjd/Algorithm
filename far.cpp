#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

typedef struct {    
    int num;    //현재위치
    int cnt;    //이동 횟수
}node;

bool visited[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int len = edge.size();
    vector<vector<int>>vec(len);    //양방향으로 저장할 vector
    vector<int>result(len); //이동횟수 저장할 vector
    

    for (int i = 0; i < edge.size(); i++)   //양방향으로 저장
    {   
        vec[edge[i][0]].push_back(edge[i][1]);
        vec[edge[i][1]].push_back(edge[i][0]);
    }

    queue<node>q;
    q.push({ 1,0 });    //1부터 탐색
    visited[1]= true;

    while (!q.empty())
    {
        int a = q.front().num;
        int b = q.front().cnt;
        q.pop();

        visited[a] = true;
       
        result.push_back(b);    //이동횟수 저장

        for (int i = 0; i < vec[a].size(); i++) //a와 연결된 노드를 탐색
        {
            int x = vec[a][i];

            if (visited[x])continue;    //방문한노드 생략

            q.push({ x,b + 1 });
            visited[x] = true;
           
        }
    }

    sort(result.begin(), result.end()); //오름차순정렬

    int num = result[result.size() - 1];    //가장큰수 저장

    for (int i = 0; i < result.size(); i++)
    {   
        if (result[i] == num)   //가장큰수와 같다면 answer 증가
            answer++;
    }

    return answer;
}


int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    vector<vector<int>> v;

    vector<int>a;
    vector<int>b;
    vector<int>c;
    vector<int>d;
    vector<int>e;
    vector<int>f;
    vector<int>g;

    a.push_back(3);
    a.push_back(6);

    b.push_back(4);
    b.push_back(3);

    c.push_back(3);
    c.push_back(2);
    
    d.push_back(1);
    d.push_back(3);

    e.push_back(1);
    e.push_back(2);

    f.push_back(2);
    f.push_back(4);
    
    g.push_back(5);
    g.push_back(2);
    
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    v.push_back(e);
    v.push_back(f);
    v.push_back(g);

    int temp = solution(6, v);

    cout << temp;

    return 0;
}