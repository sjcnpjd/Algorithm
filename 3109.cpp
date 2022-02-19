#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>


using namespace std;

int r, c;
char map[10001][501];
bool visited[10001][501];
int cnt = 0;
int xarr[3] = { 1,0,-1 };   //오른쪽, 오른쪽위대각선, 오른쪽아래대각선
int yarr[3] = { 1,1,1 };

void dfs(int x, int y)
{
    stack<pair<int, int>>s;
    s.push({ x,y });
    visited[x][y] = true;

    while (!s.empty())
    {
        int a = s.top().first;
        int b = s.top().second;

        s.pop();

        if (b == c - 1 && !visited[a][b])   //마지막열도착 및 방문하지 않은 위치일경우
        {
            visited[a][b] = true;   //방문표시
            cnt++;  //파이프개수 증가
            return;
        }

        visited[a][b] = true;

        for (int i = 0; i < 3; i++) //3방향을 탐색
        {
            int ax = a + xarr[i];
            int yx = b + yarr[i];

            if (ax < 0 || yx < 0 || ax>=r || yx >=c)continue; //맵을 벗어난경우
            if (visited[ax][yx])continue;   //방문한경우
            if (map[ax][yx] == 'x')continue;    //건물이 있는경우

            /*if (map[ax][yx] != '.')continue;*/    //빈칸이 아닌경우

            s.push({ ax,yx });
        }
    }
    
    return;

}


int main()
{   
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < r; i++) //첫번째열만 시작으로 탐색
        dfs(i, 0);

    cout << cnt;

	return 0;
}