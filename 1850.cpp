#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long long gcd(long long x, long long y)	//재귀함수를 활용한 유클리드호제법 사용
{
	return y ? gcd(y, x % y) : x;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long a, b;	//입력되는 수가 2^63 까지 이기때문에 long long 으로 선언
	cin >> a >> b;	//a, b 입력
	long long num;

	num = gcd(a, b);

	for (int i = 0; i < num; i++)	//최대공약수의 수만큼 1을 출력한다.
		cout << 1;

	return 0;
}