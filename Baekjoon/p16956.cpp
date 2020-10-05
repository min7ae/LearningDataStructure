/*
    늑대와 양
    https://www.acmicpc.net/problem/16956
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<char>> miro (r, vector<char> (c, 0));
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            scanf("%1c", &miro[r][c]);
        }
    }
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (miro[r][c] == 'W') {
                // 늑대라면,
                
            }
        }
    }
    return 0;
}