#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>


using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    bool visited[31] = { false, };  
    int cnt = 0;    //여벌의 체육복으로 해결된 학생수
    int len = lost.size();  //도난당한학생수

    sort(lost.begin(), lost.end());     //오름차순으로 정렬, 정렬을해야 근처 번호를 우선적으로 확인가능
    sort(reserve.begin(), reserve.end());


    for (int i = 0; i < lost.size(); i++)   //여벌체육복을 가져왔지만 도난당한 경우 먼저 확인
    {   
        for (int j = 0; j < reserve.size(); j++)
        {
            if (lost[i] == reserve[j])
            {
                cnt++;  
                lost[i] = 0;    //0으로 초기화
                reserve[j] = 0;
                visited[j] = true;
            }
        }
        
    }


    for (int i = 0; i < lost.size(); i++)   //앞번호, 뒷번호학생에게 빌릴수 있는지 확인
    {
        for (int j = 0; j < reserve.size(); j++)
        {   
            if (lost[i] == 0 || reserve[j] == 0) continue;

            if (lost[i] + 1 == reserve[j])
            {
                if (visited[j])continue;
                visited[j] = true;  //빌려준학생을 visited 배열에 표시
                cnt++;
            }
            else if (lost[i] - 1 == reserve[j])
            {
                if (visited[j])continue;
                visited[j] = true;
                cnt++;
            }
            if (cnt >= len) //만약 도난당한 학생수보다 해결된학생이 커질경우
            {
                cnt = len;  //도난당한학생수로 초기화후 종료
                break;
            }
        }
    }

    answer = n - (len - cnt);   //전체학생수 - (도난당한학생수 - 해결된학생수)

    return answer;
}


int main()
{   
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
   
	return 0;
}