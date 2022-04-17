#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;


int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string pt;
	string temp;
	
	vector<string>v;
	int n;

	cin >> n;	//문자열개수입력
	cin >> pt;	//문자열패턴입력

	for (int i = 0; i < n; i++)
	{
		cin >> temp;	//확인할 문자열 입력

		stack<char>s;
		for (int j = pt.size() - 1; j >= 0; j--)	//패턴을 stack에 역순으로 저장, stack의 구조상 꺼낼때 패턴의 앞부터 확인하게됨
			s.push(pt[j]);

		int idx = 0;	//현재인덱스 저장할 변수

		while (1)
		{	
			if (s.empty())	//stack이 비어있다면 패턴을 모두확인한 것임으로 일치한경우
			{
				v.push_back("DA");
				break;
			}

			if (temp[idx] == s.top())	//현재위치의 문자가 패턴과 일치한경우
			{
				idx++;	//인덱스증가
				if(!s.empty())	//stack 값 삭제
					s.pop();
				
			}
			else if (s.top() == '*')	//*을 만난경우 현재까지 패턴이 모두일치한것
			{
				if(!s.empty())	//stack 값 삭제
					s.pop();

				int len = s.size();	//남은 패턴의 문자수

				if (temp.size() - (idx - 1) <= len)	//현재까지 확인한 문자들을 빼고 남은 문자의 수가 len과 같거나 작은경우
				{
					v.push_back("NE");	//일치할 수 없기에 NE 저장 후 종료
					break;
				}
				
				idx = temp.size() - len;	//위의 경우가 아니라면 문자열의 개수 - len을 통해서 문자열의 뒷부분으로 idx 값 저장 
			}
			else
			{
				v.push_back("NE");	//패턴과 일치하지 않은경우
				break;
			}
		}

	}


	for (int i = 0; i < v.size(); i++)	//결과출력
		cout << v[i] << '\n';
	
	return 0;
}