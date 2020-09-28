#include <iostream>
#include <vector>

using namespace std;
const int MAX_DIST = 999999;

// 방문하지 않은 노드 중 
// distance 가 가장 작은 노드를 출력한다.
int getSmallestNode(int n, vector<int> &distance, vector<bool> &visited) {
    int result = 0;
    int min = MAX_DIST;
    for (int i=1; i<=n; i++) {
        if (distance[i] < min && !visited[i]) {
            min = distance[i];
            result = i;
        }
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> v(n+1);
    int startNode;
    cin >> startNode;
    for (int i=0; i<m; i++) {
        // m번 반복
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
    }

    vector<bool> visited(n+1);
    // -1은 무한대
    vector<int> distance(n+1, MAX_DIST);
    
    // 시작
    distance[startNode] = 0;
    visited[startNode] = 0;

    for (auto p : v[startNode]) {
        distance[p.first] = p.second;
    }
    
    // n번 반복
    for (int i=1; i<n; i++) {
        int node = getSmallestNode(n, distance, visited);
        visited[node] = true;

        for (auto p : v[node]) {
            int cost = distance[node] + p.second;

            if (cost < distance[p.first]) {
                distance[p.first] = cost;
            }
        }
    }

    for (int i=1; i<=n; i++) {
        cout << distance[i] << endl;
    }
}