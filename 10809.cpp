#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char temp;
	string s;
	int num = 0;
	int arr[26];	//알파벳 위치 및 포함여부를 저장할 배열

	cin >> s;	//단어입력

	fill(arr, arr + 26, -1);	//배열을 -1로 초기화

	for (int i = 0; i < s.length(); i++)
	{
		temp = s[i];	//단어의 알파벳을 한글자씩 저장
		for (char j = 'a'; j<= 'z'; j++)	
		{
			if (temp == j)	//같은 알파벳이 있을 경우
			{
				num = j - 'a';	//알파벳의 위치를 정수로 저장

				if(arr[num]==-1)	//해당위치가 비어있으면
					arr[num] = i;	//해당알파벳이 단어에서 처음등장하는 위치 저장
			}
		}
	}

	for (int i = 0; i < 26; i++)	//결과출력
		cout << arr[i] << " ";

	return 0;
}