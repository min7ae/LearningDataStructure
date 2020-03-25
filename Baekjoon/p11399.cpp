/*
    ATM
    https://www.acmicpc.net/problem/11399
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool asc(int a, int b)
{
    return a < b;
}

int main()
{
    /*
        사람의 수: n
        각 사람이 걸리는 시간 p[n];
     */
    int n;
    vector<int> v;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int timetoWithdraw;
        cin >> timetoWithdraw;
        v.push_back(timetoWithdraw);
    }

    /* 오름차순 */
    sort(v.begin(), v.end() );

    /*
        1. 오름차순 정렬
        2. a번째 있는 수는 1부터 a까지 있는 숫자를 모두 더한 값이 자신이 기다린 시간
        3. 각자 시간을 n명 다 더한다.
     */
    int r = 0;
    for(int i=0; i<n; i++)
    {
        int innerR = 0;
        for(int j = 0; j <= i; j++)
        {
            innerR += v[j];
        }
        r += innerR;
    }
    printf("%d", r);

    return 0;
}