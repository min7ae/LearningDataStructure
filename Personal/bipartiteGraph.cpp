#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

// 연결 리스트
vector<int> a[20001];

// 0: 방문X, 
// 1: 방문 + 1번 영역
// 2: 방문 + 2번 영역
int color[20001];

void dfs(int node, int c) {
    // dfs 색칠하고
    color[node] = c;
    for (int i=0; i<a[node].size(); i++) {
        int next = a[node][i];
        if (color[next] == 0) {
            // 3-c
            // c가 1이면 2, 2면 1 로 색칠
            dfs(next, 3-c);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        //연결리스트 초기화
        // color[i] = 0
        for(int i=1; i<=n; i++) {
            a[i].clear();
            color[i] = 0;
        }

        // u, v에 집어 넣고
        for (int i=0; i<m; i++) {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }

        // 1영역, 2영역 나누는 dfs 코드 실행
        // 
        for (int i=1; i<=n; i++) {
            if (color[i] == 0) {
                // 1로 시작
                dfs(i, 1);
            }
        }

        // 다하고 나서
        bool ok = true;
        
        // 각 a[]에 대하여 검사하는데,
        for (int i=1; i<=n; i++) {
            // 연결리스트 항목 중
            for (int k=0; k<a[i].size(); k++) {
                // i번째 연결 리스트에서
                int j=a[i][k];
                // 모든 간선에 대하여 색이 같은게 있으면 false
                // 간선과 연결된 서로 다른 정점은 색이 무조건 달라야함
                if (color[i] == color[j]) {
                    ok = false;
                }
            }
        }

        cout << ok ? "YES" : "NO";
        cout << endl;
    }

    return 0;
}