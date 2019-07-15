/*
    오르막 수
    https://www.acmicpc.net/problem/11057 
 */

#include <iostream>
#include <string>

using namespace std;

const int maxLen = 1000;
const int maxNum = 10;

int p[maxLen+1][maxNum] = {0, };

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < maxNum; i++)
    {
        p[1][i] = 1; 
    }

    for (int j = 2; j <= n; j++)
    {
        for (int i = 0; i < maxNum; i++)
        {
            for (int l = 0; l <= i; l++)
            {
                p[j][i] = ( p[j][i] +  p[j-1][l] ) % 10007;
            }
            
        }
    }
    
    int sum = 0;
    for (int i = 0; i < maxNum; i++)
    {
        sum = (sum + p[n][i]) % 10007;
    }
    
    cout << sum << '\n';

    return 0;
}