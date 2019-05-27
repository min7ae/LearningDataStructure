#include <stdio.h>
#include <stdlib.h>

#define M 100
#define N 100

int map[M][N];

long long num_path(int m, int n){
    if (map[m][n] == 0)
        return 0;
    
    if (m == 0 && n == 0)
        return 1;

    return ( (m>0) ? num_path(m - 1, n) : 0) +
            ( (n>0) ? num_path(m, n - 1): 0);
}

int main(){
    int m, n, i, j;

    scanf("%d %d", &m, &n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    printf("%lld\n", num_path(m-1, n-1));
    return 0;
}