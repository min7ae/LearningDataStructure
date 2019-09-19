/*
    차이를 최대로
    https://www.acmicpc.net/problem/10819
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int toInputInt;
        cin >> toInputInt;
        v.push_back(toInputInt);
    }
    sort(v.begin(), v.end());

    int maxN = 0;

    int count = 0;
    do
    {
        int tmpM = 0;
        for (int i = 0; i < n-1; i++)
        {
            tmpM += abs(v[i] - v[i+1]);
        }
        // cout << tmpM << endl;
        if (maxN < tmpM)
        {
            maxN = tmpM;
        }
        
    } while (next_permutation(v.begin(), v.end()));
    
    cout << maxN;
    return 0;
}