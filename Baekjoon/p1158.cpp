/*
    조세퍼스 문제
    https://www.acmicpc.net/problem/1158
 */

#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, k, tmp;
    cin >> n >> k;

    queue <int> q;

    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    cout << '<';
    while (n--)
    {
        // k번이면 -> k-1번 pop, push 수행하고, 
        for(int i = 1; i < k; i++){
            tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        cout << q.front();
        q.pop();
        if(n != 0){
            // 마지막은 ", " 제외
            cout << ", ";
        }
    }
    
    cout << '>';
    return 0;
}