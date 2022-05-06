#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

int n, m;
int map[51][51];
int len;
int result = 0;

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	len = min(n, m);	//정사각형을 찾아야함으로 n,m중에 작은값을 최대길이로 저장

	string str;
	for (int i = 0; i < n; i++)	//숫자들이 공백구분없이 입력됨으로 string 활용
	{	
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			map[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{	
			int idx = 0;
			for (int k = 0; k < len; k++)
			{
				if (j + k < m && i + k < n)	//범위를 벗어나지 않는경우
				{
					if (map[i][j] == map[i + k][j] && map[i][j] == map[i][j + k] && map[i][j] == map[i + k][j + k])	//각 꼭짓점의 값이 동일하다면
						idx = k;	//idx에 저장
				}
			}

			if (idx > result)	//최대값을 위해서 result에 저장
				result = idx;
		}
	}
	
	cout << (result+1) * (result+1);	//k가 0부터 시작함으로 1을 더해주고 정사각형의 크기임으로 result*result가 결과값



	return 0;
}