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
	int arr[26] = { 0, };	//각알파벳 개수를 저장하는 배열, 알파벳은 총 26개

	cin >> s;	//단어입력

	for (int i = 0; i < s.length(); i++)
	{
		temp = s[i];	//입력받은 단어에서 한글자씩 temp에 저장
		for (char j = 'a'; j<= 'z'; j++)	//a ~ z 까지 반복
		{
			if (temp == j)	//temp와 같은 알파벳이 있다면
			{
				num = j - 'a';	// j - a로 정수로 저장
				arr[num]++;	//배열에서 해당 알파벳 위치의 값을 1증가
			}
		}
	}

	for (int i = 0; i < 26; i++)	//결과출력
		cout << arr[i] << " ";

	return 0;
}