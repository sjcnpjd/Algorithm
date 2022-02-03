#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int temp;
	int count;
	int max = 0;
	int result=0;
	vector<int>v;

	cin >> n >> m;

	for (int i = 0; i < n; i++)	//카드에 쓰여진 수 입력
	{
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end()); //오름차순정렬

	for (int i = 0; i < n; i++)	//반복문을 활용하여 모든 값을 더해본다
	{	
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				temp = v[i] + v[j] + v[k];

				if (temp > max && temp <= m)	
				{
					max = temp;
				}
			}
		}
	}

	cout << max;
	return 0;
}