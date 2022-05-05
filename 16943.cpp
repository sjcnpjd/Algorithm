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

	int a, b, c;

	c = -1;

	cin >> a >> b;

	string str = to_string(a);
	sort(str.begin(), str.end());	//next_permutation을 사용하기 위해 오름차순 정렬

	do
	{
		int num = stoi(str);

		if (str[0] == '0')continue;	//문자열의 첫번째 문자가 0이면 정수로변환했을때 자리수가 변경됨으로 순열X

		if (num < b && c < num)	//b보다 작으면서 현재 c보다 크다면 num저장
			c = num;


	} while (next_permutation(str.begin(), str.end()));	//next_permutation을 활용하여 순열출력


	cout << c;	//결과출력

	return 0;
}