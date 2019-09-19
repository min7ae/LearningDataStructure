/*
    일곱 난쟁이
    https://www.acmicpc.net/problem/2309
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    vector<int> arrDwarf;
    int toInputInt;
    int originMax = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> toInputInt;
        arrDwarf.push_back(toInputInt);
        originMax += toInputInt;
    }

    int currentMax = originMax;
    int ansI = -1;
    int ansJ = -1;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 1; j < 9; j++)
        {
            if (i == j)
            {
                continue;
            }
            
            currentMax = originMax;
            currentMax -= (arrDwarf[i] + arrDwarf[j]);
            if (currentMax < 100)
            {
                /* this is answer */
                ansI = i;
                ansJ = j;
                // cout << ansI << " " << ansJ << endl ;
            }
        }
    }
    arrDwarf.erase(arrDwarf.begin() + ansI-1);
    arrDwarf.erase(arrDwarf.begin() + ansJ-1);
    sort(arrDwarf.begin(), arrDwarf.end());
    for (int i = 0; i < arrDwarf.size(); i++)
    {
        cout << arrDwarf[i] << endl;
    }
    
    return 0;
}
