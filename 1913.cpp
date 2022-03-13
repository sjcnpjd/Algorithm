#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int arr[1000][1000];

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, m;
    cin >> n;
    cin >> m;

    pair<int, int>result;

    int num = n * n;
    
    int x = 0;
    int y = 0;

    int wstart = 0;
    int hstart = 0;

    int wend = n - 1;
    int hend = n - 1;

    for (int i = num; i > 0; i--)
    {   
        


        if (y == wstart && x < hend)
        {
            arr[x][y] = i;
            x++;
        }
        else if (x == hend && y < wend)
        {
            arr[x][y] = i;
            y++;
        }
        else if (x > hstart&& y == wend)
        {
            arr[x][y] = i;
            x--;
        }
        else if (x == hstart && y > wstart)
        {
            arr[x][y] = i;
            y--;

            if (y == wstart + 1)
            {
                wstart++;
                hstart++;
                wend--;
                hend--;
                //1,1,3,3
                //x=0,y=1
            }

        }
        else if (y == hstart && y == hend)
            arr[x][y] = i;

    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == m)
            {
                result.first = i + 1;
                result.second = j + 1;
            }
        }

    }
    

  
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout << '\n';
    }

    cout << result.first << " " << result.second;


    //0,0 -> 1,0 -> 2,0 -> 2,1 -> 2,2
    //1,2 -> 0,2 -> 0,1 -> 1,1
    
    return 0;
}