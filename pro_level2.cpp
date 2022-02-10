#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {

	int len = progresses.size();	//작업의 개수
	vector<pair<int, int>>v(len);	
	vector<int> answer(len);	//결과를 저장할 vector
	stack<pair<int, int>>s;	//stack 선언
	int cnt = 1;	//날짜를 저장할 변수
	int idx = 0;	//결과 vector의 인덱스 변수

	for(int i=0;i<len;i++)	//매개변수로 받은 vector 값들을 역순으로 저장
	{
		v[i].first = progresses.back();
		v[i].second = speeds.back();
		speeds.pop_back();
		progresses.pop_back();
	}

	for (int i = 0; i < v.size(); i++)	//저장한 값을 stack에 push
	{
		s.push(make_pair(v[i].first, v[i].second));
	}

	while (!s.empty())
	{	
		int pro = s.top().first;	//stack의 top저장, 작업의진도
		int spd = s.top().second;	//개발속도

		pro += spd * cnt;	//작업의 진도에 개발속도 * 날짜를 더한다.	

		if (pro >= 100)	//작업의 진도가 100이상일 경우
		{
			s.pop();	//stack의 값 삭제
			answer[idx]++;	//배포개수 증가

			while (!s.empty())	//다음 작업이 같이 배포되는지 확인하는 반복문
			{
				int x = s.top().first;
				int y = s.top().second;
				x += y * cnt;

				if (x >= 100)	//작업의 진도가 100이상일 경우
				{
					s.pop();	
					answer[idx]++;	//배포개수 증가
				}
				else
				{	
					idx++;	//작업의 진도가 충족되지 않는 경우, 인데스증가
					break;	//반복문종료
				}
			}
		}

		cnt++;	//날짜 증가
	}

	answer.erase(answer.begin() + idx+1, answer.begin() + len);	//vector의 비어있는 인덱스 삭제

	return answer;	//결과 반환
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int>a;	//입력 예제
	vector<int>b;

	a.push_back(95);
	a.push_back(90);
	a.push_back(99);
	a.push_back(99);
	a.push_back(80);
	a.push_back(99);

	b.push_back(1);
	b.push_back(1);
	b.push_back(1);
	b.push_back(1);
	b.push_back(1);
	b.push_back(1);

	vector<int>result = solution(a, b);	//함수로 전달

	for (auto it = result.begin(); it != result.end(); it++)	//결과출력
		cout << *it << " ";



	return 0;
}