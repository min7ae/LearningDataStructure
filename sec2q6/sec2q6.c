#include <stdio.h>

int main(){
    int i = 0;
    int tmpNum = 0;
    int maxNum = 0;
    int minNum = 0;
    int sum = 0;
    double avg = 0.0;
    for(i = 1; i <= 7 ; i++){
        printf("정수형 데이터 입력 : ");
        scanf("%d", &tmpNum);
        if (maxNum <= tmpNum) {
            maxNum = tmpNum;
        }
        if (minNum >= tmpNum) {
            minNum = tmpNum;
        }
        sum += tmpNum;
        avg = (double)sum/i;
    }
    printf("최대값 : %d\n", maxNum);
    printf("최소값 : %d\n", minNum);
    printf("전체합 : %d\n", sum);
    printf("평 균 : %lf\n", avg);
    return 0;
}