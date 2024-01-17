#include <iostream>
#include <vector>

using namespace std;

int R, C, N;

vector<vector<bool>> graph;
vector<vector<int>> timer;

int main() {
    cin >> R >> C >> N;

    for (int i = 0; i < R; i++) {
        vector<bool> v1;
        vector<int> v2;
        for (int j = 0; j < C; j++) {
            char x;
            cin >> x;
            if (x == 'O') {
                v1.push_back(true);
                v2.push_back(3);
            }
            else {
                v1.push_back(false);
                v2.push_back(0);
            }
        }
        graph.push_back(v1);
        timer.push_back(v2);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                if (graph[j][k]) timer[j][k] -=1;
                if (i % 2 == 0) {
                    if (!graph[j][k]) { 
                        graph[j][k] = true;
                        timer[j][k] = 3;
                    }
                }
                else {
                    if (graph[j][k] && timer[j][k] == 0) {
                        graph[j][k] = false; // 폭탄이 있던 위치
                        timer[j][k] = 0;
                        if (j - 1 >= 0 && timer[j -1][k] > 1) { // 폭탄이 있는 위치 y-1(위) 0이상이어야 함
                            graph[j - 1][k] = false;
                            timer[j - 1][k] = 0;
                        }
                        if (k - 1 >= 0 && timer[j][k - 1] > 1) { // 폭탄이 있는 위치 x-1(좌) 0이상이어야 함
                            graph[j][k - 1] = false;
                            timer[j][k - 1] = 0;
                        }
                        if (j + 1 < R && timer[j + 1][k] > 1) { // 폭탄이 있는 위치 y+1(아래) r보다 작아 함
                            graph[j + 1][k] = false;
                            timer[j + 1][k] = 0;
                        }
                        if (k + 1 < C && timer[j][k + 1] > 1) { // 폭탄이 있는 위치 x+1(우) c보다 작아 함
                            graph[j][k + 1] = false;
                            timer[j][k + 1] = 0;
                        }
                    }
                }
            }
        }
    }

    for (int j = 0; j < R; j++) {
        for (int k = 0; k < C; k++) {
            if (graph[j][k])
                cout << 'O';
            else
                cout << '.';
        }
        cout << endl;
    }
}
