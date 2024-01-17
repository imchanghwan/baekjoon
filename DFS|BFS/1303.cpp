#include <iostream>
#include <vector>

using namespace std;

/*
문제 풀이 아이디어
인접한 병사들의 합을 세어 제곱한다.
dfs 재귀함수로 풀리는 문제는 조금만 생각해도 간단하게 풀리는거 같다..

시간 복잡도
N * M 번 반복하고 재귀함수는 방문하지 않고 인접한 병사만 탐색하니깐 배열의 크기만큼 시간이 걸릴거 같고
O(N^2) 이라 생각된다..
N^2 * M^2 의 최대는 100^2 * 100^2 = 10^8 이다.
*/

int N, M;
vector<string> graph; // 전쟁터에 있는 병사 정보 2차원 vector
bool visited[100][100] = { false, }; // 방문 여부 배열
pair<int, int> result = { 0,0 }; // 결과값 white, blue 의 위력 pair

// 배열 인덱스, 팀 문자, 인접한 병사들 합을 인수로 받는다. 병사들 합 인수는 참조로 전달하고 함수는 void 리턴
void dfs(int x, int y, char team, int& sum)
{
	// 인덱스 범위 초과시 리턴
	if (x < 0 || y < 0 || x >= M || y >= N) return;

	// 아직 방문하지 않고, 인접한 같은 팀의 합만 센다.
	if (!visited[x][y] && graph[x][y] == team) {
		sum++;
		visited[x][y] = true; // 방문 처리
		// 상하좌우 인접한 같은 팀만 재귀함수 호출
		dfs(x - 1, y, team, sum);
		dfs(x, y - 1, team, sum);
		dfs(x + 1, y, team, sum);
		dfs(x, y + 1, team, sum);
	}
}

int main()
{
	// 입력 및 초기화
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		graph.push_back(str);
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int white = 0; // 인접한 요소를 다 찾았으면 다시 0으로 초기화 한다.
			dfs(i, j, 'W', white); // 인접한 요소의 합을 white 인수에 참조로 전달한다.
			result.first += white * white; // 위력의 합은 제곱
			
			// 파란 병사도 마찬가지로 똑같이 해준다.
			int blue = 0;
			dfs(i, j, 'B', blue);
			result.second += blue * blue;
		}
	}
	
	// 결과값 출력
	cout << result.first << " " << result.second << endl;
}
