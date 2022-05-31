#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

struct cmp
{
	bool operator()(int a, int b)
	{	
		if (abs(a) == abs(b))	//절대값이 같은경우 더 작은 값을 후순위로 저장
			return a > b;
		else
			return abs(a) > abs(b);	//절대값이 더작은 값 후순위로 저장
		
	}
};

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	priority_queue<int,vector<int>,cmp>pq;
	int temp;
	vector<int>v;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;

		if (temp != 0)
		{
			pq.push(temp);	//0이아니면 pq에 저장
		}
		else
		{
			if (pq.empty())
				v.push_back(0);	//우선순위큐가 비어있는 경우 vector에 0저장
			else
			{
				v.push_back(pq.top());	//vector에 가장 작은 값 저장
				pq.pop();
			}
		}

	}


	for (int i = 0; i < v.size(); i++)	//모든 결과 출력
		cout << v[i] << '\n';
	

	return 0;
}