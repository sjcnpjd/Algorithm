#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int n;  //행, 열의 수 
int map[101][101];
int tempMap[101][101];
bool visited[101][101];

int xarr[4] = { 1,-1,0,0 }; //상하좌우탐색
int yarr[4] = { 0,0,1,-1 };

int mNum = 0;   //입력받은행열에서 가장 큰수 저장
int h = 0;  //높이
int idx = 0;
vector<int>v;   //각각의 비의양에 따라서 안전영역의 수 저장할 vector


void dfs(int a, int b)  //인접한 안전영역을 탐색하는 dfs
{
    stack<pair<int, int>>s;
    s.push({ a,b });
    visited[a][b] = true;

    while (!s.empty())
    {
        int x = s.top().first;
        int y = s.top().second;
        s.pop();

        for (int i = 0; i < 4; i++)
        {
            int sx = x + xarr[i];
            int sy = y + yarr[i];

            if (tempMap[sx][sy] == -1)continue; //안전영역이 아닌경우
            if (sx < 0 || sy < 0 || sx >= n || sy >= n)continue;    //map을 벗어난 경우
            if (visited[sx][sy]) continue;  //방문한경우

            s.push({ sx,sy });
            visited[sx][sy] = true;
        }
    }

}

                //비의양에 따라서 물에 잠기는 영역을 표시하는 bfs
void bfs(int a) //매개변수로 입력받은 비의양에 따라서 물에잠기는 영역을 tempMap에 -1로 저장
{
    copy(&map[0][0], &map[0][0] + 101 * 101, &tempMap[0][0]);   //초기화
    fill(&visited[0][0], &visited[n - 1][n], false);

    queue<pair<int, int>>q;
    q.push({ 0,0 });

    if (map[0][0] <= h)
        tempMap[0][0] = -1;

    visited[0][0] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (map[x][y] <= h) //비에잠기는 경우
        {
            tempMap[x][y] = -1;
            visited[x][y] = true;
        }

        for (int i = 0; i < 4; i++) //상하좌우 탐색
        {
            int ax = x + xarr[i];
            int yx = y + yarr[i];

            if (ax < 0 || yx < 0 || ax >= n || yx >= n)continue;    //맵을 벗어난경우
            if (visited[ax][yx])continue;   //이미 방문한 경우
            if (tempMap[ax][yx] == -1)continue; //이미 비에 잠긴 경우

            q.push({ ax,yx });
            visited[ax][yx] = true;
        }
    }

    //위의 while문이 종료되면 tempMap에서 비에 잠기는 부분은 모두 -1로 표시완료

    fill(&visited[0][0], &visited[n - 1][n], false);    //방문여부배열을 초기화

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tempMap[i][j] != -1 && !visited[i][j])  //tempMap에서 비에잠기지 않았으며, 방문하지않은 경우
            {
                dfs(i, j);  //dfs를 통해서 해당 안전영역에서 인접한 부분을 모두 방문
                v[idx]++;   //안전영역 개수 증가
            }
        }
    }
    //위의 반복문이 끝나면 해당 영역의 안전영역 탐색이 끝났음으로 인덱스 증가
    idx++;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n;   

    for (int i = 0; i < n; i++) //n크기에 행열을 입력
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];   

            if (mNum < map[i][j])   //입력받은 값 중에 가장 큰수 mNum에 저장
                mNum = map[i][j];
        }
    }

    v.resize(mNum+1);

    //비의양 0부터 mNum-1 까지를 모두 탐색

    while (h < mNum)    //비의양이 mNum보다 작은경우까지 반복, mNum과 같거나 커지면 안전영역은 0
    {
        bfs(h); //bfs함수로 높이를 전달
        h++;    //비의양 증가
    }

    sort(v.begin(), v.end());   //오름차순정렬

    cout << v[idx]; //가장 큰 수 출력

    return 0;
}