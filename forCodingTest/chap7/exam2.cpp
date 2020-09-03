#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

bool binarySearch(vector<int> &mart, int target, int begin, int end) {
    // 항상 커야 하는데
    // begin 이 end 보다 커진다면 
    if (begin > end) {
        return false;
    }
    int mid = (begin + end)/2;
    if (mart[mid] == target) {
        return true;
    } else if (target < mart[mid]) {
        // mid가 end가 되어야 함.
        binarySearch(mart, target, begin, mid-1);
    } else {
        binarySearch(mart, target, mid+1, end);
    }
}

int main() {
    int n, m;
    
    cin >> n;
    vector<int> mart(n);
    for (int i=0; i<n; i++) {
        cin >> mart[i];
    }
    cin >> m;
    vector<int> cus(m);
    for (int i=0; i<m; i++) {
        cin >> cus[i];
    }

    // 정렬되어 있을 때,
    sort(mart.begin(), mart.end());

    for (int i : cus) {
        if (binarySearch(mart, i, 0, mart.size()-1)) {
            cout << "yes" << " ";
        } else {
            cout << "no" << " ";
        }
    }

    return 0;
}