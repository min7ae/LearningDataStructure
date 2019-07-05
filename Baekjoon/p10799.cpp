/*
    쇠막대기
    https://www.acmicpc.net/problem/10799
 */

#include <iostream>
#include <string>
#include <stack>


using namespace std;

int main(){
    string stick;
    cin >> stick;

    int retSum = 0;
    stack<int> s;
    bool possibleLaser = false;
    
    for (int i = 0; i < stick.size(); i++)
    {
        char inpChar = stick.at(i);
        if (inpChar == '(')
        {
            // 얘는 그냥 집어넣어
            s.push(inpChar);
            possibleLaser = true;
        } else {
            // cout << s.size()-1 << " ";
            // 확인하자
            if (possibleLaser == true)
            {
                // cout << " L ";
                retSum += (s.size()-1);
                possibleLaser = false;
            } else { 
                retSum += 1;
            }
            s.pop();
        }
    }
    
    cout << retSum << '\n';
    return 0;
}