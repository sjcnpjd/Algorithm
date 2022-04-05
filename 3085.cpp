#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int n;	//보드의 크기
char map[51][51];	//보드로 사용될 배열
int result = 0;	//사탕의 최대 개수
int cnt = 1;	//사탕을 교환했을때의 개수를 저장할 변수


void hfunc(int a, int b)	//세로끼리 교환후 사탕 개수를 확인하는 배열
{
	swap(map[a][b], map[a + 1][b]);	//swap을 사용하여 값 교환, a <-> a+1

	for (int i = 0; i < n; i++)	//행의 최대사탕 개수를 확인하는 반복문
	{	
		cnt = 1;
		for (int j = 0; j < n; j++)
		{	
			if (j + 1 < n)
			{
				if (map[i][j] == map[i][j + 1])	// EX) 0,0 == 0,1 -> 0,1 == 0,2순서로 확인
				{
					cnt++;
					if (result < cnt)result = cnt;	//저장된 result값보다 현재값이 크다면 갱신
				}
				else
					cnt = 1;	//연속되지않은 경우 cnt 초기화
			}
		}
	}

	for (int i = 0; i < n; i++)	//열의 최대사탕 개수를 확인하는 반복문
	{
		cnt = 1;
		for (int j = 0; j < n; j++)
		{
			if (j + 1 < n)
			{
				if (map[j][i] == map[j+1][i])	// EX) 0,0 == 1,0 -> 1,0 == 2,0순서로 확인
				{
					cnt++;
					if (result < cnt)result = cnt;
				}
				else
					cnt = 1;
			}
		}
	}

	swap(map[a][b], map[a+1][b]);	//교환한 사탕 원상태로 복귀
}

void wfunc(int a, int b)	//가로끼리 교환후 사탕 개수를 확인하는 배열
{
	swap(map[a][b], map[a][b+1]);

	for (int i = 0; i < n; i++)
	{
		cnt = 1;
		for (int j = 0; j < n; j++)
		{
			if (j + 1 < n)
			{
				if (map[i][j] == map[i][j + 1])
				{
					cnt++;
					if (result < cnt)result = cnt;
				}
				else
					cnt = 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cnt = 1;
		for (int j = 0; j < n; j++)
		{
			if (j + 1 < n)
			{
				if (map[j][i] == map[j + 1][i])
				{
					cnt++;
					if (result < cnt)result = cnt;
				}
				else
					cnt = 1;
			}
		}
	}

	swap(map[a][b], map[a][b+1]);
}


int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;	//보드개수입력

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];	//보드입력


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)	
		{
			if (i + 1 < n)	//i+1이 n보다 작다면 세로자리 교환
				hfunc(i, j);
			if (j + 1 < n)	//j+1이 n보다 작다면 가로자리 교환
				wfunc(i, j);
		}
	}

	cout << result;	//결과 출력


	return 0;
}