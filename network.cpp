#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

bool visited[201];  //방문여부 확인하는 배열

int solution(int n, vector<vector<int>> computers) {
    int answer = 0; //네트워크 개수

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])    //방문하지 않은 컴퓨터일 경우 bfs탐색
        {
            queue<int>q;
            q.push(i);
            visited[i] = true;

            while (!q.empty())
            {
                int a = q.front();
                q.pop();

                for (int j = 0; j < computers[a].size(); j++)
                {
                    if (a == j)continue;    //computers[i][i]는 항상 1이기에 continue
                    if (visited[j])continue;    //이미방문한경우 continue

                    if (computers[a][j] == 1)   //j가 연결된 컴퓨터인 경우
                    {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }

            answer++;   //네트워크 증가
        }
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    vector<vector<int>>v;
    vector<int>a;
    vector<int>b;
    vector<int>c;


    a.push_back(1);
    a.push_back(1);
    a.push_back(0);

    b.push_back(1);
    b.push_back(1);
    b.push_back(0);

    c.push_back(0);
    c.push_back(0);
    c.push_back(1);

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    int temp = solution(3, v);

    cout << temp;

    return 0;
}