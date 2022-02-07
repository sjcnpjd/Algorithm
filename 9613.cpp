#include <iostream>
#include <algorithm>
#include <bitset>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t,n;	
	int temp;
	long long sum = 0;	//각 테스트케이스의 합을 저장할 변수
	vector<int>v;
	vector<long long>result;	//출력할 결과를 저장할 vector

	cin >> t;	//테스트케이스 입력

	for (int i = 0; i < t; i++)
	{
		cin >> n;	//수의개수 입력
		sum = 0;	//sum 초기화
		v.clear();	//vector 초기화

		for (int i = 0; i < n; i++)
		{
			cin >> temp;	//수 입력
			v.push_back(temp);	//vector에 push
		}
		for (int i = 0; i < v.size()-1; i++)	//vector에 저장된 모든 쌍들을 gcd함수로 전달하는 반복문
		{
			for (int j = i + 1; j < v.size(); j++)
			{
				sum += gcd(v[i], v[j]);	//gcd함수에서 리턴된 값을 sum에 저장
			}
		}
		result.push_back(sum);	//result에 sum을 push
	}

	for (int i = 0; i < result.size(); i++)	//결과값 출력
		cout << result[i] << '\n';

	return 0;
}