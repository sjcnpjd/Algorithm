#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<int> solution(vector<int> prices) {

	vector<int> answer;	//정답을 반환할 vector
	queue<int>q;	//queue 선언
	int result;	//각각의 시간을 저장할 변수
	int idx;	
	int len = prices.size();	//매개변수로 받은 vector의 개수
	
	for (int i = 0; i < len; i++)	//queue에 prices을 push
		q.push(prices[i]);

	idx = 0;

	while (!q.empty())
	{	
		result = 0;	//시간초기화
		
		int num = q.front();	//queue의 front값 저장
		q.pop();	//삭제

		for (int i = idx+1; i < len; i++)	//가격이 변화를 확인하는 반복문
		{
			if (num <= prices[i])	//떨어지지않은경우, 시간증가
			{
				result++;
			}
			else
			{	
				result++;	//떨어진경우, 시간증가후 반복문 종료
				break;
			}
		}
		answer.push_back(result);	//시간을 answer에 push
		idx++;	//idx증가
	}

	return answer;	//결과반환
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	return 0;
}