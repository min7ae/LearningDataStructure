/*
    미로 탐색
    https://www.acmicpc.net/problem/2178
*/

#include <iostream>
#include <queue>
using namespace std;
/*
    chk = { 들어왔는지 chk, (1,1)부터의 거리 }
    maps 경로
*/
pair<bool, int> chk[101][101];
int maps[101][101];

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int s;
            scanf("%1d", &s);
            maps[i][j] = s;
        }
    }
    /* index i, j*/
    int i = 1;
    int j = 1;
    queue<pair<int, int> > q;

    chk[i][j] = {true, 0};
    q.push(make_pair(i, j));
    while (!q.empty())
    {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        cout << i << " " << j << endl;
        if (maps[i+1][j] == 1)
        {
            int ni = i+1;
            int nj = j;
            // 들어갔는지 확인
            if (chk[ni][nj].first == false)
            {
                chk[ni][nj].first = true;
                chk[ni][nj].second = chk[i][j].second + 1;
                q.push(make_pair(ni, nj));
            }
        }
        else if (maps[i][j+1] == 1)
        {
            int ni = i;
            int nj = j+1;
            // 들어갔는지 확인
            if (chk[ni][nj].first == false)
            {
                chk[ni][nj].first = true;
                chk[ni][nj].second = chk[i][j].second + 1;
                q.push(make_pair(ni, nj));
            }
        }
        else if (maps[i-1][j] == 1)
        {
            int ni = i-1;
            int nj = j;
            // 들어갔는지 확인
            if (chk[ni][nj].first == false)
            {
                chk[ni][nj].first = true;
                chk[ni][nj].second = chk[i][j].second + 1;
                q.push(make_pair(ni, nj));
            }
        }
        else if(maps[i][j-1] == 1)
        {
            int ni = i;
            int nj = j-1;
            // 들어갔는지 확인
            if (chk[ni][nj].first == false)
            {
                chk[ni][nj].first = true;
                chk[ni][nj].second = chk[i][j].second + 1;
                q.push(make_pair(ni, nj));
            }
        }
    }
    cout << chk[n][m].second;
    return 0;
}