/*
    쉬운 계단 수
    https://www.acmicpc.net/problem/10844
 */

#include <iostream>
#include <vector>

using namespace std;

/* 
    countStair[i][n] == i로 시작하는 n자리 계단 수 
    즉, n자리 계단 수 = countStair[1][n] + ... + countStair[9][n]
*/
int countStair[101][10]; 

int main()
{   
    int n;
    cin >> n;
    
    /* 한자리 계산 수 */
    for (int i = 0; i < 10; i++)
    {
        countStair[1][i] = 1;
    }

    /* 
    2자리 계단 수 부터 구하자면 ..
    

     */
    for (int i = 2; i < n+1; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
            {
                countStair[i][j] = countStair[i-1][j+1];
            }
            else if (j == 9)
            {
                countStair[i][j] = countStair[i-1][j-1];
            }
            else {
                countStair[i][j] = (countStair[i-1][j-1] + countStair[i-1][j+1]) % 1000000000;
            }
            
        }
    }
    
    int result = 0;
    for (int i = 1; i < 10; i++)
    {
        result =(result +countStair[n][i] ) % 1000000000;
    }
    cout << result;

    return 0;
}