#include <vector>
#include <iostream>

using namespace std;

// 연결리스트
vector<int> a[20001];
// color
int color[20001];

// 이분 그래프면 true, 아니면 false
bool dfs(int node, int c) {
    color[node] = c;
    for (int i=0; i<a[node].size(); i++) {
        int next = a[node][i];
        // 방문X, 해야지
        if (color[next] == 0) {
            // 색이 다르다면,
            // 
            if (dfs(next, 3-c) == false) {
                return false;
            }
        } else if (color[next] == color[node]) {
            return false;
        }
    }
    return true;
}

int main() {
    // 집어넣고,
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

        bool ok = true;
        for (int i=1; i<=n; i++) {
            // 방문하지 않았다면
            if (color[i] == 0) {
                if (dfs(i, 1) == false) {
                    ok = false;
                }
            }
        }
}