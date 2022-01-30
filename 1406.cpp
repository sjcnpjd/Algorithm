#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;	//초기입력을 저장할 문자열
	int m;	//명령어의 개수를 저장할 변수
	list<char> chlist;	//리스트 선언
	char input;	//명령어 입력을 할 변수
	char temp;	

	cin >> str;
	cin >> m;

	for (int i = 0; i < str.length(); i++)	//초기문자열을 list에 저장
		chlist.push_back(str[i]);
		
	list<char>::iterator it = chlist.end();	//iterator를 사용하여 list의 원소들에 접근, 초기위치는 리스트의 맨뒤


	for (int i = 0; i < m; i++)	//명령어의 개수만큼 반복
	{
		cin >> input;	//명령어 입력

		if (input == 'P')	
		{
			cin >> temp;	//추가할 문자입력
			chlist.insert(it, temp);	//iterator의 위치의 문자 추가
		}
		else if (input == 'L')
		{
			if(it!=chlist.begin())	//iterator가 맨 앞이 아니라면
				it--;	//iterator를 왼쪽으로 한칸 이동
		}
		else if (input == 'D')
		{
			if (it != chlist.end())	//iterator가 맨 뒤가 아니라면
				it++;	//iterator를 오른쪽으로 한칸 이동
		}
		else if (input == 'B')
		{
			if (it != chlist.begin())	//iterator가 맨 앞이 아니라면
			{
				it = chlist.erase(--it);	//커서왼쪽에 문자를 삭제
			}
		}

	}

	for (it = chlist.begin(); it != chlist.end(); it++)	//결과값출력
		cout << *it;


	return 0;
}