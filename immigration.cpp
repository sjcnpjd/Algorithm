#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());   //오름차순정렬
    
    long long start = 1;
    long long end = (long long)times[times.size() - 1] * (long long)n;  //60, 가장오래걸릴수 있는 시간
    long long mid = (start + end) / 2;    //30

    long long cnt = 0;

    while (start<=end)
    {   
        cnt = 0;
        mid = (start + end) / 2;

        for (int i = 0; i < times.size(); i++)  //7,10
            cnt += mid / times[i];  //cnt는 현재 시간에서 가능한 인원수
        
        if (cnt >= n)   //시간맞거나 여유있는 경우
        {   
            end = mid - 1;
            answer = mid;
        }
        else if (cnt < n)   //시간부족한 경우
        {
            start = mid + 1;
        }
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    vector<int>v;
    v.push_back(7);
    v.push_back(10);

    long long temp = solution(6, v);

    cout << temp;


    return 0;
}