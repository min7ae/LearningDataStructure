/*
    연결 요소의 개수
    https://www.acmicpc.net/problem/11724
 */

#include <iostream>
#include <vector>

using namespace std;

// 정점 1000개 생성.
vector<int> a[1001];
bool chk[1001];



void dfs(int x){
    chk[x] = true;
    for (int i = 0; i < a[x].size(); i++)
    {
        int y = a[x][i];
        if(chk[y] == false){
            dfs(y);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs(1);
    int numC = 1;

    for (int i = 2; i <= n; i++)
    {
        if (chk[i] == false)
        {
            dfs(i);
            numC++;
        } 
    }
    
    cout << numC;
    return 0;
}