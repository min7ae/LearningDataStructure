/*
    2xn 타일링 2
    https://www.acmicpc.net/problem/11727
 */

#include <iostream>
using namespace std;

const int MAX = 1000;
// 정답을 저장
long d[MAX] = {0, };

long f(int n){
    if (n == 1 | n == 0) return d[n] = 1;
    if (d[n] > 0) return d[n];
    if (n >= 2)
    {
        d[n] = f(n-1) + 2 * f(n-2);
    }
    return d[n];
}

int main(){
    int n;
    cin >> n;
    cout << (f(n) % 10007) ;
    return 0;
}