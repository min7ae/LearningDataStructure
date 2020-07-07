/*
    1, 2, 3 더하기
    https://www.acmicpc.net/problem/9095
 */

#include <iostream>

using namespace std;

const int MAX = 10;
int d[MAX] = {0, };

// idx = 현재 위치, n = 최대 위치
int go(int idx, int n) {
    // 최대 위치 보다 더 커지면
    if (idx > n) {
        return 0;
    }
    int res = 0;
    if (idx == n) {
        return res;
    }
    // 다음 위치로 1, 2, 3칸 이동 할 수 있음.
    for (int i=1; i<=3; i++){
        res += go(idx+i, n);
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> d[i];
        cout << go(0, d[i]) << '\n';
    }
    
    return 0;
}