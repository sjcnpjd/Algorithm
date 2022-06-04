#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;	//회의의 수
int t1, t2;
int result = 1;	//회의의최대개수 첫번째경우
int result2 = 1;	//회의의최대개수 두번째경우
vector<pair<int, int>>v;	//회의시작 종료시간 저장할 vector

bool cmp(pair<int, int> p1, pair<int, int>p2)	//비교함수, 회의의 시작시간을 기준으로 오름차순정렬, 같은 경우 종료시간 비교
{
	if (p1.first == p2.second)
		return p1.second < p2.second;
	else
		return p1.first < p2.first;
}

bool cmp2(pair<int, int> p1, pair<int, int>p2)	//회의의 종료시간 기준으로 오름차순 정렬
{	
	if (p1.second == p2.second)
		return p1.first < p2.first;
	else
		return p1.second < p2.second;
}


int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> t1 >> t2;
		v.push_back({ t1,t2 });
	}

	sort(v.begin(), v.end(), cmp);	//정렬

	int start = v[0].first;
	int end = v[0].second;

	for (int i = 1; i < v.size(); i++)	
	{	
		if (end <= v[i].first)	//회의의 시작시간이 현재회의의 종료시간보다 같거나 큰경우
		{
			result++;	//개수증가
			start = v[i].first;	//회의 시간 저장
			end = v[i].second;
		}
	}

	sort(v.begin(), v.end(), cmp2);

	start = v[0].first;
	end = v[0].second;

	for (int i = 1; i < v.size(); i++)
	{
		if (end <= v[i].first)
		{	
			result2++;
			start = v[i].first;
			end = v[i].second;
		}
	}

	if (result < result2)
		result = result2;

	cout << result;

	return 0;
}