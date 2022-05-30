#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

int n, k;
vector<int>v;
vector<int>result;
int temp;
int answer = 0;

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	
	result.resize(n-1);

	for (int i = 0; i < n-1; i++)
	{
		result[i] = v[i + 1] - v[i];
	}

	sort(result.begin(), result.end());

	for (int i = 0; i < n - k; i++)
	{
		answer += result[i];
	}

	cout << answer;
	return 0;
}