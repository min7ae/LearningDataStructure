/*
    괄호
    https://www.acmicpc.net/problem/9012
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

void NO(){
    cout << "NO" << endl;
}

void YES(){
    cout << "YES" << endl;
}

void printAnswer(string PS){
    char inpChar;
    vector <char> v;

    for (int i = 0; i < PS.size(); i++)
    {
        inpChar = PS.at(i);
        // 들어가
        if (inpChar == '(')
        {
            v.push_back(inpChar);
        // 빼야한다면,  
        } else {
            if(v.empty() != true){
                char tmpChar = v.back();
                if (tmpChar == '(')
                {
                    // 빼야할게 맞아
                    v.pop_back();
                } else {
                    //아니라면,
                    NO();
                    return;
                }
            // 비어있는데 빼려하니까 No!
            } else {
                NO();
                return;
            }
        }
    }
    //살았네?
    if (v.empty() != true)
    {
        NO();
        return;
    }
    YES();
}

int main(){
    // 입력받을 숫자
    int n;
    scanf("%d\n", &n);
    string PS;

    while(n != 0) {
        // 굳이 getline 안써도 되나바 cin >> 쓰자
        getline(cin, PS);
        printAnswer(PS);
        n--;
    }
    return 0;
}