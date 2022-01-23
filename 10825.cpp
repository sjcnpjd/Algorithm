#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct student {	//student구조체 정의
	string name;	//이름
	int ko;	//국어점수
	int en;	//영어점수
	int ma;	//수학점수
};

bool cmp(student a, student b)	//정렬에 사용될 조건정의
{
	if (a.ko == b.ko)	//국어성적이 같다면
	{
		if (a.en == b.en)	//영어성적이 같다면
		{
			if (a.ma == b.ma)	//수학성적이 같다면
			{
				return a.name < b.name;	//이름이 증가하는 순서로 반환
			}

			return a.ma > b.ma;	//수학성적이 감소하는 순서로 반환
		}

		return a.en < b.en;	//영어성적이 증가하는 순서로 반환
	}
	return a.ko > b.ko;	//국어성적이 감소하는 순서로 반환
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;	//학생수 입력

	vector<student>v(n);	//학생구조체의 vector 생성

	for (int i = 0; i < n; i++)	//이름 및 점수 입력받는 반복문
	{
		cin >> v[i].name >> v[i].ko >> v[i].en >> v[i].ma;
	}

	sort(v.begin(), v.end(), cmp);	//정렬

	for (int i = 0; i < n; i++)	//결과출력 반복문
		cout << v[i].name<<'\n';

	return 0;
}
