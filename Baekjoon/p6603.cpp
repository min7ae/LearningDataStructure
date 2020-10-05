#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printTestCase(int n, vector<int> v) {
    vector<bool> bitMask (n, false);
    
}

int main() {
    int k;
    while (true) {
        cin >> k;
        if (k == 0) {
            break;
        }
        vector<int> v(k);
        for (int i=0; i<k; i++) {
            cin >> v[i];
        }
        printTestCase(k, v);
        cout << '\n';
    }
    return 0;
}