#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	unordered_map<string, int>map;
	vector<string>answer;
	string temp;


	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		map.insert(make_pair(temp, 0));
	}

	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		if (map.find(temp) != map.end())
			answer.push_back(temp);
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';

	for (auto it = answer.begin(); it != answer.end(); it++)
		cout << *it << '\n';

	return 0;
}