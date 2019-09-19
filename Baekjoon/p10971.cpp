/*
    외판원 순회 2
    https://www.acmicpc.net/problem/10971
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;
int w[11][11];

int main()
{
    int n;
    cin >> n;
    vector <int> v;
    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int toInputInt;
            cin >> toInputInt;
            w[i][j] = toInputInt;
        }
    }

    int minN = 2147483647;
    do
    {
        int tmpN = 0;
        for (int i = 0; i <= n-1; i++)
        {
            if(i != (n-1))
            {
                // cout << v[i] << " " << v[i+1] << " " << w[v[i]][v[i+1]] << " ";
                tmpN += w[v[i]][v[i+1]];
            }
            else
            {
                // cout << v[i] << " " << v[0] << " " << w[v[i]][v[0]] << " ";
                tmpN += w[v[i]][v[0]];
            }
        }
        // cout << endl;
        if(minN > tmpN)
        {
            minN = tmpN;
        }
    } while (next_permutation(v.begin(), v.end()));
    cout << minN;
    
    return 0;
}