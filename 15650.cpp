#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define MAX 9	

int n, m;
bool visited[MAX];	
vector<int>result;	

void dfs(int x, int c)
{
	if (c == m)	
	{
		for (int i = 0; i < m; i++)
		{
			cout << result[i]<< " ";
		}
		cout << '\n';
	}
	else
	{
		for (int i = x; i <= n; i++)	
		{
			if (visited[i])continue;	
			result.push_back(i);	
			visited[i] = true;	
			dfs(i + 1, c + 1);	
			visited[i] = false;
			result.pop_back();

			
		}

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;	

	dfs(1,0);

	return 0;
}