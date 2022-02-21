#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>


using namespace std;

bool visited[50001];

int solution(vector<int> people, int limit) {
    int answer = 0; //구명보트개수
    int idx = 0;
    int len = people.size()-1;
  
    sort(people.begin(), people.end()); //오름차순정렬

    while (1)   //idx와 len을 사용하여 가장가벼운사람과 가장무거운사람의 합부터 비교
    {   
        if (idx >= len) //탐색이 끝난경우
        {
            for (int i = 0; i < people.size(); i++) //방문여부확인
            {
                if (visited[i])
                    continue;
                else
                    answer++;   //방문표시가 안된 인덱스 = 보트에 못탄사람 -> 보트개수증가
            }
            break;
        }

        if (people[idx] + people[len] <= limit) //두명의 몸무게가 무게제한보다 적거나 같은경우
        {   
            answer++;
            visited[idx] = true;    //방문표시
            visited[len] = true;
            idx++;
            len--;
        }
        else if (people[idx] + people[len] > limit)    //두명의몸무게가 무게제한보다 큰경우
        {
            answer++;
            visited[len] = true;
            len--;  
        }
    }

    return answer;
}


int main()
{   
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
   
	return 0;
}