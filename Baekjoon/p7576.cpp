/*
    토마토
    https://www.acmicpc.net/problem/7576
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int answer = 0;
    int m, n;
    cin >> m >> n;
    vector<vector<int>> tomatoCase(n, vector<int>(m, 0));
    vector<vector<int>> fromZero(n, vector<int>(m, 0));
    vector<vector<bool>> chk(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> tomatoCase[i][j];
            fromZero[i][j] = -1;
            if (tomatoCase[i][j] == 1) {
                chk[i][j] = true;
                q.push(make_pair(i, j));
                fromZero[i][j] = 0;
            }
        }
    }

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (tomatoCase[nx][ny] == 0 && fromZero[nx][ny] == -1) {
                    fromZero[nx][ny] = fromZero[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (answer < fromZero[i][j]) {
                answer = fromZero[i][j];
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (tomatoCase[i][j] == 0 && fromZero[i][j] == -1) {
                answer = -1;
            }
        }
    }
    cout << answer;
    return 0;
}