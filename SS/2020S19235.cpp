/* 모노미노도미노 */

#include <iostream>
#include <vector>

using namespace std;

void pF(vector<vector<int>> &red, vector<vector<int>> &green, vector<vector<int>> &blue) {
    for (int i=0; i<red.size(); i++) {
        for (int j=0; j<red[0].size(); j++) {
            cout << red[i][j] << " ";
        }
        cout << " ";
        for (int k=0; k<blue[0].size(); k++) {
            cout << blue[i][k] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
    for (int i=0; i<green.size(); i++) {
        for (int j=0; j<green[0].size(); j++) {
            cout << green[i][j] << " ";
        }
        cout << '\n';
    }

    cout << '\n';
}

// 열을 체크하는데, 주어진 vector의 열에 블록이 존재하면 true
bool chkC(int idx, vector<vector<int>> &v) {
    bool result = false;
    for (int i=0; i<v.size(); i++) {
        // 하나라도 1이 존재하면 true
        if (v[i][idx] == 1) {
            result = true;
        }
    }
    return result;
}

// 행을 체크하는데, 주어진 vector의 행에 블록이 존재하면 true
bool chkR(int idx, vector<vector<int>> &v) {
    bool result = false;
    for (int i=0; i<v[0].size(); i++) {
        // 하나라도 1이 존재하면 true
        if (v[idx][i] == 1) {
            result = true;
        }
    }
    return result;
}

int main() {
    vector<vector<int>> red(4, vector<int>(4, 0));
    vector<vector<int>> green(6, vector<int>(4, 0));
    vector<vector<int>> blue(4, vector<int>(6, 0));

    int xx;
    int yy;

    cout << "init\n";
    pF(red, green, blue);

    int point = 0;
    int n;
    cin >> n;
    for (int cnt=0; cnt<n; cnt++) {
        // 입력 받자
        int t, x, y;
        cin >> t >> x >> y;
        cout << "idx: " << cnt+1 << '\n';
        switch (t)
        {
            case 1: {
                // 블록을 타일에 깔자
                red[x][y] = 1;
                pF(red, green, blue);

                // 왼 -> 오
                yy = 5;
                for (int j=0; j<6; j++) {
                    if (blue[x][j] == 1) {
                        // 있다면
                        yy = j-1;
                        break;
                    }
                }
                blue[x][yy] = 1;

                // 위 -> 아래
                xx = 5;
                for (int i=0; i<6; i++) {
                    if (green[i][y] == 1) {
                        // 있다면
                        xx = i-1;
                        break;
                    }
                }
                green[xx][y] = 1;
                break;
            }
            
            case 2: {
                // 1*2
                red[x][y] = 2;
                red[x][y+1] = 2;
                pF(red, green, blue);

                // 전파하자
                // 왼 -> 오
                yy = 4; /* 여기서 문제가 생길 수도 있음 */
                for (int j=0; j<6; j++) {
                    // 하나씩 체크해본다
                    if (blue[x][j]) {
                        yy = j-2;
                        break;
                    }
                }
                blue[x][yy] = 2;
                blue[x][yy+1] = 2;

                // 위 -> 아래
                xx = 5;
                for (int i=0; i<6; i++) {
                    if (green[i][y] || green[i][y+1]) {
                        xx = i-1;
                        break;
                    }
                }
                green[xx][y] = 2;
                green[xx][y+1] = 2;
                break;
            }

            case 3: {
                // 2*1
                red[x][y] = 3;
                red[x+1][y] = 3;
                pF(red, green, blue);

                // 전파하자
                // 왼 -> 오
                yy = 5;
                for (int j=0; j<6; j++) {
                    // 하나씩 체크해본다
                    if (blue[x][j] || blue[x+1][j]) {
                        yy = j-1;
                        break;
                    }
                }
                blue[x][yy] = 3;
                blue[x+1][yy] = 3;

                // 위 -> 아래
                xx = 4;
                for (int i=0; i<6; i++) {
                    if (green[i][y]) {
                        xx = i-2;
                        break;
                    }
                }
                green[xx][y] = 3;
                green[xx+1][y] = 3;
                break;
            }
        }

        // pF(red, green, blue);

        /* 이제 green 과 blue 가 점수가 나는 지 확인 */
        // green
        for (int i=5; i>=0; i--) {
            bool isPossible = true;
            for (int j=0; j<4; j++) {
                // 모두 검사해
                if (green[i][j] == 0) {
                    // 혹시 하나라도 0이라면 false;
                    isPossible = false;
                }
            }
            if (isPossible) {
                // 여전히 true 즉 모두 1이다
                for (int j=0; j<4; j++) {
                    green[i][j] = 0;
                }
                point += 1;

                // i보다 높은 idx 한칸씩 내려야한다.
                for(int k=i-1; k>=0; k--) {
                    for (int j=0; j<4; j++) {
                        green[k+1][j] = green[k][j];
                    }
                }
                for (int j=0; j<4; j++) {
                    green[0][j] = 0;
                }

                for (int j=0; j<4; j++) {
                    if (green[i][j] == 0 && green[i-1][j] != 0) {
                        // 내려가야한다. 
                        if ((green[i-1][j] == 1) || (green[i-1][j] == 3)) {
                            // 내려갈 수 있다.
                            green[i][j] = green[i-1][j];
                        }
                        green[i-1][j] = 0;
                    }
                }
                break;
            }
        }

        //blue
        for (int j=5; j>=0; j--) {
            bool isPossible = true;
            for (int i=0; i<4; i++) {
                // 모두 검사해
                if (blue[i][j] == 0) {
                    // 혹시 하나라도 0이라면 false;
                    isPossible = false;
                }
            }
            if (isPossible) {
                // 여전히 true 즉 모두 1이다
                for (int i=0; i<4; i++) {
                    blue[i][j] = 0;
                }
                point += 1;
                
                // i보다 높은 idx 한칸씩 내려야한다.
                for(int k=j-1; k>=0; k--) {
                    for (int i=0; i<4; i++) {
                        blue[i][k+1] = blue[i][k];
                    }
                }
                for (int i=0; i<4; i++) {
                    blue[0][j] = 0;
                }
                break;
            }
        }

        // 이제 밀자
        /* green */
        for (int it=0; it<2; it++) {
            bool greenIdx2 = false;
            for (int j=0; j<4; j++) {
                if (green[1][j] == 1) {
                    //만약에 존재한다면
                    greenIdx2 = true;
                }
            }
            if (greenIdx2) {
                // 한칸씩 밀자
                for (int i=4; i>=0; i--) {
                    for (int j=0; j<4; j++) {
                        green[i+1][j] = green[i][j];
                    }
                }
                for (int j=0; j<4; j++) {
                    green[0][j] = 0;
                }
            }
        }

        // blue
        for (int it=0; it<2; it++) {
            bool blueIdx2 = false;
            for (int i=0; i<4; i++) {
                if (blue[i][1] != 0) {
                    //만약에 존재한다면
                    blueIdx2 = true;
                }
            }
            if (blueIdx2) {
                // 한칸씩 밀자
                for (int j=4; j>=0; j--) {
                    for (int i=0; i<4; i++) {
                        blue[i][j+1] = blue[i][j];
                    }
                }
                for (int i=0; i<4; i++) {
                    blue[i][0] = 0;
                }
            }
        }
        pF(red, green, blue);
        cout << "point: " << point << '\n';
        // red clear
        for (int i=0; i<red.size(); i++) {
            for (int j=0; j<red[0].size(); j++) {
                red[i][j] = 0;
            }
        }
    }
    return 0;
}