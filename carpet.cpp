#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

bool visited[2000001];

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;   //격자의 총 개수
    queue<int>q;
    int temp = (int)sqrt(sum);  //총 개수의 제곱근을 int로 저장
    int num;

    q.push(temp);   //제곱근을 시작으로 탐색시작

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        if (sum % x == 0)   //x로 나누어떨어질 경우
        {
            int y = sum / x;    //x * y = sum이 성립되기때문에 sum / x = y

            if (x < y)  //가로 길이는 세로길이와같거나 길어야 하기때문에 큰 값을 x로
            {
                num = y;
                y = x;
                x = num;
            }

            if (yellow % (x-2)==0)  //-2를 하는 이유는 한줄마다 존재하는 yellow의 최대개수는 x-2이기때문에, 
            {                       //여러줄 일 수 있기때문에 x-2를 나눈 나머지가 0인경우로 확인
                answer.push_back(x);
                answer.push_back(y);
                return answer;
            }

        }

        if (visited[x])continue;    //방문한 값은 continue

        q.push(x + 1);  // 값에서 +1, -1을 push하여 탐색

        if (x - 1 > 0)
            q.push(x - 1);

        visited[x] = true;  //방문표시
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    vector<int>c;
    c = solution(18, 6);

    for (auto it = c.begin(); it != c.end(); it++)
        cout << *it << " ";

    return 0;
}