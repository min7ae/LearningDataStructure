/*
    알파벳 찾기
    https://www.acmicpc.net/problem/10809
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int num[26];
    memset(num, -1, sizeof(num));
    char c;
    int cnt = 0;
    while(scanf("%1c",&c) == 1){
        if(num[c-'a'] == -1)
            num[c-'a'] = cnt;
        cnt += 1;
    }

    for (int i = 0; i < 26; i++)
    {
        cout << num[i] << " ";
    }
    
}