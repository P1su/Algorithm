#include <bits/stdc++.h> 
#define MAX 1001
using namespace std;

vector<int> G[MAX];
bool isVisit[MAX];

void DFS(int v) {
	for (int i = 0; i < G[v].size(); i++) {
		int k = G[v][i];

		if (isVisit[k] == 0) {
			isVisit[k] = 1;
			cout << k << " ";

			DFS(k);
		}
	}
	
	return;
}

void BFS(int v) {
	queue<int> Q;
	Q.push(v);

	isVisit[v] = 1;

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		for (int i = 0; i < G[cur].size(); i++) {
			int k = G[cur][i];
			if (isVisit[k] == 0) {
				isVisit[k] = 1;
				cout << k << " ";

				Q.push(k);
			}
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, V;
	cin >> N >> M >> V;

	while (M--) {
		int x, y;
		cin >> x >> y;

		G[x].push_back(y);
		G[y].push_back(x);
	}

	for (int i = 1; i <= N; i++) {
		sort(G[i].begin(), G[i].end());
	}

	cout << V << " ";
	isVisit[V] = 1;
	DFS(V);
	cout << endl;

	fill_n(isVisit, MAX, 0);
	cout << V << " ";
	isVisit[V] = 1;
	BFS(V);
} 