#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
문제 풀이 아이디어
dfs 재귀함수를 사용해서
인접한 음식물을 방문처리 하고
인접한 음식물들 개수를 세어
최대값을 구한다.

시간복잡도
인터넷에 검색해보니
O(N+E)라고 나오는데
인접 리스트로 구현하면
예측이 불가능하다고 한다.
*/


int N, M, K;
bool graph[100][100] = { false, }; // 음식물 위치 좌표

int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,-1,1 };

// 좌표를 인수로 받고, 인접한 음식물 크기를 참조 인수로 전달한다.
void dfs(int x, int y, int &sum)
{
	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

		if (graph[nx][ny]) {
			sum++;
			graph[nx][ny] = false;
			dfs(nx, ny, sum);
		}
	}
}

int main()
{
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) { // k개의 줄만큼 반복하여 좌표를 입력
		int r, c;
		cin >> r >> c;
		graph[r  - 1][c - 1] = true; // 해당 인덱스는 실제 좌표에서 -1
	}

	int max = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int size = 0; // 음식물 크기 0 초기화
			dfs(i, j, size); // 음식물 크기를 참조 인수로 전달해 저장
			if (size > max) max = size; // 음식 물크기와 최대값을 비교해 최대값 구하기
		}
	}
	// 출력
	cout << max;
}
