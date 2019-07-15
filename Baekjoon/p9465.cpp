/*
    스티커
    https://www.acmicpc.net/problem/9465
 */

#include <iostream>
#define max(a, b) (((a)>(b))?(a):(b))

using namespace std;

const int maxCase = 100000;
// 들어갈 case
/*

    1,2를 사용하기 위해서 p[][3] 
 */
int p[maxCase + 1][2 + 1] = {0, };
// max case
int a[maxCase + 1][2 + 1] = {0, };

int main(){
    int n;
    cin >> n;
    while (n--)
    {
        int k;
        cin >> k;
        for (int i = 1; i <= k; i++)
        {
            cin >> p[i][1];
        }
        for (int i = 1; i <= k; i++)
        {
            cin >> p[i][2];
        }
        for (int i = 1; i <= k; i++)
        {
            a[i][1] = max(p[i][1] + a[i-1][2], a[i-1][1]);
            a[i][2] = max(p[i][2] + a[i-1][1], a[i-1][2]);
        }
        
        cout << max(a[k][1], a[k][2]) << '\n';
    }
    
    return 0;
}