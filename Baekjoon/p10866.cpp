/*
    덱
    https://www.acmicpc.net/problem/10866
 */

#include <iostream>
#include <string>

using namespace std;

/* 
    명령의 갯수가 10,000개 이므로, 최초 커서 10,001에서 시작.
 */
const int MAX_ORDER = 20001;
int mydeque[MAX_ORDER] = {0, };

void pPlus(){
    cout << 1 << '\n';
}

void pMinus(){
    cout << -1 << '\n';
}

void pZero(){
    cout << 0 << '\n';
}

int main(){
    int n;
    cin >> n;
    // 명령어
    string order;

    // curser
    int front=10001, back=10001;

    while (n--)
    {
        cin >> order;
        if (order == "push_front")
        {
            int X;
            cin >> X;
            mydeque[--front] = X;
        } else if(order == "push_back"){
            int X;
            cin >> X;
            mydeque[back++] = X;
        } else if(order == "pop_front"){
            if (front == back)
            {
                pMinus();
            } else {
                cout << mydeque[front] << '\n';
                front += 1;
            }
        } else if(order == "pop_back"){
            if (front == back)
            {
                pMinus();
            } else {
                cout << mydeque[back-1] << '\n';
                back -= 1;
            }
        } else if(order == "size"){
            cout << back-front << '\n';
        } else if(order == "empty"){
            if (front == back)
            {
                pPlus();
            } else {
                pZero();
            }
        } else if(order == "front"){
            if (front == back)
            {
                pMinus();
            } else {
                cout << mydeque[front] << '\n';
            }
        } else if(order == "back"){
            if (front == back)
            {
                pMinus();
            } else {
                cout << mydeque[back-1] << '\n';
            }
        }
    }

    

    return 0;
}