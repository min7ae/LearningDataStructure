#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int sum = a+b+c;
    bool isPossible = false;
    if (sum%3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<bool>> chk (1501, vector<bool>(1501, false));
    queue<pair<int, int>> q;

    // 방문하고
    chk[a][b] = true;
    q.push(make_pair(a, b));
    
    while(!q.empty()) {
        // 반복하는데, 
        int qa = q.front().first;
        int qb = q.front().second;
        int qc = sum - qa - qb;
        q.pop();
        
        if (qa != qb) {
            int qqa = qa;
            int qqb = qb;
            int qqc = qc;
            if (qqa > qqb) {
                qqa = qa - qb;
                qqb = qb + qb;
            } else if (qqa < qqb) {
                qqa = qa + qa;
                qqb = qb - qa;
            }
            if (chk[qqa][qqb] == false) {
                cout << qqa << " " << qqb << " " << qqc << endl;
                chk[qqa][qqb] = true;
                if (qqa == qqb && qqb == qqc) {
                    cout << 1 <<endl;
                    return 0;
                }
                q.push(make_pair(qqa, qqb));
            }
        }

        if (qb != qc) {
            int qqa = qa;
            int qqb = qb;
            int qqc = qc;
            if (qqb > qqc) {
                qqb = qb - qc;
                qqc = qc + qc;
            } else if (qqb < qqc) {
                qqb = qb + qb;
                qqc = qc - qb;
            }
            qqa = sum - qqb - qqc;
            if (chk[qqa][qqb] == false) {
                cout << qqa << " " << qqb << " " << qqc << endl;
                chk[qqa][qqb] = true;
                if (qqa == qqb && qqb == qqc) {
                    cout << 1 <<endl;
                    return 0;
                }
                q.push(make_pair(qqa, qqb));
            }
        }

        if (qa != qc) {
            int qqa = qa;
            int qqb = qb;
            int qqc = qc;
            if (qqa > qqc) {
                qqa = qa - qc;
                qqc = qc + qc;
            } else if (qqa < qqc) {
                qqa = qa + qa;
                qqc = qc - qa;
            }
            qqb = sum - qqa - qqc;
            if (chk[qqa][qqb] == false) {
                cout << qqa << " " << qqb << " " << qqc << endl;
                chk[qqa][qqb] = true;
                if (qqa == qqb && qqb == qqc) {
                    cout << 1 <<endl;
                    return 0;
                }
                q.push(make_pair(qqa, qqb));
            }
        }

    }

    if (isPossible) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}