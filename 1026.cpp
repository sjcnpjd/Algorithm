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
	cin >> n;	//길이 입력

	vector<int>a(n);	//vector 선언
	vector<int>b(n);

	int midx=0;	//가장큰수의 인덱스를 저장할 변수
	int sum = 0;	//결과출력을 위한 변수

	for (int i = 0; i < n; i++)	//첫번째 배열 입력
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; i++)	//두번째 배열 입력
	{
		cin >> b[i];
	}

	sort(a.begin(), a.end());	//첫번째 배열 오름차순 정렬

	for (int i = 0; i < n; i++)	//배열의 길이만큼 반복
	{
		midx = max_element(b.begin(), b.end()) - b.begin();	//두번째 배열에서 가장큰수가 저장된 인덱스 저장
		sum += a[i] * b[midx];	//합계에 a의 가장작은수와 b의 가장큰수의 곱을 더한다.
		b[midx] = 0;	//사용한 가장큰수는 초기화
	}

	cout << sum;

	return 0;
}
