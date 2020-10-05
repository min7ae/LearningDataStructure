/*
    탈옥
    https://www.acmicpc.net/problem/9376
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dx {0, 1, 0, -1};
vector<int> dy {1, 0, -1, 0};

void pjail(vector<vector<char>> &jail) {
    for(int i=0; i<jail.size(); i++) {
        for (int j=0; j<jail[0].size(); j++) {
            cout << jail[i][j];
        }
        cout << '\n';
    }
}

void dfs(vector<vector<char>> &jail, vector<vector<int>>&dist, int x, int y) {

}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int h, w;
        cin >> h >> w;
        vector<vector<char>> jail(h+2, vector<char>(w+2, '.'));
        for (int i=1; i<=h; i++) {
            for (int j=1; j<=w; j++) {
                scanf("%1s", &jail[i][j]);
            }
            jail[i][w+1] = '.';
        }
        vector<vector<vector<int>>> dist(3, vector<vector<int>>(h+2, vector<int>(w+2, 0)));
        dist[0];
    }
    return 0;
}