#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

pair<int, char> func(int letter, int start) {
    int result = 0;
    char resultChar;
    switch (letter)
    {
    case 0: {
        // D
        result = start*2;
        if (result > 9999) {
            result = result % 10000;
        }
        resultChar = 'D';
        break;
    }

    case 1: {
        // S
        result = start-1;
        if (result == -1) {
            result = 9999;
        }
        resultChar = 'S';
        break;
    }

    case 2: {
        // L
        result = (start % 1000) * 10 + start / 1000;
        resultChar = 'L';
        break;
    }

    case 3: {
        // R/
        result = start / 10 + (start % 10) * 1000;
        resultChar = 'R';
        break;
    }
    
    default:
        break;
    }

    return make_pair(result, resultChar);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        // case
        vector<bool> check(10000, false);
        vector<int> dist(10000);
        vector<int> from(10000);
        vector<char> how(10000);
        
        queue<int> q;
        
        int start, end;
        cin >> start >> end;
        check[start] = true;
        q.push(start);
        dist[start] = 0;
        from[start] = -1;
        how[start] = ' ';
        
        while(!q.empty()) {
            int n = q.front(); q.pop();
            for (int i=0; i<4; i++) {
                auto nn = func(i, n);
                if (nn.first < 10000) {
                    if (check[nn.first] == false) {
                        // 방문하지 않음, 방문하자.
                        q.push(nn.first);
                        check[nn.first] = true;
                        dist[nn.first] = dist[n] + 1;
                        from[nn.first] = n;
                        how[nn.first] = nn.second;
                        
                    }
                }
            }
        }
        // 다 담았고, 
        string answer = "";
        while (start != end) {
            answer += how[end];
            end = from[end];
        }
        reverse(answer.begin(), answer.end());
        cout << answer << endl;
    }

    return 0;
}