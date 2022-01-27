#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int func(string str)
{
	stack<char> s;	//stack 선언
	char ch;
	int result = 0;	//결과값 저장 할 변수

	for (int i = 0; i < str.length(); i++)	
	{
		ch = str[i];

		if (ch == '(')	//여는괄호일경우 stack에 push
		{
			s.push(ch);
		}

		else if (ch == ')')	//닫는괄호일경우
		{	
			s.pop();	//stack에 데이터 삭제

			if (str[i-1] == '(')	//str[i-1]이 ( 인경우 레이저 임으로 스택의 사이즈를 결과값에 더한다.
				result += s.size();
			else
				result++;	//그외의 경우는 막대기의 끝임으로 결과값에 1을 더한다

		}
	}
	return result;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string temp;

	cin >> temp;	//괄호입력
	cout<<func(temp);	//결과출력
	
	return 0;
}
