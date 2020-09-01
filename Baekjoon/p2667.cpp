/*
    단지번호붙이기
    https://www.acmicpc.net/problem/2667
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int bfs(vector<vector<int>> &map, vector<vector<int>> &chk, int n, int x, int y, int cnt) {
    int answer = 1;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    chk[x][y] = 1;
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (map[nx][ny] == 1 && chk[nx][ny] == 0) {
                    answer += 1;
                    q.push(make_pair(nx, ny));
                    chk[nx][ny] = 1;
                }
            }
        }
    }
    return answer;
}

void printmap(vector<vector<int>> &map) {
    int mapSize = map.size();
    for (int i=0; i<mapSize; i++) {
        for (int j=0; j<mapSize; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n, 0));
    vector<vector<int>> chk(n, vector<int>(n, 0));
    for (int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    int cnt = 0;
    vector<int> answerVector;
    for (int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if (chk[i][j] == 0 && map[i][j] == 1) {
                answerVector.push_back(bfs(map, chk, n, i, j, cnt));
                cnt += 1;
            }
        }
    }
    sort(answerVector.begin(), answerVector.end());
    
    cout << cnt << endl;
    for(int i : answerVector) {
        cout << i << endl;
    }
    

    return 0;
}