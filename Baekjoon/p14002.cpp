/*
    가장 긴 증가하는 부분 수열 4
    https://www.acmicpc.net/problem/14002
 */

#include <iostream>
using namespace std;

const int cimaxInpNum = 1000;

int arrA[cimaxInpNum + 1] = {0, };
int arrNIS[cimaxInpNum + 1] = {0, };
int indexA[cimaxInpNum + 1] = {0, };
int printA[cimaxInpNum + 1] = {0, };

int main(){

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arrA[i];
    }
    // 최초 1
    arrNIS[1] = 1;
    int ret = arrNIS[1];

    int index = n;
    
    // 2번째 요소부터 최댓값을 찾자.
    for (int i = 2; i <= n; i++)
    {
        // 가장 긴 증가하는 부분 수열의 길이 중 임시 최댓값
        int tmpMax = 1;

        int tmpArrNIS[cimaxInpNum + 1] = {0, };

        // 자기자신-1 번째 요소부터 감소해가며 검색한다
        for (int j = i-1; j >= 1; --j)
        {
            // 자신보다 작은 숫자가 있으면,
            if (arrA[j] < arrA[i] )
            {
                // NIS+1 한값이 현재 임시 최댓값보다 큰지 확인한 뒤
                int tmpNISplusOne = arrNIS[j] + 1;
                if (tmpNISplusOne > tmpMax)
                {
                    // 크다면, 그 때의 NIS+1을 임시 최댓값에 저장한다.
                    tmpMax = tmpNISplusOne;
                    
                    // 그때 배열[i]에 j의 index를 저장
                    indexA[i] = j;
                }
            }
        }
        
        // 다 돌았으면 그때의 자신의 최댓값 = 임시 최댓값
        arrNIS[i] = tmpMax; 
        // 지금까지 최댓값 저장.
        if (arrNIS[i] > ret)
        {
            ret = arrNIS[i];
            index = i;
        }
    }

    int i = index;
    cout << ret << '\n';

    int rret = ret;
    while (arrA[i] != 0)
    {
        printA[ret--] = arrA[i];
        i = indexA[i];
    }

    for (int i = 1; i <= rret; i++)
    {
        cout << printA[i];
        if (rret != i)
        {
            cout << " ";
        }
        
    }
    


    
    return 0;
}