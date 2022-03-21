#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct
{
    int x;  //x좌표
    int y;  //y좌표
    int cnt;    //이동거리 저장
}node;

int map[6][6];  //대기실 저장 배열
bool visited[6][6]; //방문여부 저장배열
int dx[4] = { 1,-1,0,0 };   //상,하,좌,우 탐색
int dy[4] = { 0,0,1,-1 };


bool bfs(int bx, int by)
{
    queue<node>q;
    q.push({ bx,by,0 });
    visited[bx][by] = true;

    while (!q.empty())
    {
        int qx = q.front().x;
        int qy = q.front().y;
        int qcnt = q.front().cnt;
        q.pop();

        if (qx != bx || qy != by)   //현재 좌표가 시작 좌표랑 다른경우
            if (map[qx][qy] == 1 && qcnt < 3)   //다른 응시자가 앉아있는자리로 이동가능하며, 이동거리가 3보다 작은경우
                return 0;   //거리두기가 안지켜짐
        

        for (int i = 0; i < 4; i++)
        {
            int qqx = qx + dx[i];
            int qqy = qy + dy[i];

            if (visited[qqx][qqy])continue; //방문한 경우
            if (qqx < 0 || qqx>5 || qqy < 0 || qqy >5)continue; //대기실 벗어난 경우
            if (map[qqx][qqy] == -1)continue;   //파티션인 경우

            q.push({ qqx,qqy,qcnt + 1 });
            visited[qqx][qqy] = true;
        }
    }

    return 1;
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;


    for (int i = 0; i < places.size(); i++)
    {
        for (int j = 0; j < places[i].size(); j++)
        {
            string temp = places[i][j]; //입력으로 주어지는 각 string을 저장

            for (int k = 0; k < temp.size(); k++)
            {
                if (temp[k] == 'P')
                    map[j][k] = 1;    //P == 사람이 앉아있는 위치
                else if (temp[k] == 'O')
                    map[j][k] = 0;    //O == 빈테이블
                else if (temp[k] == 'X')
                    map[j][k] = -1;   //X == 파티션
            }
        }

        bool nch;   //bfs탐색결과를 저장할 변수
        bool ou = false;    //반복문을 종료할때 사용할 변수

        int np = 0; //응시자 수
        for (int a = 0; a < 5; a++) //대기실에 응시자가 없거나, 한명만있을 경우를 확인할 반복문
        {
            for (int b = 0; b < 5; b++)
            {
                if (map[a][b] == 1)
                    np++;
            }
        }

        if (np < 2)
        {
            answer.push_back(1);    //응시자없거나 한명만있다면 continue
            continue;
        }

        for (int a = 0; a < 5; a++)
        {
            for (int b = 0; b < 5; b++)
            {
                if (map[a][b] == 1) //응시자가 앉은 자리라면
                {
                    fill(&visited[0][0], &visited[5][6], false);    //visited배열 초기화 후 
                    nch = bfs(a, b);    //bfs탐색
                   
                    if (!nch)   //거리두기가 지켜지지 않았다면 반복문 종료
                    {
                        ou = true;
                        break;
                    }
                    else
                        continue;   //지켜진다면 continue
                }
            }
            if (ou)
                break;
        }
        if (nch && !ou)
            answer.push_back(1);    //거리두기가 지켜진 경우
        else if (!nch && ou)
            answer.push_back(0);    //거리두기가 지켜지지 않은경우
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    vector<vector<string>>v;    //테스트케이스 vector
    vector<string>v1,v2,v3,v4,v5;

    v1.push_back("POOOP");
    v1.push_back("OXXOX");
    v1.push_back("OPXPX");
    v1.push_back("OOXOX");
    v1.push_back("POXXP");

    v2.push_back("POOPX");
    v2.push_back("OXPXP");
    v2.push_back("PXXXO");
    v2.push_back("OXXXO");
    v2.push_back("OOOPP");

    v3.push_back("PXOPX");
    v3.push_back("OXOXP");
    v3.push_back("OXPOX");
    v3.push_back("OXXOP");
    v3.push_back("PXPOX");

    v4.push_back("OOOXX");
    v4.push_back("XOOOX");
    v4.push_back("OOOXX");
    v4.push_back("OXOOX");
    v4.push_back("OOOOO");

    v5.push_back("PXPXP");
    v5.push_back("XPXPX");
    v5.push_back("PXPXP");
    v5.push_back("XPXPX");
    v5.push_back("PXPXP");

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);


    vector<int>res = solution(v);

    for (int i = 0; i < res.size(); i++)
        cout << res[i];

    return 0;
}