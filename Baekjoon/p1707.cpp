/*
    이분 그래프
    https://www.acmicpc.net/problem/1707
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> v[20001];
bool chk[20001];

void bfs(int n){
    queue<int> q;
    chk[n] = true;
    q.push(n);
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        printf("%d ",p);
        for (int i = 0; i < v[n].size(); i++)
        {
            int y = v[n][i];
            if (chk[y] == false)
            {
                chk[y] = true;
                q.push(y);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    while (n--)
    {
        int vertex, edge;
        cin >> vertex >> edge;
        for (int i = 0; i < edge; i++)
        {
            int n1, n2;
            cin >> n1 >> n2;
            v[n1].push_back(n2);
            v[n2].push_back(n1);
        }

        
    }
    
    return 0;
}
