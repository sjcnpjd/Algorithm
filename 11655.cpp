#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	char temp;

	getline(cin, s, '\n');	//공백도 주어질 수 있기때문에 getline 사용

	for (int i = 0; i < s.length(); i++)
	{
		temp = s[i];	//문자열의 한 글자씩 temp에 저장

			if (temp >= 'a' && temp <= 'z')	//temp가 소문자일 경우
			{
				if (temp+13 > 122)	//13글자씩 밀어서 만드는 것이 ROT13임으로 13을 더하지만 더한 값이 z를 넘어갈 경우 
				{
					s[i] = temp -= 13;	//13만큼 빼준다.
				}
				else
					s[i] = temp += 13;
			}
			else if (temp >= 'A' && temp <= 'Z')	//temp가 대문자일 경우
			{
				if (temp+13 > 90)
				{
					s[i] = temp -= 13;
				}
				else
					s[i] = temp += 13;
			}
		
	}

	cout << s;	//결과출력

	return 0;
}