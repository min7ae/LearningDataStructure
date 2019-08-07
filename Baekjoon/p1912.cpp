/*
    연속합
    https://www.acmicpc.net/problem/1912
 */

#include <iostream>

#define MAX(X,Y) ((X) > (Y) ? (X) : (Y)) 

using namespace std;

const int citmpMax = 100000;
int arrInt[citmpMax + 1] = {0, };
int maxRes[citmpMax + 1] = {0, };
int tmpRes[citmpMax + 1] = {0, };

int main(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arrInt[i];
    }


    // 처음으로 양수등장하는 idx를 찾자.
    int firstIndex = 1;
    while (arrInt[firstIndex] < 0)
    {
        firstIndex++;
    }
    // (-) 구간 이후 합 저장 공간
    int tmp = 0;
    int lastIndex = 0;
    for (int i = firstIndex ; i <= n; i++)
    {
        // 계산할 친구를 검사
        // 그리고 양수라면 그냥 더하고 음수라면 임시 저장공간에 저장.
        int toCalcul = arrInt[i];
        tmpRes[i] = tmpRes[i-1] + toCalcul;
        if (toCalcul < 0)
        {
            tmp = 0;
            maxRes[i] = maxRes[i-1];
        } else {
            tmp += toCalcul;

            int tmpMax1 = max(tmpRes[i], tmp);
            int tmpMax2 = max(maxRes[i-1], tmpMax1);
            maxRes[i] = max(tmpMax2, maxRes[lastIndex]);
            lastIndex = i;
        }
    }
    cout << maxRes[n];
    return 0;
}