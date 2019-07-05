/*
    edit ver.
    에디터
    https://www.acmicpc.net/problem/1406
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    // 에디터 수정 후
    string outStr;
    cin >> outStr;
    
    int n;
    cin >> n;

    // 커서 전, 후 담기는 stack
    stack <char> leftStr, rightStr;
    for (char c : outStr)
        leftStr.push(c);
    
    while (n--)
    {
        char ch;
        cin >> ch; // 명령을 입력받고,

        switch (ch)
        {
        case 'L':
        {
            if (!leftStr.empty())
            {
                char tmpChar = leftStr.top();
                leftStr.pop();
                rightStr.push(tmpChar);
            }
            break;
        }
        case 'D':
        {
            if (!rightStr.empty())
            {
                char tmpChar = rightStr.top();
                rightStr.pop();
                leftStr.push(tmpChar);
            }
            break;
        }
        case 'B':
        {
            if (!leftStr.empty())
            {
                leftStr.pop();
            }
            break;
        }
        case 'P':
        {
            char inpChar;
            cin >> inpChar;
            leftStr.push(inpChar);
            break;
        }
        
        default:
            break;
        }
        
    } 
    while (!leftStr.empty())
    {
        char tmpChar = leftStr.top();
        leftStr.pop();
        rightStr.push(tmpChar);
    }
    while (!rightStr.empty())
    {
        cout << rightStr.top();
        rightStr.pop();
    }
    return 0;
}