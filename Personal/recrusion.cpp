#include <vector>

int go(int count, int sum, int goal) {
    if (sum > goal) {
        return 0;
    }
    if (sum == goal) {
        return 1;
    }
    int result = 0;
    for(int i=1; i<=3; i++) {
        result += go(count + 1, sum + i, goal);
    }
    return result;
}

void go(int n, vector<char> &alpha, string pass, int i) {
    if (n == alpha.size()) {
        if (check(pass) == true) {
            cout << pass << endl;
        }
        return;
    }
    if (i >= alpha.size()) {
        return;
    }
    go(n, alpha, pass + alpha[i], i+1);
    go(n, alpha, pass, i+1);
}

int go(int n, )