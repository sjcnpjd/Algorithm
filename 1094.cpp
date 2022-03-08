#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    //64 32 16 8 4 2 1

    int x;
    int answer = 0; //사용되는 막대의 개수
    int arr[7] = { 1,2,4,8,16,32,64 };
    int i = 6;
    cin >> x;

    while (x != 0)  
    {
        if (x - arr[i] >= 0)
        {
            x -= arr[i];
            answer++;
        }
        
        i--;
    }
    
    cout << answer;


    return 0;
}