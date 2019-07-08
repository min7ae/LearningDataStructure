/*
    카드 구매하기 2
    https://www.acmicpc.net/problem/16194
 */
#include <iostream>
using namespace std;

const int MAX = 1000;
// 최소값
int m[MAX+1] = {0, };
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
    m[1] = card[1];
    for (int i = 2; i <= n ; i++)
    {
        int tmpMin = card[i];
        for (int j = 1; j < i ; j++)
        {
            if (tmpMin > m[j] + m[i-j] )
            {
                tmpMin = m[j] + m[i-j];
            }
        }
        m[i] = tmpMin;
    }
    
    cout << m[n] << '\n';
    return 0;
}