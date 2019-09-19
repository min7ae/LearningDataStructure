/*
    탈출
    https://www.acmicpc.net/problem/3055
*/

#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

/* 방문했는지 확인[0, 1], D가 움직인 거리 */
tuple <bool, bool, int> chk[51][51];

/* 최대 map의 크기 */
char maps[51][51];

const int di[] = {1, -1, 0, 0};
const int dj[] = {0, 0, 1, -1}; 

int main()
{
    int r, c;
    cin >> r >> c;
    
    int initDI, initDJ;
    int initStarI, initStarJ;

    queue<pair<int, int> > qD;
    queue<pair<int, int> > qStar;

    /* 지도에 집어넣고 */
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            char toPutChar;
            scanf("%1c", &toPutChar);
            maps[i][j] = toPutChar;
            /* D와 * 위치 확인 */
            if (toPutChar == 'D')  
            {
                initDI = i;
                initDJ = j;
            }
            if (toPutChar == '*')
            {
                initStarI = i;
                initStarJ = j;
            }
        }
    }
    chk[initStarI][initStarJ] = make_tuple(false, true, 0);
    chk[initDI][initDJ] = make_tuple(true, false, 1);

    qStar.push(make_pair(initStarI, initStarJ));
    qD.push(make_pair(initDI, initDJ));

    while (!qD.empty())
    {
        int iD, jD;
        iD = qD.front().first;
        jD = qD.front().second;
        qD.pop();

        int iStar, jStar;
        iStar = qStar.front().first;
        jStar = qStar.front().second;
        qStar.pop();

        for (int idxD = 0; idxD < 4; idxD++)
        {
            int niD = iD+di[idxD];
            int njD = jD+dj[idxD];
            if(niD < 1 || niD > r || njD < 1 || njD > c)
            {
                continue;
            }
            if (get<0>(chk[niD][njD]) == true)
            {
                continue;
            }
            for (int idxStar = 0; idxStar < 4; idxStar++)
            {
                int niStar = iStar + di[iStar];
                ini njStar = jStar + dj[iStar];

            }
            
            if (get<1>(chk[]))
            
        }
        
    }
    
    return 0;
}