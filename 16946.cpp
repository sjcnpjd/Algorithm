#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <set>


using namespace std;

int n, m;   
int map[1001][1001];    //행렬을 입력받을 배열
int result[1001][1001]; //결과출력에 사용될 배열
int test[1001][1001];   //이동할수있는 곳을 영역별로 분리할때 사용될 배열
bool visited[1001][1001];   //방문여부 확인하는 배열

int xarr[4] = { 1,-1,0,0 }; //상,하,좌,우 확인
int yarr[4] = { 0, 0, 1, -1 };

string temp = "";
int idx = 1;
int cnt;

void dfs(int a, int b)  //이동할수 있는 구역 탐색 및 값 저장
{
    stack<pair<int, int>>s;
    vector<pair<int, int>>v;    //확인한 구역의 좌표값을 저장할 vector

    v.push_back({ a,b });
    s.push({ a,b });

    cnt = 1;
    visited[a][b] = true;

    while (!s.empty())
    {
        int x = s.top().first;
        int y = s.top().second;
        s.pop();

        for (int i = 0; i < 4; i++) //상하좌우 탐색
        {
            int x2 = x + xarr[i];
            int y2 = y + yarr[i];

            if (x2 < 0 || y2 < 0 || x2 >= n || y2 >= m)continue;    //맵을 벗어난경우
            if (visited[x2][y2])continue;   //이미 방문한 경우
            if (map[x2][y2] != 0)continue;  //이동할수 있는 위치가 아닌 경우

            cnt++;  //값 증가
            s.push({ x2,y2 });
            v.push_back({ x2,y2 });
            visited[x2][y2] = true; //방문표시
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        map[v[i].first][v[i].second] = cnt; //map에 이동가능한 영역의 합을 저장
        test[v[i].first][v[i].second] = idx;    //해당 구역에 idx 저장
    }
    idx++;
}


int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n >> m;  //n,m 입력

    for (int i = 0; i < n; i++) //행렬입력받는 반복문
    {   
        cin >> temp;
        for (int j = 0; j < m; j++) //숫자들이 붙어있는 형태로 입력받기때문에 string으로 입력받은 후 한자리씩저장
        {
            if (temp[j] - '0' == 1) //벽을 입력받으면 -1로 저장
                map[i][j] = -1;
            else
                map[i][j] = temp[j] - '0';  //나머지는 그대로 저장
        }
    }

    copy(&map[0][0], &map[0][0] + n * m, &result[0][0]);    //입력받은 행렬을 복사하여 result에 저장

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0 && !visited[i][j])   //map에서 이동할수 있는 곳이면서, 방문하지 않은 곳 dfs탐색
            {
                dfs(i, j);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == -1 && !visited[i][j])  //벽이면서, 방문하지 않은 경우
            {
                int sum = 1;
                vector<int>s;   //결과값 저장할 vector
                vector<int>temp;
                temp.push_back(0);
                
                for (int k = 0; k < 4; k++) //가로세로 탐색
                {
                    int xk = i + xarr[k];
                    int yk = j + yarr[k];

                    if (xk < 0 || yk < 0 || xk >= n || yk >= m)continue;    //맵을 벗어난경우
                    if (find(temp.begin(),temp.end(),test[xk][yk]) !=temp.end()) continue;  //이미결과값에 더해진 구역의 값인지 확인
                    if (map[xk][yk] == -1)continue; //벽을 만난경우

                    s.push_back(map[xk][yk]);   //값을 push
                    temp.push_back(test[xk][yk]);   //같은 구역의 값을 더하는것을 막기위해서 temp에 구역값 push
                }

                for (auto it = s.begin(); it != s.end(); it++)
                    sum += *it;

                result[i][j] = sum % 10;    //결과값을 10으로 나눈 나머지 값 저장
           }
        }
        
    }

    for (int i = 0; i < n; i++) //결과값을 저장한 배열 출력
    {
        for (int j = 0; j < m; j++)
        {
            cout << result[i][j];
        }
        cout << '\n';
    }

    return 0;
}