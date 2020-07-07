/*
    단어 수학
    https://www.acmicpc.net/problem/1339
 */

#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool acs(pair<int, string>v1, pair<int, string>v2) {
    return v1.first > v2.first;
}

int stringtoint(string str, int number[]){
    cout << str << " ";
    int result = 0;
    int idx = 0;
    int len = str.length();
    while(len > 0) {
        int order = str[idx] - 'a';
        result += number[order] * pow(10, len-1);
        len--;
        idx++;
    }
    cout <<result <<endl;
    return result;
}

int main() {
    int c;
    vector<pair<int, string> > v;
    vector<pair<int, string> >::iterator iter;
    cin >> c;
    for(int i=0; i<c; i++) {
        string str;
        cin >> str;
        v.push_back(make_pair(str.length(), str));
    }

    sort(v.begin(), v.end(), acs);

    int myNumber = 9;
    bool isSetNumbers[10] = {false, };
    int setNumbers[10];
    int result = 0;
    for(iter = v.begin(); iter != v.end(); iter++) {
        int hereNumber = 0;
        int length = iter->first;
        const string str = iter->second;
        for(int i=0; i<length; i++) {
            char c = str[i];
            int order = c - 'a';
            // 처음 들어간다면,
            if (isSetNumbers[order] == false) {
                cout << c << myNumber << endl;
                isSetNumbers[order] = true;
                setNumbers[order] = myNumber;
                myNumber -= 1;
            }
        }
        result += stringtoint(str, setNumbers);
    }
    cout << result;
    return 0;
}
