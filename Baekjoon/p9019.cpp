/*
    DSLR
    https://www.acmicpc.net/problem/9019
 */

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<int> makeIntVector(int n) {
    vector<int> result;
    while (n>10) {
        result.push_back(n%10);
        n = n / 10;
    }
    // 1234 -> result {4, 3, 2, 1};
    return result;
}

pair<int, char> DSLR(int n, int i) {
    int result = 0;
    char resultC; 
    // n : 입력
    // i : D, S, L, R
    switch (i)
    {
    case 0: {
        // D
        result = n*2;
        if (result > 9999) {
            result %= 10000;
        }
        resultC = 'D';
        break;
    }
    case 1: {
        // S
        if (n == 0) {
            result = 9999;
        } else {
            result = n-1;
        }
        resultC = 'S';
        break;
    }
    case 2: {
        // L
        vector<int> nV = makeIntVector(n);
        // 1234 -> size: 4, 1000
        // nV = {4, 3, 2, 1};
        int result = 0;
        int digit = nV.size()-1;
        // digit = 3;
        for (int i=nV.size()-2; i>=0; i--) {
            result += nV[i]*pow(10, digit);
            // i = 2, 1, 0
            // result , i=2
            // 2 * (10**3) 2000
            // result, i=1
            // 3 * (10**2) 2300
            // result, i=0;
            // 4 * (10**1) 2340
            digit -= 1;
        }
        result += nV[nV.size()-1];
        resultC = 'L';
        break;
    }
    case 3: {
        // R
        vector<int> nV = makeIntVector(n);
        // 1234 -> size: 4, 1000
        // nV = {4, 3, 2, 1};
        int digit = nV.size()-1;
        int result = nV[0]*pow(10, digit);
        digit -= 1;
        for (int i=nV.size()-1; i>=1; i--) {
            result += nV[i]*pow(10, digit);
            // i = 2, 1, 0
            // result , i=2
            // 2 * (10**3) 2000
            // result, i=1
            // 3 * (10**2) 2300
            // result, i=0;
            // 4 * (10**1) 2340
            digit -= 1;
        }
        resultC = 'R';
        break;
    }
    }
    return make_pair(result, resultC);
}

int main() {
    int n;
    cin >> n;
    // q: 문제
    vector<pair<int, int>> q(n);
    for (int i=0; i<n; i++) {
        cin >> q[i].first >> q[i].second;
    }

    // for (int i=0; i<n; i++) {
    //     cout << q[i].first << " " << q[i].second << endl;
    // }
    for (int i=0; i<n; i++) {
        // i번째 문제.
        // start: 처음, end: 목표
        int start = q[i].first;
        int end = q[i].second;
        
        // v[0] = start부터 0 도착 할 때까지 필요한 연산 횟수
        // v[9999] = start부터 9999 도착 할 때까지 필요한 연산 횟수
        // v[i] == -1 아직 방문X
        vector<int> v(10000, -1);
        vector<string> answer(10000);
        queue<int> q;
        v[start] = 0;
        q.push(start);
        bool isFinished = false;
        while (!q.empty()) {
            if (isFinished == true) {
                break;
            }
            int n = q.front();
            q.pop();

            // 연산을 4번 하는데, 
            for (int i=0; i<4; i++) {
                pair<int, char> nn = DSLR(n, i);
                // cout << n << ": " << nn.first << " " << nn.second << endl;
                int nnn = nn.first;
                if (v[nnn] == -1) {
                    // 방문X
                    v[nnn] = v[n] + 1;
                    answer[nnn] = answer[n] + nn.second;
                    if (nnn == end) {
                        isFinished = true;
                    }
                    q.push(nnn);
                }
            }
        }
        cout << answer[end];
        cout << endl;
    }

    return 0;
}