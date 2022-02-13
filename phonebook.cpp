#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;

bool solution(vector<string> phone_book) {

	bool answer = true;	//결과값을 반환할 변수

	sort(phone_book.begin(), phone_book.end());	//문자열을 오름차순으로 정렬

	for (int i = 0; i < phone_book.size() - 1; i++)	//substr을 활용하여 phone_book의 길이만큼 추출하여 비교 
	{	
		if(phone_book[i] == phone_book[i+1].substr(0, phone_book[i].size()))return false;	//접두어인경우 false 리턴
	}

	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}