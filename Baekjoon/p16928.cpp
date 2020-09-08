/*
    뱀과 사다리 게임
    https://www.acmicpc.net/problem/16928
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> l(n);

    for (int i=0; i<n; i++) {
        cin >> l[i].first >> l[i].second;
    }
    vector<pair<int, int>> s(m);
    for (int i=0; i<m; i++) {
        cin >> s[i].first >> s[i].second;
    }

    vector<bool> isVisted(101, false);
    vector<int> answer(101, 0);

    queue<int> q;

    answer[1] = 0;
    q.push(1);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();


        
        // 1부터 6까지 
        for (int i=1; i<=6; i++) {
            // 사다리 검사
            int ccur = cur + i;

        }
    }

    cout << answer[100];

    return 0;
}