/*
    1, 2, 3 더하기 5
    https://www.acmicpc.net/problem/15990
 */

#include <iostream>

using namespace std;

struct ott{
    long one;
    long two;
    long three;
};

const int MAX = 100000;
const int retMAX = 1000000009;
ott v[MAX + 1];

int main(){
    int n;
    cin >> n;
    
    v[1].one = 1l; v[1].two = 0l; v[1].three = 0l;
    v[2].one = 0l; v[2].two = 1l; v[2].three = 0l;
    v[3].one = 1l; v[3].two = 1l; v[3].three = 1l;

    for (int i = 4; i <= MAX; i++)
    {
        v[i].one = (v[i-1].two + v[i-1].three)%retMAX;
        v[i].two = (v[i-2].one + v[i-2].three)%retMAX;
        v[i].three = (v[i-3].one + v[i-3].two)%retMAX;
    }
    
    while (n--)
    {
        int inpNum;
        cin >> inpNum;
        cout << (v[inpNum].one + v[inpNum].two + v[inpNum].three)%retMAX << '\n';
    }
    return 0;
}