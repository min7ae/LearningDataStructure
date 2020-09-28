/**
 * 떡볶이 떡 만들기
 **/

#include <iostream>
#include <vector>

using namespace std;

void qSort(vector<int> &v, int start, int end) {
    // 종료조건
    if (start >= end) {
        return;
    }
    // 두가지 커서와 피벗을 준비
    int pv = start;
    int left = start+1;
    int right = end;

    while(left <= right) {
        while(left <= end && v[left] <= v[pv]) {
            left += 1;
        }
        while (start < right && v[pv] <= v[right]) {
            right -= 1;
        }
        if (left > right) {
            // 엇갈렸다면
            // 작은 데이터와 피벗을 교체
            int tmp = v[right];
            v[right] = v[pv];
            v[pv] = tmp;
        } else {
            // 아니라면,
            int tmp = v[right];
            v[right] = v[left];
            v[left] = tmp;
        }
    }
    qSort(v, start, right-1);
    qSort(v, right+1, end);
}

int getReminder(vector<int> &v, int target) {
    // v는 오름차순 정렬 되었다고 가정
    int result = 0;
    for (int i : v) {
        int s = 0;
        if (i < target) {
            s = i - target;
        }
        result += s;
    }
    return result;
}

// return index
int binarySearch(vector<int> &v, int target, int begin, int end) {
    // 못 찾음. 
    if (begin > end) {
        return -1;
    }
    int mid = (begin + end) / 2;
    if (getReminder(v, mid) == target) {
        return mid;
    } else if (getReminder(v, mid) > target) {
        return binarySearch(v, target, begin, mid-1);
    } else {
        return binarySearch(v, target, mid+1, end);
    }
}

int main() {
    int n, target;
    int answer = 0;
    cin >> n >> target;
    vector<int> stick(n);
    for (int i=0; i<n; i++) {
        cin >> stick[i];
    }

    qSort(stick, 0, stick.size()-1);

    int begin = 0;
    int end = stick.back();
    while (begin <= end) {
        int mid = (begin + end) / 2;
    }

    return 0;
}
