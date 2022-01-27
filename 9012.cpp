#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

string func(string str)
{
	stack<char> s;	//stack 선언
	char ch;

	for (int i = 0; i < str.length(); i++)	
	{
		ch = str[i];	//매개변수로 받은 문자열을 한글자씩 확인하기 위해 ch에 저장
		if (ch == '(')	//여는괄호일 경우 stack에 push
		{
			s.push(ch);
		}
		else if (ch == ')')	//닫는 괄호일 경우 
		{	
			if (!s.empty())	//stack이 비어있지않다면
			{
				if ('(' == s.top())	//stack에 top이 여는괄호라면
				{
					s.pop();	//stack에서 여는괄호를 삭제
				}
			}
			else
				return "NO";	//stack이 비어있다면 NO 반환
		}
	}

	if (s.empty())	//반복문이 끝나고 stack이 비어있다면 괄호의 모양이 올바른 것임으로 YES 반환
		return "YES";
	else
		return "NO";

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;	//입력할 데이터수 입력

	string temp;
	vector<string>v(t);	//결과값을 저장할 vector

	for (int i = 0; i < t; i++)	
	{
		cin >> temp;	//테스트데이터 입력
		v[i] = func(temp);	//결과값 vector에 저장
	}

	for (int i = 0; i < t; i++)	//결과값 출력
		cout << v[i] << '\n';
	
	
	return 0;
}
