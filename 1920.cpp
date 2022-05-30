#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

int n,m;
vector<int>v;
int t1, t2;

bool func(int a)
{

	int low = 0;
	int high = v.size() - 1;

	while (low <= high)	//low가 high와 같거나 작은동안 반복
	{	
		int mid = (low + high) / 2;	//현재값
		
		if (v[mid] == a)	//a를 찾은경우 true return
			return true;

		if (v[mid] < a)	//a보다 현재값이 작은경우
			low = mid+1;	//현재값+1을 low에 저장
		else if (v[mid] > a)
			high = mid-1;

	}

	return false;
}


int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> t1;
		v.push_back(t1);	//vector에 저장
	}

	sort(v.begin(), v.end());	//오름차순 정렬


	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> t2;	//찾아야할숫자

		if (func(t2))
			cout << "1" << '\n';	//true
		else
			cout << "0" << '\n';	//false
		
	}

	return 0;
}