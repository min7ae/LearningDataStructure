/*
    포도주 시식
    https://www.acmicpc.net/problem/2156
*/

#include <iostream>
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y)) 

using namespace std;

const int ciMaxdn = 10000;
int d[ciMaxdn+1] = {0, };

/*
    첫번째 요소 0: 이번에 먹지 않았을 때
    첫번째 요소 1: 이번에 처음 먹을 때
    첫번째 요소 2: 이번에 두번 째 먹을 때 
 */
int dm[ciMaxdn+1][3] = {0, };

int main(){
    int n;
    cin >> n;
    // 집어 넣고
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    
    dm[1][0] = 0;
    dm[1][1] = d[1];
    dm[1][2] = 0;

    for (int i = 2; i <= n ; i++)
    {
        
        dm[i][0] = max(dm[i-1][1], dm[i-1][2]);
        dm[i][1] = dm[i-1][0] + d[i];
        dm[i][2] = dm[i-1][1] + d[i];
    }
    int itMax = max(dm[n][0], dm[n][1]);
    cout << max(itMax, dm[n][2]);
    return 0;
}