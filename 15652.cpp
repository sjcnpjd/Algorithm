#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <utility>

using namespace std;

#define MAX 9	

int n, m;
vector<int>result;	//결과를 저장할 vector

void dfs(int cnt,int pre)	
{
	if (cnt == m)	//cnt == m  경우 결과 출력
	{
		for (int i = 0; i < m; i++)
		{
			cout << result[i] << " ";
		}
		cout << '\n';
	}
	else
	{
		for (int i = 1; i <= n; i++)	//1부터 n이하의 자연수까지 반복
		{	
			if (i < pre)continue;	//수열을 비내림차순으로 만들기위해서 이전 자연수보다 작을 경우 continue
			result.push_back(i);	//result에 i값 push
			pre = i;	//pre에 i 저장
			dfs(cnt + 1, pre);	//cnt를 증가하고 pre값 전달, 재귀
			result.pop_back();	//result 값 삭제

		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;	//n, m 입력
	dfs(0,1);

	return 0;
}