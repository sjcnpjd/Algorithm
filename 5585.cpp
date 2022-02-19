#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>


using namespace std;

int main()
{   
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n;
    int cnt = 0;
    int arr[6] = { 500,100,50,10,5,1 };
    cin >> n;

    int num = 1000 - n;

    while (num != 0)    
    {
        for (int i = 0; i < 6; i++) //큰수부터 반복
        {
            if (num % arr[i] != num)    
            {
                num -= arr[i];
                cnt++;
                break;
            }
        }
    }

    cout << cnt;
    

	return 0;
}