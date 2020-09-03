/*
    이진 탐색: 반으로 쪼개면서 탐색하기
*/
#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &v, int target, int start, int end) {
    if (start > end) {
        return -1;
    }
    int mid = (start + end) / 2;
    cout << mid << " " << v[mid] << " " << target << endl;
    if (v[mid] == target) {
        return mid;
    }
    else if (v[mid] > target) {
        return binary_search(v, target, start, mid-1);
    } else {
        // v[mid] > target
        return binary_search(v, target, mid+1, end);
    }
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int s = binary_search(arr, target, 0, arr.size()-1);
    cout << s + 1;
    
    return 0;
}