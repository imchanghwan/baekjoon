#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int w, h;
vector<vector<int>> graph;
vector<int> result;

bool dfs(int x, int y)
{
	if (x < 0 || y < 0 || x >= h || y >= w) return false;

	if (graph[x][y]) {
		graph[x][y] = 0;
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
	do {
		graph.clear();

		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			vector<int> v;
			for (int j = 0; j < w; j++) {
				int x;
				cin >> x;
				v.push_back(x);
			}
			graph.push_back(v);
		}

		int count = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (dfs(i, j)) {
					count++;
				}
			}
		}
		result.push_back(count);

	} while (w != 0 && h != 0);

	for (int i = 0; i < result.size() - 1; i++)
		cout << result[i] << endl;
}
