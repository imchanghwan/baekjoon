#include <iostream>
#include <unordered_map>

using namespace std;

int N, M, card;
unordered_map<int, int> m; // key: 카드 숫자, value: 카드의 개수

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> card;
		m[card]++;
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> card;
		cout << m[card] << " "; // value 출력
	}
}
