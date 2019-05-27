// 재귀적으로 nCr을 계산하기

// nC0 = nCn = 1
// r > 0 이면, nCr = n-1Cr-1 + n-1Cr

#include <iostream>
#define MAXNUM  200
using namespace std;


long long memo[MAXNUM][MAXNUM];

long long nCr(int n, int r){
    if (memo[n][r] > 0)
    {
        return memo[n][r];
    }
    
    if ( r == 0 || n == r){
        return memo[n][r] = 1;
    } 

    return memo[n][r] = nCr(n-1, r-1) + nCr(n-1, r);
}

int main(){
    long long n, r;
    cout << "input n, r:";
    cin >> n >> r;
    cout << nCr(n, r);

    return 0;
}