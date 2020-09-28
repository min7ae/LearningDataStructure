#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    queue<int> q;
    vector<bool> v(m, false);
    q.push(n);
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        
        
    }

    return 0;
}