#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <deque>
#include <queue>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	vector<string> v;

	cin >> str;	//문자열 입력

	for (int i = 0; i < str.length(); i++)
	{
		v.push_back(str.substr(i, str.length()));	//substr을 이용하여 문자열을 잘라서 vector에 저장
	}

	sort(v.begin(), v.end());	//오름차순 정렬

	for (int i = 0; i < v.size(); i++)	//결과출력
	{
		cout << v[i] << '\n';
	}

	return 0;
}