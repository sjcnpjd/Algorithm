#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	
	cin >> n >> k;
	vector<int>v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());	//오름차순정렬

	cout << v[k - 1];	//해당인덱스의 값 출력
	

	return 0;
}
