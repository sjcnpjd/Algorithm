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
    
    int n;
    string temp;
    int sum = 0;
    int num = 0;
    vector<int>v;
    cin >> n;

    for (int i = 0; i < n; i++)
    {   
        sum = 0;
        num = 0;
        cin >> temp;

        for (int j = 0; j < temp.length(); j++)
        {
            if (temp[j] == 'O')
            {
                num++;
            }
            else
            {
                num = 0;
            }
            sum += num;
        }
        v.push_back(sum);
    }

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';

    return 0;
}