/*
    미로 탐색
    https://www.acmicpc.net/problem/2178
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> &miro, vector<vector<int>> &fromZero, vector<vector<bool>> &isVisited, int inpX, int inpY, int n, int m) {
    queue<pair<int, int>>q;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    q.push(make_pair(inpX, inpY));
    fromZero[inpX][inpY] = 1;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (isVisited[nx][ny] == false && miro[nx][ny] == 1) {
                    q.push(make_pair(nx, ny));
                    fromZero[nx][ny] = fromZero[x][y] + 1;
                    isVisited[nx][ny] = true;
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> miro(n, vector<int>(m, 0));
    vector<vector<int>> fromZero(n, vector<int>(m, 0));
    vector<vector<bool>> isVisited(n, vector<bool>(m, false));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d", &miro[i][j]);
        }
    }
    bfs(miro, fromZero, isVisited, 0, 0, n, m);
    cout << fromZero[n-1][m-1];
    return 0;
}