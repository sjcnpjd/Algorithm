#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;	//n개의 수 입력
	int temp;
	int count[10001] = {0,};	//주어지는수가 10000이하이기때문에 count해줄 배열 선언 및 초기화

	for (int i = 0; i < n; i++)	//수를 입력받는 반복문
	{
		cin >> temp;
		count[temp]++;	//입력받은 수를 인덱스로 해당 인덱스의 값에 1을 더한다
	}

	for (int i = 1; i < 10001; i++)
	{
		for (int j = 0; j < count[i]; j++)	//count배열 인덱스의 값과 비교하였을때 j가 작으면 i를 출력한다. 중복값이 있다면 중복된 값만큼 출력된다.
		{
			cout << i << '\n';
		}
	}

	return 0;
}
