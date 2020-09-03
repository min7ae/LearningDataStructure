#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int answer = 0;
    const int row = 9;
    const int col = 9;
    
    string str;
    cin >> str;

    int numberRow = str[0] - 'a' + 1;
    int numberCol = str[1] - '1' + 1;

    vector<vector<int>> Arrow(2, vector<int>(8, 0)); 
    Arrow = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    for(int i=0; i<Arrow.size(); i++) {
        int curRow = numberRow + Arrow[i][0];
        int curCol = numberCol + Arrow[i][1];
        if (1 <= curRow && curRow <= 8 && 1 <= curCol && curCol <= 8) {
            answer += 1;
        }
    }
    cout << answer;
    return 0;
}