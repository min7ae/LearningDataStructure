#include <stdio.h>

int main(){
    int n = 0;
    printf("자연수 입력: ");
    scanf("%d", &n);
    int arrS[2] = {0, };
    for(int i = 1; i <= n; i++)
    {
        if( i%2 == 0) 
            arrS[0] += i;
        else arrS[1]+= i;
    }

    printf("%d 이하 홀수 합: %d\n", n, arrS[1]);
    printf("%d 이하 짝수 합: %d\n", n, arrS[0]);

    return 0;
}