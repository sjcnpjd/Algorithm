#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int map[26][26];
int mapTemp[26][26][4];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n;

typedef struct
{
    int x;
    int y;
    int money;
    int px;
}node;


int bfs(int start)
{
    queue<node>q;
    q.push({ start,start,0,-1 });
    vector<int>result;

    fill(&mapTemp[0][0][0], &mapTemp[n - 1][n][4], 0);    //배열0으로 초기화

    while (!q.empty())
    {
        int qx = q.front().x;   //x좌표
        int qy = q.front().y;   //y좌표
        int qm = q.front().money;   //현재 비용
        int qpx = q.front().px; //이전 방향
        q.pop();


        if (qx == n - 1 && qy == n - 1) //목적지 도착하면 현재 비용 저장
        {
            result.push_back(qm);
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int mx = qx + dx[i];
            int my = qy + dy[i];
            int temp = qm;

            if (mx<0 || mx>n - 1 || my<0 || my>n - 1)continue;       //map을 벗어난 경우
            if (map[mx][my] == 1)continue;  //벽인 경우


            if (qpx == -1 || qpx == i)  //-1이거나 qpx가 현재방향과 동일한 경우 직선도로
                temp += 100;
            else if (qpx != i || qpx != -1)    //그외의 경우 코너
                temp += 600;

            if (mapTemp[mx][my][i] >= temp || mapTemp[mx][my][i] == 0)   //현재 비용값이 mapTemp에 저장된 비용값보다 작거나 같은경우
            {
                mapTemp[mx][my][i] = temp;
                q.push({ mx,my,temp,i });
            }

        }

    }

    sort(result.begin(), result.end()); //오름차순 정렬

    return result[0];   //가장 작은 값 반환
}

int solution(vector<vector<int>> board) {
    int answer = 0;

    for (int i = 0; i < board.size(); i++)  //board를 map에 저장
        for (int j = 0; j < board[i].size(); j++)
            map[i][j] = board[i][j];

    n = board.size();

    int temp = bfs(0);  //0부터 bfs탐색
    answer = temp;  //결과 저장

    return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	return 0;
}