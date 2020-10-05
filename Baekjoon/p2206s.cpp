/*
    벽 부수고 이동하기
    https://www.acmicpc.net/problem/2206
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printMap (vector<vector<int>> &map) {
    for (int i=0; i<map.size(); i++) {
        for (int j=0; j<map[0].size(); j++) {
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    vector<int> dx {-1, 0, 1, 0};
    vector<int> dy {0, 1, 0, -1};
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d", &v[i][j]);
        }
    }
    bool isFirst = false;
    int shortestPath = -1;
    for (int i=0; i<n*m; i++) {
        bool isBreak = false;
        if (v[i/m][i%m] == 0) {
            // 두번째 부턴 부술 필요 없다.
            if (isFirst) {
                continue;
            }
            // 부술 수 없다.
            isFirst = true;
        } else {
            // 1 부술 수 있다면
            v[i/m][i%m] = 0;
            isBreak = true;
        }
        // cout << "i: " <<i << '\n';
        // printMap(v);
        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        dist[0][0] = 1;
        visit[0][0] = true;
        q.push(make_pair(0, 0));
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int j=0; j<4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (0<=nx && nx < n && 0<=ny && ny < m) {
                    if (visit[nx][ny] == false && v[nx][ny] == 0) {
                        // 방문하고, 
                        visit[nx][ny] = true;
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        // cout << dist[n-1][m-1] << endl;
        // 다시 되돌려 놔
        if (dist[n-1][m-1] != 0) {
            if (shortestPath == -1) {
                // 처음
                shortestPath = dist[n-1][m-1];
            }
            if (dist[n-1][m-1] < shortestPath) {
                shortestPath = dist[n-1][m-1];
            }
        }
        if (isBreak) {
            v[i/m][i%m] = 1;
            // 다시 돌려놔
        }
        
    }
    cout << shortestPath << endl;
    return 0;
}