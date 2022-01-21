#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int count;	
	cin >> n;	//전체 사람의 수
	
	vector<pair<int,int>> v(n);	//몸무게와 키를 입력받을 vector
	vector<int>rank(n);	//등수를 저장할 vector

	for (int i = 0; i < n; i++)	//몸무게 및 키 입력
	{
		cin >> v[i].first >> v[i].second;
	}

	for (int i = 0; i < n; i++)
	{	
		count = 0;	//count 초기화
		for (int j = 0; j < n; j++)	//첫번째 사람부터 다른 사람들과 비교하는 반복문
		{
			if (v[i].first < v[j].first && v[i].second < v[j].second)
				count++;	//덩치가 큰사람이 있을 경우 count에 1을 더한다
		}
		rank[i] = count + 1;	//vector에 등수 저장
	}

	for (int i = 0; i < n; i++)	//결과출력
		cout << rank[i] << " ";

	return 0;
}
