#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <deque>
#include <map>

using namespace std;

int n, temp;
int arr[1001][3];
int dp[1001][3];

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];	//1,0 - 1,1 - 1,2
		}

		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}

	int answer = min(min(dp[n][0], dp[n][1]), dp[n][2]);

	cout << answer;

	return 0;
}