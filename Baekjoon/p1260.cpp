/*
    DFS와 BFS
    https://www.acmicpc.net/problem/1260
 */
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// for DFS
bool chkDFS[1001] = {false, };
void dfs(int x, vector< vector<int> > &v);
void pushDFS(int a, int b, vector< vector<int> > &v); 

// for BFS
bool chkBFS[1001] = {false, };
void bfs(int x, vector< vector<int> > &v); 
void pushBFS(int a, int b, vector< vector<int> > &v);

int main(){
    int n, m, v;
    cin >> n >> m >> v;

    vector< vector<int> > dfsNode;
    
    dfsNode.assign(n+1);

    vector< vector<int> > bfsNode;
    // bfsNode.assign(n+1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << a << " " << b << endl;
        pushDFS(a, b, dfsNode);
        pushBFS(a, b, bfsNode);
    }
    
    // DFS
    // dfs(v, dfsNode);

    // BFS
    // bfs(v, bfsNode);
    return 0;
}

void pushDFS(int a, int b, vector< vector<int> > &v){
    v.at(a).push_back(b);
    v.at(b).push_back(a);
}


void pushBFS(int a, int b, vector< vector<int> > &v){
    v.at(a).push_back(b);
    v.at(b).push_back(a);
}


void dfs(int x, vector< vector<int> > &v){
    chkDFS[x] = true;
    printf("%d ", x);
    for (int i = 0; i < v[x].size(); i++)
    {
        int y = v[x][i];
        if(chkDFS[y] == false){
            dfs(y, v);
        }
    }
}