#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<pair<int,int>>v(9);

	for (int i = 0; i < 9; i++)
	{
		cin >> v[i].first;
		v[i].second = i+1;
	}


	sort(v.begin(), v.end());

	cout << v[8].first << '\n';
	cout << v[8].second << '\n';



	return 0;
}
