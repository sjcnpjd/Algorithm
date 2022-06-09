#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

//톱니바퀴는 총4개, 입력할때 12방향부터 시계방향으로 입력
//N극은 0 , S극은 1
//같은 극이면 회전 X, 다른극일경우 이전 톱니바퀴에 반대방향으로 회전 ex) 이전바퀴 시계방향회전 -> 다음 바퀴 반시계방향회전

int k;	//회전회수
int num;	//회전할 톱니 번호
int dir;	//회전방향, 1일경우 시계방향 -1일 경우 반시계방향
int t1[8], t2[8], t3[8], t4[8];	//톱니바퀴
string str;
int answer = 0;	//결과값

void func(int idx)	//매개변수로 회전해야할 톱니바퀴 번호를 받고 시계방향으로 회전하는 함수
{	
	int temp;
	int last;

	if (idx == 1)
	{	
		last = t1[7];	//마지막 값 저장

		for (int i = 6; i >= 0; i--)
		{
			t1[i + 1] = t1[i];	//7-6, 6-5, 5-4, 4-3, 3-2, 2-1, 1-0  
		}
		t1[0] = last;	//시계방향 회전임으로 마지막 값을 첫번째 값으로 이동
	}
	else if (idx == 2)
	{
		last = t2[7];

		for (int i = 6; i >= 0; i--)
		{
			t2[i + 1] = t2[i];	//7-6, 6-5, 5-4, 4-3, 3-2, 2-1, 1-0  
		}
		t2[0] = last;
	}
	else if (idx == 3)
	{
		last = t3[7];

		for (int i = 6; i >= 0; i--)
		{
			t3[i + 1] = t3[i];	//7-6, 6-5, 5-4, 4-3, 3-2, 2-1, 1-0  
		}
		t3[0] = last;
	}
	else if (idx == 4)
	{
		last = t4[7];

		for (int i = 6; i >= 0; i--)
		{
			t4[i + 1] = t4[i];	//7-6, 6-5, 5-4, 4-3, 3-2, 2-1, 1-0  
		}
		t4[0] = last;
	}

}

void refunc(int idx)	//매개변수로 회전해야할 톱니바퀴 번호를 받고 반 시계방향으로 회전하는 함수
{
	int temp;
	int last;

	if (idx == 1)
	{
		last = t1[0];	//첫번째 값 저장

		//7-0, 6-7 , 5-6 , 4-5 , 3-4, 2-3 , 1-2 , 0-1

		for (int i = 0; i < 7; i++)
		{
			t1[i] = t1[i+1];	//0-1, 1-2 , 2-3, 3-4 , 4-5 ,5-6 ,6-7
		}
		t1[7] = last;	//반시계 방향임으로 첫번째 값을 마지막값으로 이동
	}
	else if (idx == 2)
	{
		last = t2[0];

		//7-0, 6-7 , 5-6 , 4-5 , 3-4, 2-3 , 1-2 , 0-1

		for (int i = 0; i < 7; i++)
		{
			t2[i] = t2[i + 1];	//0-1, 1-2 , 2-3, 3-4 , 4-5 ,5-6 ,6-7
		}
		t2[7] = last;
	}
	else if (idx == 3)
	{
		last = t3[0];

		//7-0, 6-7 , 5-6 , 4-5 , 3-4, 2-3 , 1-2 , 0-1

		for (int i = 0; i < 7; i++)
		{
			t3[i] = t3[i + 1];	//0-1, 1-2 , 2-3, 3-4 , 4-5 ,5-6 ,6-7
		}
		t3[7] = last;
	}
	else if (idx == 4)
	{
		last = t4[0];

		//7-0, 6-7 , 5-6 , 4-5 , 3-4, 2-3 , 1-2 , 0-1

		for (int i = 0; i < 7; i++)
		{
			t4[i] = t4[i + 1];	//0-1, 1-2 , 2-3, 3-4 , 4-5 ,5-6 ,6-7
		}
		t4[7] = last;
	}

}

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 각 톱니바퀴의 초기값을 입력

	cin >> str;
	for (int i = 0; i < 8; i++)
		t1[i] = str[i] -'0';

	cin >> str;
	for (int i = 0; i < 8; i++)
		t2[i] = str[i] - '0';

	cin >> str;
	for (int i = 0; i < 8; i++)
		t3[i] = str[i] - '0';

	cin >> str;
	for (int i = 0; i < 8; i++)
		t4[i] = str[i] - '0';

	cin >> k;	//회전횟수 입력

	for (int i = 0; i < k; i++)
	{
		cin >> num >> dir;

		if (dir == 1)	//첫번째 톱니바퀴의 회전일 경우
		{
			if (num == 1)
			{	
				if (t1[2] != t2[6])	//첫번째 톱니바퀴를 회전하기전 2, 3, 4 톱니바퀴의 맞닿은 극의 상태를 확인하고 회전
				{	
					if (t2[2] != t3[6])
					{	
						if (t3[2] != t4[6])
						{
							refunc(4);
						}

						func(3);
					}

					refunc(2);
				}

				func(1);
				
			}
			else if (num == 2)
			{	
				if (t1[2] != t2[6])
				{	
					refunc(1);
				}
				if (t2[2] != t3[6])
				{
					if (t3[2] != t4[6])
					{
						func(4);
					}

					refunc(3);
				}


				func(2);
				
			}
			else if (num == 3)
			{	
				if (t3[2] != t4[6])
				{
					refunc(4);
				}
				if (t3[6] != t2[2])
				{	
					if (t2[6] != t1[2])
					{
						func(1);
					}

					refunc(2);
				}

				func(3);
			
			}
			else if (num == 4)
			{	
				if (t4[6] != t3[2])
				{	
					if (t3[6] != t2[2])
					{	
						if (t2[6] != t1[2])
						{
							refunc(1);
						}

						func(2);
					}

					refunc(3);
				}

				func(4);
				
			}
		}
		else if(dir == -1)
		{
			if (num == 1)
			{
				if (t1[2] != t2[6])
				{
					if (t2[2] != t3[6])
					{
						if (t3[2] != t4[6])
						{
							func(4);
						}

						refunc(3);
					}

					func(2);
				}

				refunc(1);
			}
			else if (num == 2)
			{
				if (t1[2] != t2[6])
				{
					func(1);
				}
				if (t2[2] != t3[6])
				{
					if (t3[2] != t4[6])
					{
						refunc(4);
					}

					func(3);
				}


				refunc(2);
			}
			else if (num == 3)
			{
				if (t3[2] != t4[6])
				{
					func(4);
				}
				if (t3[6] != t2[2])
				{
					if (t2[6] != t1[2])
					{
						refunc(1);
					}

					func(2);
				}

				refunc(3);
			}
			else if (num == 4)
			{
				if (t4[6] != t3[2])
				{
					if (t3[6] != t2[2])
					{
						if (t2[6] != t1[2])
						{
							func(1);
						}

						refunc(2);
					}

					func(3);
				}

				refunc(4);
			}
		}
		
	}
	

	if (t1[0] == 1)	//각톱니바퀴별로 12시방향이 S극일 경우 각각의 점수 추가
		answer += 1;
	if (t2[0] == 1)
		answer += 2;
	if (t3[0] == 1)
		answer += 4;
	if (t4[0] == 1)
		answer += 8;

	cout << answer;	//총 점수 출력
;

	return 0;
}