/*
    1, 2, 3 더하기
    https://www.acmicpc.net/problem/9095
 */

#include <iostream>

using namespace std;

const int MAX = 12;
int d[MAX] = {0, };

int main(){
    int n;
    cin >> n;

    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for (int i = 4; i <= MAX; i++)
    {
        d[i] = d[i-1] + d[i-2] + d[i-3];
    }
    while (n--)
    {
        int k;
        cin >> k;
        cout << d[k] << '\n';
    }
    return 0;
}