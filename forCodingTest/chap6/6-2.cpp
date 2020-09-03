#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> a = {5, 2, 3, 4, 1, 6, 8, 7};
    
    for(int i=1; i<a.size(); i++) {
        for (int j=i; j>0; j--) {
            if (a[j] < a[j-1]) {
                int tmp = a[j-1];
                a[j-1] = a[j];
                a[j] = tmp;
            }
            else {
                break;
            }
        }
    }

    for (int aa : a) {
        cout << aa << " ";
    }

}