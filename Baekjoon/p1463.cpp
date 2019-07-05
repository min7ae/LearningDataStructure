/*
    괄호
    https://www.acmicpc.net/problem/9012
 */

#include <iostream>
using namespace std;

const int MAX = 1000000;
int D[MAX] = {0, };

// 최소 함수
int min(int a, int b){
    return a > b ? b : a;
}

// 1로 만들기 함수 f
int makeOne(int n){
    if (n == 1)
    {
        D[1] = 0;
        return 0;
    }
    
    if (n % 3 == 0)
    {
        D[n] = min(makeOne(n-1), makeOne(n/3)) + 1;
        return D[n];
    }

    if (n % 2 == 0)
    {
        D[n] = min(makeOne(n-1), makeOne(n/2)) + 1;
        return D[n];
    }
    
    D[n] = makeOne(n-1) + 1;
    return D[n];
}

int main(){
    int n;
    cin >> n;

    cout << makeOne(n) << endl;
    return 0;
}
