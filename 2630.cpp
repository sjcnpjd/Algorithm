#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int map[129][129];  //전체종이
int wcnt = 0;   //하얀색 색종이의 수
int bcnt = 0;   //파란색 색종이의 수
int n;  //한변의길이
int len;

void func(int a,int b,int l)    //각각의 색종이를 확인하는 함수
{   
    int wc = 0;
    int bc = 0;
    int check = false;

    for (int i = a; i < a+l; i++)   //입력받은 매개변수에서 색종이의 길이만큼 확인
    {
        for (int j = b; j < b+l; j++)
        {
            if (map[i][j] == 1)
                bc++;
            else if (map[i][j] == 0)
                wc++;
        }
    }

    if (wc == l * l)
    {
        wcnt++;
        check = true;
    }
    else if (bc == l * l)
    {
        bcnt++;
        check = true;
    }

    if (check == true)
    {
        for (int i = a; i < a + l; i++)
            for (int j = b; j < b + l; j++)
                map[i][j] = -1; //색종이로 확인된경우 -1저장으로 제외
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    cin >> n;
    len = n;    //한변의 길이를 len에 저장

    for (int i = 0; i < n; i++) //전체종이 입력
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    int tempw = 0;
    int tempb = 0;

    for (int i = 0; i < n; i++) //종이전체가 모두 같은색인지 확인하기위한 반복문
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 0)
                tempw++;
            else if (map[i][j] == 1)
                tempb++;
        }
    }

    if (tempw == n * n) //종이전체가 하얀색인 경우
    {
        cout << wcnt + 1 << '\n' << bcnt;
        return 0;
    }

    if (tempb == n * n) //종이전체가 파란색인 경우
    {
        cout << wcnt << '\n' << bcnt + 1;
        return 0;
    }


    while (1)
    {   
      len /= 2; //4개의 색종이로 나누기 위해서 len / 2 

      for (int i = 0; i < n; i += len)  
      {
          for (int j = 0; j < n; j += len)
          {
              func(i, j, len);  //나눈 색종이의 시작점을 매개변수로 전달
          }
      }

      if (len == 1)break;   //더이상자를수없는 경우

      //0,0 - 0,4 - 4,0 -4,4
      //0,0 - 0,2 - 0,4 - 0,6 - 2,0 - ...
    }
    
    
    cout << wcnt << '\n' << bcnt;


    return 0;
}