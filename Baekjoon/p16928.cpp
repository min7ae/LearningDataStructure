/*
    뱀과 사다리 게임
    https://www.acmicpc.net/problem/16928
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> l;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        l[a] = b;
    }
    unordered_map<int, int> s;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        s[a] = b;
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
            int ccur = 0;
            // 사다리 검사
            // 사다리 && 뱀X 라면
            if (l.find(cur) != l.end() && s.find(cur) == s.end() && !isVisted) {
                ccur = cur + l[cur];
            } else {
                ccur = cur + i;
            }
            answer[cur] = answer[cur] + ccur;
        }
    }

    cout << answer[100];

    return 0;
}