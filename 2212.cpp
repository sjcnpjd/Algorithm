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

    
    int n, k;
    int sum = 0;
    cin >> n;
    cin >> k;
    vector<int>v(n);
    vector<int>result(n-1);


    for (int i = 0; i < n; i++)
        cin >> v[i];
    

    sort(v.begin(), v.end());

    for (int i=0;i<n-1;i++)
       result[i] = v[i + 1] - v[i];  

    sort(result.begin(), result.end());

    for (int i = 0; i < n - k; i++)
        sum += result[i];
    
    
    cout << sum;

	return 0;
}