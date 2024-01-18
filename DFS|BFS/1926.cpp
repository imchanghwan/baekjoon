#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
어떤 문제에 dfs를 쓰고 bfs를 써야되는지 아직 감이 잘 안잡힌다.
개인적으로 이 문제도 dfs가 더 효율적이고 편해서 dfs를 계속 쓰게되는거 같다.

문제 풀이 아이디어
dfs 재귀함수를 사용해서 인접한 i,j의 1로 된 칸을 세어 그림의 넓이를 구하고
인접한 그림일시 true를 리턴해서 그림의 개수를 센다.
그림 넓이 최대값은 우선순위 큐를 사용해서 구한다.

시간 복잡도
n*m의 최대는 25*10^4 25만
우선순위 큐는 logN
시간 복잡도는 O(N^2) ?
*/

int n, m;
vector<vector<bool>> graph;

bool dfs(int x, int y, int& sum)
{
	// 인덱스 범위 초과시 false 리턴
	if (x < 0 || y < 0 || x >= n || y >= m) return false;

	// 인접한 그림이면 방문 처리하고 인접한 그림 칸을 세어 넓이를 구한다.
	if (graph[x][y]) {
		sum++; // 인접한 그림 칸의 합
		graph[x][y] = false; // 방문 처리
		// 상하좌우 인접한 그림 재귀함수 호출
		dfs(x - 1, y, sum);
		dfs(x, y - 1, sum);
		dfs(x + 1, y, sum);
		dfs(x, y + 1, sum);
		return true;
	}
	return false;
}


int main()
{
	// 입력 및 초기화
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		vector<bool> v;
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			v.push_back(x);
		}
		graph.push_back(v);
	}

	int count = 0; // 그림 개수
	priority_queue<int> max; // 그림 넓이 우선순위 큐로 최대값 구하기

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp = 0; // 인접한 그림의 넓이
			if (dfs(i, j, temp)) count++;
			max.push(temp);
		}
	}
	// 출력
	cout << count << '\n' << max.top();
}
