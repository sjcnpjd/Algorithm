#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool compare(pair<int,string> a, pair<int, string> b)
{	
	return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, string>>v(n);	//vector 선언

	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;	//나이와 이름 입력

	stable_sort(v.begin(), v.end(),compare);	//stable_sort는 sort와는 다르게 값이 같은경우 원소의 순서대로 정렬한다.


	for (int i = 0; i < n; i++)	//결과출력
		cout<< v[i].first <<" "<< v[i].second<<'\n';

	return 0;
}
