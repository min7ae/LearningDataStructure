/*
    데스 나이트
    https://www.acmicpc.net/problem/16948
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> map (n, vector<int>(n, 0));
    vector<vector<int>> dist (n, vector<int>(n, -1));

    vector<int> dr {-2, -2, 0, 0, 2, 2};
    vector<int> dc {-1, 1, -2, 2, -1, 1};
    
    pair<int, int> p1;
    pair<int, int> p2;
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    p1.first = r1;
    p1.second = c1;
    p2.first = r2;
    p2.second = c2;

    queue<pair<int, int>> q;
    dist[p1.first][p1.second] = 0;
    q.push(p1);
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i=0; i<6; i++) {
            int rr = r + dr[i];
            int cc = c + dc[i];
            if (0<=rr && rr<n && 0<=cc && cc<n) {
                // 방문 했는지 확인
                if (dist[rr][cc] == -1) {
                    dist[rr][cc] = dist[r][c] + 1;
                    q.push(make_pair(rr, cc));
                }
            }
        }
    }
    if (dist[p2.first][p2.second] != -1) {
        cout << dist[p2.first][p2.second];
    } else {
        cout << -1;
    }
    return 0;
}