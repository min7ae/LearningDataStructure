#include <iostream>
#include <vector>
using namespace std;

bool next_permutation(int *a, int n) {
    int i = n-1;
    while(i>0 && a[i-1] >= a[i]) {
        i -= 1;
    }
    if (i <= 0) {
        return false;
    }
    int j = n-1;
    while(a[j] <= a[i-1]) {
        j -= 1;
    }
    swap(a[i-1], a[j]);
    while(i<j) {
        swap(a[i], a[j]);
        i += 1;
        j -= 1;
    }
    return true;
}

int main() {
    return 0;
}