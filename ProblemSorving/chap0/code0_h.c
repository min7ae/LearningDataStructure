/*
0.h 길이가 n인 정수 배열 a[]와 위치 p가 주어진다. i, j를 구하는 프로그램을 작성하라.
*/
#include <stdio.h>
#include <stdlib.h>

int* findIandJ(int a[], int n, int p){
    // sum 계산을 위한 idx
    int *ret = (int*)malloc(sizeof(int));
    int idx, lastsum, sum;

    sum = a[p]; 
    // 직전 sum의 값을 저장
    lastsum = sum;

    for (idx = p-1; idx >= 0 ; idx--)
    {
        sum += a[idx];
        if (sum < lastsum)
        {
            sum = lastsum;
            ret[0] = idx;
            break;
        }
        lastsum = sum;
    }
    
    for (idx = p+1; idx < n; idx++)
    {
        sum += a[idx];
        if (sum < lastsum)
        {
            sum = lastsum;
            ret[1] = idx;
            break;
        }
        lastsum = sum;
    }

    return ret;
}

int main(){

    int a[] = {4,5,2,3,4, -1, 4,2, 2,3,1,-3,1,4};
    int alen = 14;
    int p = 7;
    int *r = NULL;
    r = findIandJ(a, alen, p);
    printf("%d %d", r[0], r[1]);
    return 0;
}
