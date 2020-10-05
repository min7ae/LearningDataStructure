/*
    돌 그룹
    https://www.acmicpc.net/problem/12886
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    vector<int> init(3);
    for (int i=0; i<3; i++) {
        cin >> init[i];
    }
    queue<vector<int>> q;
    vector<vector<vector<int>>> visited (1501, vector<vector<int>>(1501, vector<int>(1501, false)));
    visited[init[0]][init[1]][init[2]] = true;
    q.push(init);
    bool chk = false;
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        if (v[0] < v[1]) {
            auto s(v);
            s[0] = s[0] + s[0];
            s[1] = s[1] - s[0];
            // 방문 X
            if (s[0] <= 1500 && 1<=s[1]) {
                if (visited[s[0]][s[1]][s[2]] == false) {
                    visited[s[0]][s[1]][s[2]] = true;
                    if (s[0] == s[1] && s[1] == s[2]) {
                        // 만약 다 같다면
                        chk = true;
                        break;
                    }
                    q.push(s);
                }
            }
        } else if (v[0] > v[1]) {
            auto s(v);
            s[1] = s[1] + s[1];
            s[0] = s[0] - s[1];
            // 방문 X
            if (s[1] <= 1500 && 1<=s[0]) {
                if (visited[s[0]][s[1]][s[2]] == false) {
                    visited[s[0]][s[1]][s[2]] = true;
                    if (s[0] == s[1] && s[1] == s[2]) {
                        // 만약 다 같다면
                        chk = true;
                        break;
                    }
                    q.push(s);
                }
            }
        }
        
        if (v[1] < v[2]) {
            auto s(v);
            s[1] = s[1] + s[1];
            s[2] = s[2] - s[1];
            if (s[1] <= 1500 && 1<=s[2]) {
                if (visited[s[0]][s[1]][s[2]] == false) {
                    visited[s[0]][s[1]][s[2]] = true;
                    if (s[0] == s[1] && s[1] == s[2]) {
                        // 만약 다 같다면
                        chk = true;
                        break;
                    }
                    q.push(s);
                }
            }
        } else if (v[1] > v[2]) {
            auto s(v);
            s[2] = s[2] + s[2];
            s[1] = s[1] - s[2];
            if (s[2] <= 1500 && 1<=s[1]) {
                if (visited[s[0]][s[1]][s[2]] == false) {
                    visited[s[0]][s[1]][s[2]] = true;
                    if (s[0] == s[1] && s[1] == s[2]) {
                        // 만약 다 같다면
                        chk = true;
                        break;
                    }
                    q.push(s);
                }
            }
        }
        
        if (v[0] < v[2]) {
            auto s(v);
            s[0] = s[0] + s[0];
            s[2] = s[2] - s[0];
            if (s[0] <= 1500 && 1<=s[2]) {
                if (visited[s[0]][s[1]][s[2]] == false) {
                    visited[s[0]][s[1]][s[2]] = true;
                    if (s[0] == s[1] && s[1] == s[2]) {
                        // 만약 다 같다면
                        chk = true;
                        break;
                    }
                    q.push(s);
                }
            }
        } else if (v[0] > v[2]) {
            auto s(v);
            s[2] = s[2] + s[2];
            s[0] = s[0] - s[2];
            if (s[2] <= 1500 && 1<=s[0]) {
                if (visited[s[0]][s[1]][s[2]] == false) {
                    visited[s[0]][s[1]][s[2]] = true;
                    if (s[0] == s[1] && s[1] == s[2]) {
                        // 만약 다 같다면
                        chk = true;
                        break;
                    }
                    q.push(s);
                }
            }
        }
    }
    
    if (chk) {
        cout << 1;
    } else {
        cout << 0;
    }
    
    return 0;
}