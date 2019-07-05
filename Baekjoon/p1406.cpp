/*
    에디터
    https://www.acmicpc.net/problem/1406
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    // 에디터 수정 후, 수정하기전 left, right String
    string outStr, leftStr, rightStr;
    cin >> outStr;

    // 명령의 갯수와 현재 커서 위치
    int n, cur = outStr.size();
    cin >> n;
    
    stack <string> s;

    while (n--)
    {
        char ch;
        cin >> ch; // 명령을 입력받고,

        switch (ch)
        {
        case 'L':
        {
            cur -= 1;
            if (cur < 0)
            {
                cur = 0;
            }
            break;
        }
        case 'D':
        {
            cur += 1;
            if (cur > outStr.size())
            {
                cur = outStr.size();
            }
            break;
        }
        case 'B':
        {
            if (cur == 0)
            {
                leftStr = "";
            } else {
                leftStr = outStr.substr(0, cur-1);
            }
            rightStr = outStr.substr(cur);
            outStr = leftStr + rightStr;
            cur -= 1;
            if (cur < 0)
            {
                cur = 0;
            }
            break;
        }
        case 'P':
        {
            char inpchar;
            cin >> inpchar;
            if (cur == 0)
            {
                leftStr = "";
            } else {
                leftStr = outStr.substr(0, cur);
            }
            rightStr = outStr.substr(cur);
            outStr = leftStr + inpchar + rightStr;
            cur += 1;
            if (cur > outStr.size())
            {
                cur = outStr.size();
            }
            break;
        }
        
        default:
            break;
        }
        
    } 
    cout << outStr << '\n';

    return 0;
}