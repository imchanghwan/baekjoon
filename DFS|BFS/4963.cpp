#include<iostream>
#include<vector>

using namespace std;

int w, h;
vector<vector<int>> graph; // 육지와 바다 정보를 저장하는 2차원 vector
int result; // 출력 결과값 vector

bool dfs(int x, int y)
{
	// 인덱스 범위 초과시 false 리턴
	if (x < 0 || y < 0 || x >= h || y >= w) return false;

	if (graph[x][y]) {
		// 육지라면 재귀함수가 무한 반복하지 않게 방문처리한다.
		graph[x][y] = 0;
		// 육지와 인접한 상하좌우 대각선 네방향에 모두 탐색한다.
		dfs(x - 1, y);
		dfs(x, y - 1);
		dfs(x + 1, y);
		dfs(x, y + 1);
		dfs(x - 1, y - 1);
		dfs(x + 1, y - 1);
		dfs(x - 1, y + 1);
		dfs(x + 1, y + 1);
		return true;
	}
	return false;
}

int main()
{
	while (true) {
		graph.clear(); // vector를 빈 vector로 초기화
        result = 0; // result 출력 값도 0으로 초기화
        
		cin >> w >> h;
        
        if (w == 0 && h == 0) break; // w와 h 입력이 0 0 이면 종료

		// 입력 및 초기화
		for (int i = 0; i < h; i++) {
			vector<int> v;
			for (int j = 0; j < w; j++) {
				int x;
				cin >> x;
				v.push_back(x);
			}
			graph.push_back(v);
		}

		// 각 정사각형 칸 마다 육지와 인접한 땅을 dfs 재귀함수로 탐색하고, 탐색이 끝나면 true를 반환하여 result +1 증가
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (dfs(i, j)) {
					result++;
				}
			}
		}

		// 결과 출력
		cout << result << endl;
	}
}
