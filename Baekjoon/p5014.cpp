/*
    스타트링크
    https://www.acmicpc.net/problem/5014
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main() {
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    vector<bool> check(f+1, false);
    vector<int> dist(f+1, 0);
    queue<int> q;

    q.push(s);
    check[s] = true;

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        if (now + u <= f && check[now + u] == false) {
            dist[now + u] = dist[now] + 1;
            check[now + u] = true;
            q.push(now+u);
        }
        if (now - d >= 1 && check[now-d] == false) {
            dist[now-d] = dist[now] + 1;
            check[now-d] = true;
            q.push(now-d);
        }
    }
    if (check[g]) {
        cout << dist[g] << '\n';
    } else {
        cout << "use the stairs\n";
    }
    return 0;
}