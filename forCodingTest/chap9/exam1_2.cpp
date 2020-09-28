#include <vector>
#include <iostream>

using namespace std;
const int MAX = 9999999;

int getNode (int n, vector<int> &distance, vector<bool> &isVisited) {
    int result = 0;
    int min = MAX;
    for (int i=1; i<=n; i++) {
        if (distance[i] < min && !isVisited[i]) {
            min = distance[i];
            result = i;
        }
    }
    return result;
}

int main() {
    int n, m, st;
    cin >> n >> m >> st;

    // vector<pair> 가 n+1 개 존재한다.
    // v[a].push_back(make_pair(b, c));
    vector<vector<pair<int, int>>> v(n+1);

    // 간선의 갯수 만큼 증가
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
    }
    
    // distance[a] : st에서 노드 a까지 최소 거리
    // 각 노드가 지날 수록 갱신 됨.
    // isVisited[a] : a 노드 방문
    vector<int> distance(n+1, MAX);
    vector<bool> isVisited(n+1, false);

    distance[st] = 0;
    isVisited[st] = true;

    //
    for (auto p : v[st]) {
        distance[p.first] = p.second;
    }

    // 1부터 n번보다 작게, 총 n-1번 반복
    for (int i=1; i<n; i++) {
        // 각 노드 중 최소 노드 찾기
        int minNode = getNode(n, distance, isVisited);
        // 여기서 방문하고,
        isVisited[minNode] = true;

        for (auto p : v[minNode]) {
            int cost = distance[minNode] + p.second;

            // 
            if (cost < distance[p.first]) {
                distance[p.first] = cost; 
            }
        }
    }

    return 0;
}