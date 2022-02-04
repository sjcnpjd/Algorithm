#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<int>v;
	int temp;
	cin >> n;	//n을 입력
	
	for (int i = 1; i <= n; i++)	//vector에 1부터 n까지 저장
	{
		temp = i;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());	//오름차순정렬

	do {
		for (auto it = v.begin(); it != v.end(); it++)	//순열을 출력하는 반복문
		{
			cout << *it << " ";
		}
		cout << '\n';
	} while (next_permutation(v.begin(), v.end()));	//next_permutation함수는 순열을 구할때 사용되는 함수

	return 0;
}