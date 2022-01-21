#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int temp=0;
	cin >> n;

	vector<int>v(n);	//vector 선언

	for (int i = 0; i < n; i++)	//n개의 정수입력을 하는 반복문
	{
		cin >> v[i];
	}
	
	sort(v.begin(), v.end());	//sort함수를 사용하여 오름차순 정렬

	for (int i = 0; i < n; i++)	//출력
	{
		if (temp == v[i])	//중복을 빼기 위한 조건문
			continue;
		cout << v[i] << " ";
		temp = v[i];
	}

	return 0;
}
