/*
    벽 부수고 이동하기
    https://www.acmicpc.net/problem/2206
*/

#include <iostream>
#include <queue>
using namespace std;
/*
    chk = {들어왔는지 chk, (1,1,1)부터의 거리}
    maps 경로인데, maps를 한 겹 더 씌운다. 
*/
pair<bool, int> chk[1001][1001][2];
int maps[1001][1001];
bool maps_z = false;
int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};

struct loc {
    int x;
    int y;
    int z;
};

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int s;
            scanf("%1d", &s);
            maps[i][j][0] = maps[i][j][1] = s;
        }
    }

    /* index i, j*/
    int i = 1;
    int j = 1;
    int z = 0; // 0층
    queue<loc> q;

    chk[i][j][z] = {true, 1};
    q.push( {i, j, z} );
    while (!q.empty())
    {
        i = q.front().x;
        j = q.front().y;
        z = q.front().z;

        q.pop();
        cout << i << " " << j << " " << z << " " << chk[i][j][z].second << endl;
        for (int dxy = 0; dxy < 4; dxy++)
        {
            int ni = i + di[dxy];
            int nj = j + dj[dxy];
            
            if (ni < 1 | ni > n | nj < 1 | nj > m) 
            {
                continue;
            }
            if (chk[ni][nj][z].first == true ) {
                continue;
            }
            /* 갈 수 있다면 */
            if (maps[ni][nj][z] == 0) 
            {
                /* 방문하고, */
                chk[ni][nj][z].first = true;
                
                /* 거리를 +1 증가시킨다. */
                chk[ni][nj][z].second = chk[i][j][z].second + 1;
                /* queue에 집어넣자. */
                q.push( {ni, nj, z} );
            } 
            /* 갈 수 없다면, 한 번 더 확인한다. */
            else 
            {
                /* 아직 1층이니? */
                if (z == 0){
                    /* 2층으로 올려주고, */
                    chk[ni][nj][z+1].first = true;
                    chk[ni][nj][z+1].second = chk[i][j][z+1].second + 1;
                    q.push({ni, nj, z+1});
                }
            }
        }
    }
    /* 도착했다면 */
    if(chk[n][m][z].first == true)
    {
        cout << chk[n][m][z].second;
    }
    /* 아니라면, */
    else 
    {
        cout << -1;
    }
    return 0;
}