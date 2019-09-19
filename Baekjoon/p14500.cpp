/*
    테트로미노
    https://www.acmicpc.net/problem/14500
 */

#include <iostream>
#include <algorithm>

using namespace std;
int maps[501][501] = {0, };

void findMax(int map[][], int i, int j, int &max)
{
    int tmpMax = 0;
    /* case1. 도형1 */
    tmpMax = map[i][j] + map[i][j+1] 
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int toInputInt;
            cin >> toInputInt;
            maps[i][j] = toInputInt;
        }
    }


    /* 테트로미노 확인 max값 */
    int maxTetro = 0;
    for (int i = 1; i <= n-3; i++)
    {
        for (int j = 1; j <= m-3; j++)
        {
            findMax(maps, i, j, maxTetro);
        }
    }
    cout << maxTetro;
    
    return 0;
}