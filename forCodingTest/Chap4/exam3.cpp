#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void printMap(vector<vector<int>> &map) {
    for(int i=0; i<map.size(); i++) {
        for(int j=0; j<map[i].size(); j++) {
            cout << map[i][j];
            cout << " ";
        }
        cout << endl;
    }
}


// 현재 위치, 방향
// 다음 위치가 
// 1: 바다, 0: 육지, 2: 육지인데 방문한 곳
bool isPossible(vector<vector<int>> &map, int x, int y, int d) {
    int sizeofN = map.size();
    int sizeofM = map[0].size();
    switch (d)
    {
    case 0:
        if ((x-1 < 0) && map[x-1][y] != 0) {
            return false;
        }
        break;
    case 1:
        if ((y+1 >= sizeofM) && map[x][y+1] != 0) {
            return false;
        }
        break;
    case 2:
        if ((x+1 >= sizeofN) && map[x+1][y] != 0) {
            return false;
        }
        break;
    case 3:
        if ((y-1 < 0) && map[x][y-1] != 0) {
            return false;
        }
        break;
    }
    // 여기까지 통과하면 벗어나는 범위는 없다는 것
    // 다음 방향에 
    return true;
}

// d방향으로 방문
// 1: 바다, 0: 육지, 2: 육지인데 방문한 곳
void go(vector<vector<int>> &map, int x, int y, int d) {
    if (!isPossible(map, x, y, d)) {
        return;
    }
    switch (d)
    {
    case 0:
        map[x-1][y] = 2;
        break;
    case 1:
        map[x][y+1] = 2;
        break;
    case 2:
        map[x+1][y] = 2;
        break;
    case 3:
        map[x][y-1] = 2;
        break;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    // 1: 바다, 0: 육지, 2: 육지인데 방문한 곳
    vector<vector<int>> map(n, vector<int>(m, 0));
    
    // x, y 좌표, 방향
    vector<int> isHear(3);
    for(int i=0; i<3; i++) {
        cin >> isHear[i];
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }
    // 길을 순회하기 위한 stack
    // x, y 좌표
    stack<pair<int, int>> s;
    // 현재 위치에서 다음 위치로 이동 할 수 있는지 검사
    while (!isPossible(map, isHear[0], isHear[1], isHear[2])) {
        int d = isHear[2];
        for(int i=0; i<4; i++) {
            // 4개를 도는데 0, 1, 2, 3을 순회
            // 왼쪽 방향부터 수행
            int nextD = (d+i-1)%4;
            s.push(make_pair(isHear[0], isHear[1]));
            go(map, isHear[0], isHear[1], nextD);
        }
    }
    
    printMap(map);
    return 0;
}