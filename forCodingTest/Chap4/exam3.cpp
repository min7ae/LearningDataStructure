#include <iostream>
#include <vector>

using namespace std;

void printMap(vector<vector<int>> &map) {
    for(int i=0; i<map.size(); i++) {
        for(int j=0; j<map[i].size(); j++) {
            if (map[i][j] == 1) {
                cout << 1;
            } else {
                cout << 0;
            }
            cout << " ";
        }
        cout << endl;
    }
}



// 현재 위치, 방향
bool isPossible(vector<vector<int>> &map, int x, int y, int d) {
    int sizeofN = map.size();
    int sizeofM = map[0].size();
    switch (d)
    {
    case 0:
        if (x-1 < 0) {
            return false;
        }
        break;
    case 1:
        if (y+1 >= sizeofM) {
            return false;
        }
        break;
    case 2:
        if (x+1 >= sizeofN) {
            return false;
        }
        break;
    case 3:
        if (y-1 < 0) {
            return false;
        }
        break;
    }
    // 여기까지 통과하면 벗어나는 범위는 없다는 것
    // 다음 방향에 
    return true;
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

    // 현재 위치에서 다음 위치로 이동 할 수 있는지 검사
    while (!isPossible(map, isHear[0], isHear[1], isHear[2])) {
        int d = isHear[2];
        for(int i=0; i<4; i++) {
            // 4개를 도는데 0, 1, 2, 3을 순회
            int nextD = (d+i)%4;
            
        }
    }
    
    printMap(map);
    return 0;
}