/*
    숨바꼭질 4
    https://www.acmicpc.net/problem/13913
*/
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

const int NumofCases = 3;
bool visitedN[100001] = {false, };
unsigned int arrFromStart[100001] = {0, };
int savedMyParent[100001];

int main()
{
    int n, k;
    cin >> n >> k;
    queue<int> q;
    visitedN[n] = true;
    arrFromStart[n] = 0;
    q.push(n);
    while (!q.empty())
    {
        int p = q.front();
        unsigned int currentTime = arrFromStart[p]+1;
        q.pop();
        /* for debuging,  */
        // cout << p << " ";
        if ((p+1) <= 100000 && visitedN[p+1] == false)
        {
            arrFromStart[p+1] = currentTime;
            savedMyParent[p+1] = p;
            if((p+1) == k)
            {
                break;
            }
            visitedN[p+1] = true;
            q.push(p+1);
        }
        if ((p-1) >= 0 && visitedN[p-1] == false)
        {
            arrFromStart[p-1] = currentTime;
            savedMyParent[p-1] = p;
            if((p-1) == k)
            {
                break;
            }
            visitedN[p-1] = true;
            q.push(p-1);
        }
        if ((p*2) <= 100000 && visitedN[p*2] == false)
        {
            arrFromStart[p*2] = currentTime;
            savedMyParent[p*2] = p;
            if((p*2) == k)
            {
                break;
            }
            visitedN[p*2] = true;
            q.push(p*2);
        }
    }
    cout << arrFromStart[k] << '\n';

    stack<int> forPrintStack;
    int findInit = k;
    forPrintStack.push(findInit);
    while (true)
    {
        if(findInit == n)
        {
            break;
        }
        findInit = savedMyParent[findInit];
        forPrintStack.push(findInit);
    }
    while (!forPrintStack.empty())
    {
        cout << forPrintStack.top() << " ";
        forPrintStack.pop();
    }
    
    return 0;
}