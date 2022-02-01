#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int gcd(int a, int b)	//최대공약수를 구하는 함수
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	int t;
	int num;
	cin >> t;
	vector<int>v(t);

	for (int i = 0; i < t; i++)	//테스트케이스만큼 반복
	{	
		cin >> a >> b;
		v[i] = (a*b)/gcd(a, b);	//(a * b) / a,b의 최대공약수 = 최소공배수 
	}

	for (int i = 0; i < t; i++)	//결과출력
		cout << v[i] << '\n';


	return 0;
}