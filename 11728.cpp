#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <string>
#include <set>


using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, m;
    int temp;
    vector<int> vn, vm;

    cin >> n >> m;

    for (int i = 0; i < n; i++) //n값들 입력
    {
        cin >> temp;
        vn.push_back(temp);
    }

    for (int i = 0; i < m; i++) //m값들 입력
    {
        cin >> temp;
        vm.push_back(temp);
    }

    for (int i = 0; i < m; i++) //vm에 저장된 값들을 vn에 저장
        vn.push_back(vm[i]);

    sort(vn.begin(), vn.end()); //오름차순정렬

    for (auto it = vn.begin(); it != vn.end(); it++)    //결과출력
        cout << *it << " ";

    return 0;
}