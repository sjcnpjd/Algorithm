#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int map[4][3];  //키패드 배열
bool visited[4][3]; //방문확인 배열
int ax[4] = { 1,-1,0,0 };   //상하좌우
int ay[4] = { 0,0,1,-1 };

typedef struct
{
    int x;
    int y;
    int cnt;
}node;

int bfs(int start, int target)  //start는 현재 왼손 또는 오른손 엄지의 위치, target은 눌러야할 키패드
{
    queue<node>q;
    int a, b;

    for (int i = 0; i < 4; i++) //현재 키패드의 좌표구하는 반복문
    {
        for (int j = 0; j < 3; j++)
        {
            if (map[i][j] == start)
            {
                a = i;
                b = j;
            }
        }
    }

    q.push({ a,b,0 });
    visited[a][b] = true;

    while (!q.empty())
    {
        int qx = q.front().x;
        int qy = q.front().y;
        int qcnt = q.front().cnt;
        q.pop();

        if (map[qx][qy] == target)  //현재위치가 target이면 이동한 거리를 return
            return qcnt;


        for (int i = 0; i < 4; i++)
        {
            int xx = qx + ax[i];
            int yy = qy + ay[i];

            if (visited[xx][yy])continue;   //방문한경우
            if (xx < 0 || xx>4 || yy < 0 || yy>3)continue;  //배열을 벗어난 경우
            if (map[xx][yy] > 9)continue;   //키패드의 숫자보다 큰 경우

            q.push({ xx,yy,qcnt + 1 });
            visited[xx][yy] = true;
        }

    }

}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int num = 1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            map[i][j] = num;
            num++;
        }
    }

    map[3][0] = 10; //왼손시작위치, 키패드 * = 10
    map[3][1] = 0;
    map[3][2] = 11; //오른손시작위치, 키패드 # = 11


    int lh = 10;
    int rh = 11;

    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)  //왼쪽열인 경우
        {
            lh = numbers[i];
            answer += "L";
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) //오른쪽열인 경우
        {
            rh = numbers[i];
            answer += "R";
        }
        else
        {
            fill(&visited[0][0], &visited[3][3], false);    //visited 배열 초기화후, 각 엄지손가락위치에서 탐색시작
            int lcnt = bfs(lh, numbers[i]);
            fill(&visited[0][0], &visited[3][3], false);
            int rcnt = bfs(rh, numbers[i]);

            if (lcnt > rcnt)    //오른손이 더 가까운 경우
            {
                rh = numbers[i];
                answer += "R";
            }
            else if (lcnt < rcnt)   //왼손이 더 가까운 경우
            {
                lh = numbers[i];
                answer += "L";
            }
            else if (lcnt == rcnt)  //같은경우
            {
                if (hand == "right")
                {
                    rh = numbers[i];
                    answer += "R";
                }
                else
                {
                    lh = numbers[i];
                    answer += "L";
                }
            }

        }
    }


    return answer;
}