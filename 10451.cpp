#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int t;
int n;
int temp;
vector<int>vec[1005];
vector<int>result;
bool visited[1005];
int sum = 0;

void dfs(int start) //dfs 탐색
{
    stack<int>s;
    s.push(start);
    visited[start] = true;

    while (!s.empty())
    {
        int x = s.top();
        s.pop();

        for (int i = 0; i < vec[x].size(); i++) //스택의 top 값인 x와 연결된 값들을 확인
        {   
            if (visited[vec[x][i]])continue;    //방문하지않았으면 스택의 push하여 같은 사이클로 생각

            s.push(vec[x][i]);
            visited[vec[x][i]] = true;
        }

    }

    sum += 1;   //사이클 개수 증가
}


int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    cin >> t;   //테스트케이스 개수 입력

    for (int i = 0; i < t; i++)
    {
        cin >> n;   //순열의 크기 입력

        for (int i = 1; i <= n; i++)    //순열을 저장하는 배열 초기화
            vec[i].clear();
        
        fill(visited, visited + 1001, false);   //방문을확인하는 배열 초기화
        
        for (int j = 1; j <= n; j++)
        {
            cin >> temp;    //순열 입력
            vec[j].push_back(temp);  //1 2 3 4 5 6 7 8 9 10 <- 저장되는 값 예제
            vec[temp].push_back(j);  //2 1 3 4 5 6 7 9 10 8

            if (temp == j)  //같은 숫자인 경우 사이클 개수 증가 및 방문표시
            {
                visited[temp] = true;
                sum++;
            }
        }

        for (int k = 1; k <= n; k++)
        {   
            if(!visited[k]) //방문하지 않은 값 방문
                dfs(k);
        }

        result.push_back(sum);  //결과값 result 벡터에 저장
        sum = 0;
        
    }

    for (int i = 0; i < result.size(); i++) //결과값 출력
        cout << result[i] << '\n';

    return 0;
}