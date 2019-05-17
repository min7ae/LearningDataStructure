#include <stdio.h>
#define DivError    -256

/*  q = ap+r 
    몫: q, 나머지: r
    받는 수 p, a
    a/p = q ... r
*/
int DivInt(int a, int p, int* ret){
    if (p == 0) {
        return DivError;
    }
    ret[0] = a / p;
    ret[1] = a % p;
    return 1;
}
int main(){
    int p, a;
    int ret[2] = {0, };
    printf("나눗셈 위한 두 정수 입력: ");
    scanf("%d %d", &a, &p);
    while(DivInt(a, p, ret) == DivError) {
        printf("0으로 나누는 오류발생! 숫자 재 입력\n");
        printf("나눗셈 위한 두 정수 입력: ");
        scanf("%d %d", &a, &p);
    }
    printf("몫: %d, 나머지: %d", ret[0], ret[1]);
    return 0;
}