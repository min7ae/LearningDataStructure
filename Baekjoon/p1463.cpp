/*
    괄호
    https://www.acmicpc.net/problem/9012
 */

#include <iostream>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y)) 

using namespace std;

const int MAX = 1000000;

int D[MAX] = {0, };
int d[MAX] = {0, };

// 1로 만들기 함수 f
int makeOne(int n){    
    if(n == 1) return 0;
    if(D[n] > 0) return D[n];
    if (n % 6 == 0) {
        D[n] = MIN(MIN(makeOne(n/3), makeOne(n/2)) , makeOne(n-1)) + 1;
    } else if (n % 3 == 0) {
        D[n] = MIN(makeOne(n/3), makeOne(n-1)) + 1;
    } else if (n % 2 == 0) {
        D[n] = MIN(makeOne(n/2) , makeOne(n-1)) + 1;
    } else {
        D[n] = makeOne(n-1) + 1;
    }
    return D[n];
}

// top-down 방식
int makeOnev2(int n){
    d[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        d[i] = d[i-1] + 1;
        if (i % 2 == 0 && d[i] > d[i/2] + 1)
        {
            d[i] = d[i/2] + 1;
        }
        if (i % 3 == 0 && d[i] > d[i/3] + 1)
        {
            d[i] = d[i/3] + 1
        }
        
    }
    
}

int main(){
    int n;
    cin >> n;

    cout << makeOne(n) << endl;
    return 0;
}
