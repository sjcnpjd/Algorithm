#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

vector<int> solution(vector<string> operations) {

	vector<int> answer;	//정답을 저장할 vector
	priority_queue<int>maxq;	//우선순위큐 최대
	priority_queue<int, vector<int>, greater<int>>minq;	//최소

	string temp;

	int cnt = 0;	//우선순위큐에 저장된 수의 개수
	int len = operations.size();

	for (int i = 0; i < len; i++)
	{	
		if (cnt <= 0 && !maxq.empty())	//저장된 수의 개수가 0이하 이지만 maxq가 비어있지 않은경우
		{	
			maxq = priority_queue<int>();	//maxq, cnt 초기화
			cnt = 0;
		}

		if (cnt <= 0 && !minq.empty())	//저장된 수의 개수가 0이하 이지만 minq가 비어있지 않은경우
		{
			minq = priority_queue<int, vector<int>, greater<int>>();	//minq, cnt 초기화
			cnt = 0;
		}

		if (operations[i].substr(0, 1) == "I")	//명령어가 I 숫자 인경우
		{	
			int num = 0;
			temp = operations[i];
			for (int i = 0; i < temp.size(); i++)	//아스키코드활용하여 숫자를 num에 저장
			{
				if (temp[i] >= 48 && temp[i] <= 57)
				{
					num = (num * 10) + (temp[i] - 48);
				}
			}

			if (temp[2] == '-')	//음수인경우
				num = num * -1;
	
			maxq.push(num);	//우선순위큐에 각각 push
			minq.push(num);
			cnt++;	//저장된 수증가
		}
		else if (operations[i].substr(0, 3) == "D 1")	//최대값 삭제
		{
			if (!maxq.empty())	//최대힙의 최대값 삭제
			{
				maxq.pop();
				cnt--;
			}
				
		}
		else if (operations[i].substr(0, 4) == "D -1")	//최솟값 삭제
		{	
			if (!minq.empty())	//최소힙의 최솟값 삭제
			{
				minq.pop();
				cnt--;
			}
				
		}

	}

	if (cnt <= 0)	//우선순위큐가 비어있을 경우 0을 2번 push
	{
		answer.push_back(0);
		answer.push_back(0);
	}
	//else if (cnt == 1)	//저장된 수가 1개일 경우
	//{	
	//	while (1)
	//	{
	//		int n = minq.top();
	//		if (maxq.top() == n)
	//		{
	//			answer.push_back(n);
	//			answer.push_back(n);
	//			break;
	//		}
	//		if (!minq.empty())
	//			minq.pop();
	//		else if (!maxq.empty())
	//			maxq.pop();
	//	}
	//}
	else
	{
		answer.push_back(maxq.top());	//최대값 및 최솟값 push
		answer.push_back(minq.top());
	}

	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string>a;	//입력예시
	a.push_back("I 16");
	a.push_back("I -5643");
	a.push_back("D 1");
	a.push_back("I 123");
	a.push_back("D -1");

	vector<int>temp = solution(a);	//함수호출

	for (auto it = temp.begin(); it != temp.end(); it++)	//결과출력
		cout << *it<<" ";

	return 0;
}