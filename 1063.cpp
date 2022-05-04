#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int map[8][8];	//체스판
string str, str2, od;	//킹의위치입력, 돌의위치입력, 움직이는정보
int n;	//움직이는횟수
vector<pair<int, int>>v(2);	//킹,돌의 좌표저장할 vector


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str >> str2 >> n;

	for (int i = 0; i < str.length(); i++)	//킹의위치 저장, 좌표상 0,0 은 체스판으로 8,a
	{
		if (i == 0)
		{	
			int idx = 0;
			for (char j = 'A'; j <= 'H'; j++)	//가로좌표값 , A B C -> 0 1 2 ...
			{
				if (str[i] == j)
					v[0].second = idx;
				
				idx++;
			}
		}
		else
		{	
			int temp = str[i] - '0';	//세로좌표값, 입력값이 1이면 -> 좌표상 7 
			v[0].first = 8 - temp;
		}
	}

	for (int i = 0; i < str2.length(); i++)	//돌의위치 저장
	{
		if (i == 0)
		{
			int idx = 0;
			for (char j = 'A'; j <= 'H'; j++)
			{
				if (str2[i] == j)
					v[1].second = idx;

				idx++;
			}
		}
		else
		{
			int temp = str2[i] - '0';
			v[1].first = 8 - temp;
		}
	}
	

	for (int i = 0; i < n; i++)	//움직이는정보에 따라 킹과 돌의 위치 이동
	{
		cin >> od;

		if (od == "R")	//오른쪽
		{	
			if (v[0].second + 1 < 8)	//킹이 이동했을때 범위를 벗어나지않는다면
			{
				v[0].second++;	//킹위치변경

				if (v[0].first == v[1].first && v[0].second == v[1].second)	//킹과 돌의 위치가 같아진다면
				{
					if (v[1].second + 1 < 8)	//돌의위치가 범위를 벗어나지않는다면 돌의 위치 변경
						v[1].second++;
					else
						v[0].second--;	//돌의위치가 범위를 벗어난다면 킹위치 원상복구
				}
			}
		}
		else if (od == "L")	//왼쪽
		{
			if (v[0].second - 1 >= 0)
			{
				v[0].second--;

				if (v[0].first == v[1].first && v[0].second == v[1].second)
				{
					if (v[1].second - 1 >= 0)
						v[1].second--;
					else
						v[0].second++;
				}
			}
		}
		else if (od == "B")	//아래
		{
			if(v[0].first + 1 < 8)
			{
				v[0].first++;

				if (v[0].first == v[1].first && v[0].second == v[1].second)
				{
					if (v[1].first + 1 < 8)
						v[1].first++;
					else
						v[0].first--;
				}
			}
		}
		else if (od == "T")	//위로
		{
			if (v[0].first -1 >= 0)
			{
				v[0].first--;

				if (v[0].first == v[1].first && v[0].second == v[1].second)
				{
					if (v[1].first -1  >= 0)
						v[1].first--;
					else
						v[0].first++;
				}
			}
		}
		else if (od == "RT")	//오른쪽위대각선
		{
			if (v[0].first - 1 >= 0 && v[0].second+1<8)
			{
				v[0].first--;
				v[0].second++;

				if (v[0].first == v[1].first && v[0].second == v[1].second)
				{
					if (v[1].first - 1 >= 0 && v[1].second + 1 < 8)
					{
						v[1].first--;
						v[1].second++;
					}
					else
					{
						v[0].first++;
						v[0].second--;
					}
				}
			}
		}

		else if (od == "LT")	//왼쪽위대각선
		{
			if (v[0].first - 1 >= 0 && v[0].second - 1 >= 0)
			{
				v[0].first--;
				v[0].second--;

				if (v[0].first == v[1].first && v[0].second == v[1].second)
				{
					if (v[1].first - 1 >= 0 && v[1].second - 1 >= 0)
					{
						v[1].first--;
						v[1].second--;
					}
					else
					{
						v[0].first++;
						v[0].second++;
					}
				}
			}
		}

		else if (od == "RB")	//오른쪽아래대각선
		{
			if (v[0].first + 1 < 8 && v[0].second + 1 < 8)
			{
				v[0].first++;
				v[0].second++;

				if (v[0].first == v[1].first && v[0].second == v[1].second)
				{
					if (v[1].first + 1 < 8 && v[1].second + 1 < 8)
					{
						v[1].first++;
						v[1].second++;
					}
					else
					{
						v[0].first--;
						v[0].second--;
					}
				}
			}
		}

		else if (od == "LB")	//왼쪽아래대각선
		{
			if (v[0].first + 1 < 8 && v[0].second - 1 >= 0)
			{
				v[0].first++;
				v[0].second--;

				if (v[0].first == v[1].first && v[0].second == v[1].second)
				{
					if (v[1].first + 1 < 8 && v[1].second - 1 >= 0)
					{
						v[1].first++;
						v[1].second--;
					}
					else
					{
						v[0].first--;
						v[0].second++;
					}
				}
			}
		}
		
	}

	vector<string>strVec(2);

	for (int i = 0; i < 2; i++)	//현재좌표값을 다시 알파벳과 숫자로 변환
	{	
		char chTemp = 'A';

		for (int j=0;j<8;j++)
		{
			if (v[i].second == j)
				strVec[i] += chTemp;

			chTemp++;
		}

		int nuTemp = 8 - v[i].first;

		strVec[i] += to_string(nuTemp);

	}

	for (int i = 0; i < 2; i++)	//결과출력
		cout << strVec[i] << '\n';

	return 0;
}