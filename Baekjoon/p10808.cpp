/*
    알파벳 개수
    https://www.acmicpc.net/problem/10808
 */

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int num[26] = {0, };
    char c;
    
    while(scanf("%1c",&c) == 1){
        num[c-'a'] += 1;
    }

    for (int i = 0; i < 26; i++)
    {
        cout << num[i] << " ";
    }
    
}