
/*
    동전 0
    https://www.acmicpc.net/problem/11047
*/

#include <iostream>
#include <vector>

#include <algorithm>
using namespace std;



int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v;
    for(int i=0; i<n; i++)
    {
        // 동전 가치 입력
        int toInput;
        cin >> toInput;
        v.push_back(toInput);
    }

    /*
        Ai 는 Ai-1의 배수라고 했음.
        큰 수 부터 내려오면서

        370 = 100 * 3
        70 = 50 * 1
        20 = 10 * 2

        이게 가장 작은 동전의 갯수인가 ?
        맞음.
    */
    
    /* 동전 개수 */
    int makeZero = k;
    int r = 0;
    while(makeZero != 0)
    {
        
    }

    return 0;
}