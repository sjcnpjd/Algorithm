#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

bool cmp(string a, string b)
{	
	return a + b > b + a;	// ex) a=10, b=2 -> a+b=102, b+a=210
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string>v;

	for (int i = 0; i < numbers.size(); i++)
		v.push_back(to_string(numbers[i]));
	
	sort(v.begin(), v.end(),cmp);	//내림차순으로 정렬, cmp함수의 조건을 만족하도록 정렬된다

	for (auto it = v.begin();it != v.end();it++)	//vector의 시작숫자부터 answer에 더한다
		answer += *it;
	
	if (answer[0] == '0')	//시작숫자가 0일 경우 0으로 초기화
		answer = "0";

	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int>a;
	a.push_back(123);
	a.push_back(134);
	a.push_back(543);


	string str = solution(a);
	cout << str;

	return 0;
}