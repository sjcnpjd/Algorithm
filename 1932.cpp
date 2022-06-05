#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int n;	//삼각형크기
int arr[501][501];	//처음 삼각형 값 저장
int dp[501][501];	//삼각형의 층을 내려가며 값을 더해나갈 배열
int answer = 0;	//최대값

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;


	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			cin >> arr[i][j];	//  0,0 부터 1,0 - 1,1 -> 2,0 - 2,1 -2,2 ~...



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)	//1,0 - 1,1 에 더할 수 있는 숫자는 0,0 
		{
			if (i == 0 && j == 0)	//삼각형 맨위의 숫자
			{
				dp[i][j] = arr[i][j];
			}
			else if(i>0 && j>0)
			{
				dp[i][j] = max(dp[i - 1][j - 1] + arr[i][j] , dp[i-1][j] + arr[i][j]);	//그외의 경우에는 자신의 층위에 2개의 숫자중 큰 값 저장
			}
			else
			{
				dp[i][j] = dp[i - 1][j] + arr[i][j];	//삼각형 각층의 첫번째 자리 숫자
			}
		}
		
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{	
			if (answer < dp[i][j])
				answer = dp[i][j];

			//cout << dp[i][j] << " ";
		}
		//cout << '\n';
	}

	//cout << '\n';

	cout << answer;

	return 0;
}