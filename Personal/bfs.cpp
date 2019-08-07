/*
    bfs 코드 작성

 */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<int> v[1001];
// 방문 -> chk
bool chk[1001];

void dfs(int x);
void bfs(int x);

int main(){
    int n, m, s;
    cin >> n >> m >> s;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    

    return 0;
}

void dfs(int x){
    chk[x] = true;
    cout << x << " ";
    for (int i = 0; i <= v[x].size(); i++)
    {
        int y = v[x][i];
        if (chk[y] == false)
        {
            dfs(y);
        }
    }
}

void bfs(int x){
    queue<int> q;
    a

}