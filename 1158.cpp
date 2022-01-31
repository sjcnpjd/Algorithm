#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> q;	//queue 선언
	int n, k;
	int num = 0;

	cin >> n >> k;	//n 과 k 입력

	for (int i = 1; i <= n; i++)	//queue에 1부터 n까지 값을 추가
		q.push(i);

	cout<<"<";

	while (1)
	{	
		for (int i = 1; i < k; i++)	//k번째를 찾기위한 반복문
		{
			num = q.front();	//가장 앞에 있는 값을 num에 저장하고
			q.pop();	//값을 삭제
			q.push(num);	//삭제한 값을 다시 push, 맨앞에서 맨뒤로 이동된다.
		}
		cout << q.front();	//위의 반복문이 수행되면 front는 k번째 값, 해당 값 출력
		q.pop();	//값을 삭제

		if (q.empty())	//queue가 비어있다면 종료
			break;

		cout << "," << " ";
	}

	cout << ">";

	return 0;
}