/*
    뱀
    https://www.acmicpc.net/problem/3190
*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// 0: 오른쪽, 1: 아래, 2: 왼쪽, 3: 위쪽
vector<int> dx {0, 1, 0, -1};
vector<int> dy {1, 0, -1, 0};

void pDummy(vector<vector<int>> &dummy, vector<vector<int>> &apple) {
    for (int i=0; i<dummy.size(); i++) {
        for (int j=0; j<dummy[0].size(); j++) {
            cout << dummy[i][j] + apple[i][j]*9 << " ";
        }
        cout << '\n';
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dummy(n+1, vector<int>(n+1, 0));
    vector<vector<int>> apple(n+1, vector<int>(n+1, 0));
    int k;
    cin >> k;
    // 사과
    while (k--) {
        int x, y;
        cin >> x >> y;
        // 사과는 apple 에서 1
        apple[x][y] = 1;
    }
    int l;
    cin >> l;
    // 방향 변환 횟수
    vector<pair<int, char>> dirChange;
    int dirCount = 0;
    while(l--) {
        int x;
        char c;
        cin >> x >> c;
        dirChange.push_back(make_pair(x, c));
    }

    // 0: 오른쪽, 1: 아래, 2: 왼쪽, 3: 위쪽
    int dir = 0;
    int x = 1;
    int y = 1;
    deque<pair<int, int>> dq;
    dq.push_back(make_pair(1, 1));
    dummy[x][y] = 1;
    // pDummy(dummy, apple);
    for(int i=1; i<10000; i++) {
        // cout << "i: " << i << " dir: " << dir << '\n';
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 1 || n < nx || ny < 1 || n < ny) {
            cout << i;
            return 0;
        }
        if (dummy[nx][ny] == 1) {
            cout << i;
            return 0;
        }
        dq.push_back(make_pair(nx, ny));
        if (apple[nx][ny] == 1) {
            // 바뀐 위치가 사과가 있다면
            // 없어지고
            apple[nx][ny] = 0;
            // 꼬리는 움직이지 않는다.
        } else {
            // 없다면
            dummy[dq.front().first][dq.front().second] = 0;
            dq.pop_front();
        }
        for (auto dqi : dq) {
            // cout << dqi.first << " " << dqi.second << " ";
            dummy[dqi.first][dqi.second] = 1;
        }
        // cout << '\n';
        x = nx;
        y = ny;
        // pDummy(dummy, apple);
        // 방향이 바뀜
        if (i == dirChange[dirCount].first) {
            if (dirChange[dirCount].second == 'D') {
                dir = (dir + 1) % 4;
            } else {
                dir = (dir + 3) % 4;
            }
            dirCount += 1;
        }
    }
    
    return 0;
}