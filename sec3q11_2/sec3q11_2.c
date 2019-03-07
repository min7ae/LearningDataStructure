#include <stdio.h>

int main(){
    int n = 0;
    printf("2 이상 입력: ");
    scanf("%d", &n);
    int i = 0;
    int sum = 0;
    while(n > sum){
        i++;
        sum += i;
    }
    printf("%d를 넘기 이전의 합: %d\n", n, sum-i);
    printf("%d를 넘기 이후의 합: %d\n", n, sum);

    return 0;
}