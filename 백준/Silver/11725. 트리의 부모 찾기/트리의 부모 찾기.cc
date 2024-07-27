#include <bits/stdc++.h> 
using namespace std;
#define MAX 100002

int N, M;
vector<int> edges[MAX];
int parent[MAX];
bool visited[MAX];

void Travel(int x) {
	for (int i = 0; i < edges[x].size(); i++) {
		int y = edges[x][i];

		if (!visited[y]) {
			visited[y] = true;
			parent[y] = x;

			Travel(y);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N-1; i++) {
		int x, y;
		cin >> x >> y;

		edges[x].push_back(y);
		edges[y].push_back(x);

	}
	visited[0] = true;
	Travel(1);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}
} 