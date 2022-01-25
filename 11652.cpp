#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int count = 0;
	int max = 0;

	vector<long long> v(n); //입력받을수가 -2^62 ~ 2^62 이기때문에 long long 으로 vector 선언

	for (int i = 0; i < n; i++)	//카드에 있는 정수를 입력받는 반복문
		cin >> v[i];

	sort(v.begin(), v.end());	//오름차순으로 정렬

	long long result = v[0];	//결과값을 저장할 변수

	for (int i = 1; i < n; i++)	//중복의 개수판단을 위한 반복문
	{
		if (v[i] == v[i - 1])	//앞뒤 정수가 중복인 경우
		{
			count++;	//count에 1을 더한다

			if (max < count)	//max보다 count가 클경우
			{
				max = count;	//max에 count 저장
				result = v[i];	//결과값에 해당 정수 저장
			}
		}
		else
			count = 0;	//앞뒤 정수가 중복이 아니면 count 초기화
	}

	cout << result;	//결과출력

	return 0;
}
