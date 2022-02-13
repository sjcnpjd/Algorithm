#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>


using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";	//결과를 저장할 변수
	multiset<string>s;	//중복된 key값 저장가능하며, 오름차순으로 정렬되는 multiset 선언

	for (int i = 0; i < participant.size(); i++)	//참여자들을 multiset에 insert
		s.insert(participant[i]);
	
	for (auto it = completion.begin();it != completion.end();it++)	
	{	
			s.erase(s.find(*it));	//multiset에서 완주한 선수를 찾은 후 삭제
	}
	answer = *(s.begin());	//multiset에 남은 값은 완주하지 못한 선수

	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}