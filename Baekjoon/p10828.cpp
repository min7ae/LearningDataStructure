/*
    스택
    https://www.acmicpc.net/problem/10828
 */

#include <iostream>
#include <string>
#include <vector> 

using namespace std;

int main(){
    // 명령의 수
    int n;
    cin >> n;

    // 주어진 명령을 입력받을 string
    string inpOrder;

    // 정수를 넣을 vector
    vector <int> v;
    // 명령의 수 만큼 수행
    while(n != 0){
        cin >> inpOrder;
        // push 명령어 일 경우, 
        if (inpOrder == "push")
        {
            // push 할 정수
            int toPush;
            cin >> toPush;
            v.push_back(toPush);
        }
        // 아니라면,
        else if (inpOrder == "pop") {
            if (v.empty() == true)
            {
                cout << -1 << endl;
            } else {
                cout << v.back() << endl;
                v.pop_back();
            }
        } else if (inpOrder == "size") {
            cout << v.size() << endl;
        } else if (inpOrder == "empty") {
            if (v.empty() == true)
            {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else if (inpOrder == "top") {
            if (v.empty() == true)
            {
                cout << -1 << endl;
            } else {
                cout << v.back() << endl;
            }
        }
        n--;
    }
    return 0;
}