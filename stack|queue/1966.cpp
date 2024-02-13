#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M;
vector<pair<int, int>> q; // 중요도, index
int x;

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		for (int j = 0; j < N; j++) {
			cin >> x;
			q.push_back({ x, j });
		}

		pair<int, int> max = *max_element(q.begin(), q.end());

        int result[100];
        int cnt = 0;

        while (!q.empty()) {
            max = *max_element(q.begin(), q.end());
            if (q.front().first < max.first) {
                q.push_back(q.front());
                q.erase(q.begin());
            }
            else {
                cnt++;
                result[q.front().second] = cnt;
                q.erase(q.begin());
            }
        }

        q.clear();

        cout << result[M] << '\n';
	}
}
