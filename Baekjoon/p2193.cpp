/*
    이친수
    https://www.acmicpc.net/problem/2193
*/

#include <iostream>

using namespace std;

const int inpMax = 90;
int p[inpMax+1] = {0, };

int main(){
    int n;
    cin >> n;

    p[0] = p[1] = p[2] = 1;
    for (int i = 3 ; i <= n; i++)
    {
        for (int j = 0; j <= i-2; j++)
        {
            p[i] += p[j];
        }
    }
    
    cout << p[n] << '\n';

    return 0;
}