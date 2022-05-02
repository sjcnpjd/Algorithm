#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>


using namespace std;

bool check(int n)   //소수여부 확인
{
    int cnt = 2;

    for (int i = 1; i <= n; i++)   //1과 n외에 나눠지는값이 있다면 종료
    {
        if (i == 1)continue;
        if (i == n)continue;

        if (n % i == 0)
        {
            cnt++;
            break;
        }
    }

    if (cnt == 2)
        return true;
    else
        return false;

}

int solution(vector<int> nums) {
    int answer = 0;

    for (int i = 0; i < nums.size(); i++)  //3중for문
    {
        for (int j = i; j < nums.size(); j++)
        {
            if (i == j)continue;

            for (int k = j; k < nums.size(); k++)
            {
                if (k == i || k == j)continue;

                int temp = nums[i] + nums[j] + nums[k];
                bool res = check(temp);

                if (res)
                    answer++;
            }
        }
    }

    return answer;
}