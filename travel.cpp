#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int visited[10001];

void func(string str, vector<string>& temp_tic, vector<vector<string>>& tic, int cnt, vector<string>& result)
{
    temp_tic.push_back(str);    //임시 vector에 ICN을 시작으로 이후 목적지 저장

    if (cnt == tic.size() && result.size() == 0)   //cnt의 값이 총 티켓의 수와 같으며, result의 크기가 0인 경우
    {
        result = temp_tic;  //result에 저장 후 종료
        return;
    }

    for (int i = 0; i < tic.size(); i++)
    {
        if (tic[i][0] == str && visited[i] != true)    //방문하지 않았으며, 출발지가 현재 str과 같은 경우
        {
            visited[i] = true;
            func(tic[i][1], temp_tic, tic, cnt + 1, result);  //목적지를 str로 전달하고 cnt 증가

            visited[i] = false;  //경로가 없는 경우
            temp_tic.pop_back();
        }
    }

}


vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<string> temp;
    int num = 0;

    sort(tickets.begin(), tickets.end());    //정렬

    func("ICN", temp, tickets, num, answer);    //ICN 부터 시작

    return answer;
}