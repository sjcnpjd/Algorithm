#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>

using namespace std;


int n1,n2,t;
string str1, str2;
string temp;
vector<pair<char, int>>v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n1 >> n2;	//각그룹의개미수
	cin >> str1;	//첫번째그룹
	cin >> str2;	//두번째그룹
	cin >> t;	//초

	for (int i = str1.size()-1;i>=0;i--)	//첫번째그룹 역순으로 temp에 저장
		temp += str1[i];

	for (int i = 0; i < temp.size(); i++)	//vector에 첫번째그룹저장, pair를 활용하여 두번째값에 1저장
		v.push_back({ temp[i],1 });

	for (int i = 0; i < str2.size(); i++)	//vector에 두번째그룹저장, pair를 활용하여 두번째값에 2저장
		v.push_back({ str2[i],2 });

	

	for (int j = 0; j < t; j++)	//t만큼 반복
	{	
		int cnt = 0;	//두번째그룹이 끝까지 도착했는지 확인하기 위한 변수

		while (cnt <= n1)
		{
			if (v[cnt].second == 2)	//vector에 첫번째인덱스부터 2그룹 개미가 끝까지 도착했는지 확인하고 도착했다면 cnt증가
				cnt++;
			else
				break;
		}

		for (int i = 0+cnt; i < v.size() - 1-cnt; i++)	//개미의 순서를 변경하는 반복문, cnt값만큼 앞뒤를 제외한다
		{	
			if(i >= v.size())break;

			if (v[i].second != v[i + 1].second)	//그룹이 다르다면 변경
			{
				swap(v[i], v[i + 1]);
				i++;
			}
		}
	}

	for (int k = 0; k < v.size(); k++)	//결과출력
		cout << v[k].first;
	
	return 0;
}