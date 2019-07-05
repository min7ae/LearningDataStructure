/*
    큐
    https://www.acmicpc.net/problem/10845
 */

#include <iostream>
#include <string>

using namespace std;

const int MAX_ORDER = 10000;
int myqueue[MAX_ORDER] = {0, };

int main(){
    int n;
    cin >> n; // 명령어 개수
    string order; // 명령어

    int front = 0, back = 0;

    while (n--)
    {
        cin >> order;
        if (order == "push")
        {
            int inpInt; 
            cin >> inpInt; // 정수 X
            myqueue[back++] = inpInt;
        } else if(order == "pop") {
            if (front == back)
            {
                cout << -1 << '\n';
            } else {
                cout << myqueue[front++] << '\n';
            }
        } else if (order == "size") {
            cout << back - front << '\n';
        } else if (order == "empty") {
            if (front == back)
            {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else if (order == "front") {
            if (front == back)
            {
                cout << -1 << '\n';
            } else {
                cout << myqueue[front] << '\n';
            }
        } else if (order == "back") {
            if (front == back)
            {
                cout << -1 << '\n';
            } else {
                if (back != 0)
                {
                    cout << myqueue[back-1] << '\n';
                } else {
                    cout << 0 << '\n';
                }
                
                
            }
        } 
    }
    

    return 0;
}