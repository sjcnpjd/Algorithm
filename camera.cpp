#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>


using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    int len = routes.size();
    
    sort(routes.begin(), routes.end()); //vector안에 vector<int>를 오름차순 정렬


    for (int i = 0; i < routes.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << routes[i][j] << " ";
        }
        cout << '\n';
    }

    int temp = routes[0][1];    //카메라 위치
    int idx = 1;

    while (1)
    {   
        if (idx >= len)break;   //모든 차량 다 확인하면 종료

        if (temp >= routes[idx][1]) //현재 카메라 위치가 차량이 나간지점보다 클 경우
                temp = routes[idx][1];  //카메라 위치갱신

        if(temp < routes[idx][0])   //현재 카메라위치가 차량의 진입지점보다 작은경우
        {
            answer++;   //카메라개수 증가
            temp = routes[idx][1];  //카메라 위치 저장
        }

        idx++;  //인덱스증가
    }
    
    return answer;
}       

int main()
{   
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
   
    vector<vector<int>>a;
    vector<int>b;
    vector<int>c;
    vector<int>d;
    vector<int>e;

    b.push_back(-20);
    b.push_back(-15);

    c.push_back(-14);
    c.push_back(-5);

    d.push_back(-18);
    d.push_back(-13);

    e.push_back(-5);
    e.push_back(-3);


    a.push_back(b);
    a.push_back(c);
    a.push_back(d);
    a.push_back(e);

    int temp = solution(a);
    cout << temp;

    
   
	return 0;
}