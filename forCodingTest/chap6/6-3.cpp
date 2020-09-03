#include <iostream>
#include <vector>

using namespace std;

void quick(vector<int> &v, int begin, int end) {
    // 종료 조건
    if (begin >= end) {
        return;
    }
    // 피벗
    int pv = begin;
    // 두가지 커서를 준비
    int left = begin+1;
    int right = end;

    while(left <= right) {
        while (left <= end && v[left] <= v[pv])
        {
            left += 1;
        }
        while (begin < right && v[pv] <= v[right]) {
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
            // 작은 데이터와 큰 데이터를 교체
            int tmp = v[right];
            v[right] = v[left];
            v[left] = tmp;
        }
    }
    quick(v, begin, right - 1);
    quick(v, right + 1, end);
}

int main() {
    vector<int> a = {1, 5, 2, 3, 4, 1, 6, 8, 7, 1};

    quick(a, 0, a.size()-1);

    for (int aa : a) {
        cout << aa << " ";
    }

    
    return 0;
}