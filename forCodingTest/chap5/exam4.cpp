#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
void print(vector<vector<T>> &m) {
    for (int i=0; i<m.size(); i++) {
        for (int j=0; j<m[0].size(); j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> miro(n, vector<int>(m, 0));
    vector<vector<int>> ans(n, vector<int>(m, 0));
    vector<vector<bool>> chk(n, vector<bool>(m, false));
    queue<pair<int, int>> q;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d", &miro[i][j]);
        }
    }

    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    // 시작, (0, 0)을 방문한다.
    ans[0][0] = 1;
    q.push(make_pair(0, 0));
    chk[0][0] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        // 4방향 돌아가며 
        // 1. 범위가 벗어나지 않는지
        // 2. 방문할 수 있는지
        // 3. 방문한 곳이었는지 확인한다.
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < m && 0 <= ny && ny < n) {
                // 범위가 벗어나지 않았더라면
                // 방문할 수 있는 곳이고 방문하지 않았다면
                if (miro[nx][ny] == 1 && chk[nx][ny] == false) {
                    // 방문하고
                    // ans에 저장한다.
                    chk[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                    ans[nx][ny] = ans[x][y] + 1;
                }
            }
        }
    }
    print(miro);
    cout << endl;
    print(chk);
    cout << endl;
    print(ans);
    cout << endl;
    
    cout << ans[n-1][m-1];
    return 0;
}