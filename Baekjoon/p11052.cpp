/*
    카드 구매하기
    https://www.acmicpc.net/problem/11052
 */
#include <iostream>
using namespace std;

const int MAX = 1000;
// 최댓값
int d[MAX+1] = {0, };
// 카드 값 저장
int card[MAX+1] = {0, };

int main(){
    int n, k;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        card[i] = k;
    }
    d[1] = card[1];
    for (int i = 2; i <= n ; i++)
    {
        int tmpMax = card[i];
        for (int j = 1; j <= i ; j++)
        {
            if (tmpMax < d[j] + d[i-j] )
            {
                tmpMax = d[j] + d[i-j];
            }
        }
        d[i] = tmpMax;
    }
    
    cout << d[n] << '\n';
    return 0;
}