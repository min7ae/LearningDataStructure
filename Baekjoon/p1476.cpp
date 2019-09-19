/*
    날짜 계산
    https://www.acmicpc.net/problem/1476
 */

#include <iostream>
using namespace std;

int main()
{
    int e, s, m;
    cin >> e >> s >> m;
    int maxYear = 15 * 28 * 19;
    for (int i = 1; i <= maxYear; i++)
    {
        if ((i % 15) == (e % 15))
        {
            if ((i % 28) == (s % 28))
            {
                if ((i % 19) == (m % 19))
                {
                    cout << i;
                    return 0;
                }
            }
        }
    }
    return 0;
}