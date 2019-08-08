/*
    숨바꼭질
    https://www.acmicpc.net/problem/1697
 */

#include <iostream>
#include <queue>
using namespace std;

const int MAX_NUM = 100000;
pair<bool, int> p[MAX_NUM];

void printPair(int n){
    cout << p[n].first << " " << p[n].second << '\n';
}

void bfs(int n, int k){
    queue<pair<bool, int> > q;
    int sec = 0;
    p[n].first = true; p[n].second = n;
    q.push(p[n]);
    printPair(n);
    
    while (p[k].first == false)
    {
        int x = q.front().second;
        cout << "x " << x << endl;
        q.pop();
        
        int y1 = x+1; int y2 = x-1; int y3 = x*2;

        // 만약 범위를 벗어났다면 이동하지 않는다.
        if (y1 < 0 || y1 > MAX_NUM)
        {
            y1 = x;
        }
        if (y2 < 0 || y2 > MAX_NUM)
        {
            y2 = x;
        }
        if (y3 < 0 || y3 > MAX_NUM)
        {
            y3 = x;
        }

        // 방문했는지 확인
        if(p[y1].first == false) {
            p[y1].first = true;
            p[y1].second = y1;
            printPair(y1);
            q.push(p[y1]);
        }
        if(p[y2].first == false) {
            p[y2].first = true;
            p[y2].second = y2;
            printPair(y2);
            q.push(p[y2]);
        }
        if(p[y3].first == false) {
            p[y3].first = true;
            p[y3].second = y3;
            printPair(y3);
            q.push(p[y3]);
        }
        cout << sec << endl;
        sec++;
    }
    cout << sec << '\n';
}

int main(){
    int n, k;
    cin >> n >> k;
    bfs(n, k);
    return 0;
}