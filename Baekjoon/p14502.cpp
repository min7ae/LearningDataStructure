#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dfs(vector<vector<int>> miro, int n, int m) {
    // 바이러스를 퍼뜨린 후 
    // free 영역을 센다.
    int result = 0;
    vector<int> dx {-1, 0, 1, 0};
    vector<int> dy {0, 1, 0, -1};
    vector<vector<bool>> visited (n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    // 초기 값 찾기
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (miro[i][j] == 2 && visited[i][j] == false) {
                // 찾았고,
                visited[i][j] = true;
                // 퍼뜨리자.
                q.push(make_pair(i, j));
                while (!q.empty()) {
                    int ii = q.front().first;
                    int jj = q.front().second;
                    q.pop();
                    for (int k=0; k<4; k++) {
                        int nx = ii + dx[k];
                        int ny = jj + dy[k];
                        if (0<=nx && nx<n && 0<=ny && ny<m && miro[nx][ny] == 0) {
                            // 그리고 방문하지 않았다면,
                            if (visited[nx][ny] == false) {
                                // 0이라면 2로 바꾼다.
                                visited[nx][ny] = true;
                                miro[nx][ny] = 2;
                                q.push(make_pair(nx, ny));
                            }
                            
                        }
                    }
                }
            }        
        }
    }
    
    // 다시 세고
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (miro[i][j] == 0) {
                result += 1;
            }
        }
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> miro (n, vector<int>(m, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> miro[i][j];
        }
    }

    // 세개를 세우는데 모두 0이여야지만 세운다.
    int mn = m*n;
    int maxValue = 0;
    for (int i=0; i<mn; i++) {
        for (int j=i+1; j<mn; j++) {
            for (int k=j+1; k<mn; k++) {
                // i, j, k에 벽을 세운다.
                // i가 23이고, n이 4라면
                // miro[5][3]
                // 23/4 23%4
                if ( (miro[i/m][i%m] == 0) && (miro[j/m][j%m]==0) && (miro[k/m][k%m]==0) )  {
                    // 만약 모두 빈 칸이라면
                    miro[i/m][i%m] = 1;
                    miro[j/m][j%m] = 1;
                    miro[k/m][k%m] = 1;
                    // 벽을 세우고
                    // 바이러스를 퍼뜨린다.
                    // 
                    int space = dfs(miro, n, m);
                    if (space >= maxValue) {
                        maxValue = space;
                    }
                    miro[i/m][i%m] = 0;
                    miro[j/m][j%m] = 0;
                    miro[k/m][k%m] = 0;
                }
            }
        }
    }
    cout << maxValue;
    return 0;
}