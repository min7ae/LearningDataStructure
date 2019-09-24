/*
    크로아티아 알파벳
    https://www.acmicpc.net/problem/2941
*/
#include <iostream>
#include <string>

using namespace std;
int main()
{
    string str;
    cin >> str;
    int countWord = 0;

    for (int i = 0; i < str.size();)
    {
        char c;
        c = str.at(i);
        cout << c << endl;
        if (c == 'c')
        {
            i += 1;
            c = str.at(i);
            if (c == '=' || c == '-')
            {
                i += 1;
            }
            countWord++;
            continue;
        } 
        else if (c == 'd')
        {
            
            i += 1;
            c = str.at(i);
            if (c == 'z')
            {
                i += 2;
            } else if (c == '-')
            {
                i += 1;
            }
            countWord++;
            continue;
        }
        else if(c == 'l')
        {
            i += 1;
            c = str.at(i);
            if (c == 'j')
            {
                i += 1;
            }
            countWord++;
            continue;
        }
        else if(c == 'n')
        {
            i += 1;
            c = str.at(i);
            if (c == 'j')
            {
                i += 1;
            }
            countWord++;
            continue;
        }
        else if(c == 's')
        {
            i += 1;
            c = str.at(i);
            if (c == '=')
            {
                i += 1;
            }
            countWord++;
            continue;
        }
        else if(c == 'z')
        {
            i += 1;
            c = str.at(i);
            if (c == '=')
            {
                i += 1;
            }
            countWord++;
            continue;
        }
        countWord++;
        i++;
    }
    cout << countWord;
}