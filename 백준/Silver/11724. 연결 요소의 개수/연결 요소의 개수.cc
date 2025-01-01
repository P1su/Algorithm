#include <bits/stdc++.h> 
#define MAX 1001
using namespace std;

vector<int> V[MAX];
bool isVisited[MAX];

void DFS(int x) {
	for (int i = 0; i < V[x].size(); i++) {
		int k = V[x][i];
		
		if (isVisited[k] == 0) {
			isVisited[k] = 1;
			DFS(k);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, ans = 0;
	cin >> N >> M;

	while (M--) {
		int x, y;
		cin >> x >> y;
		
		V[x].push_back(y);
		V[y].push_back(x);
	}

	for (int i = 1; i <= N; i++) {
		if (isVisited[i] == 1)continue;

		DFS(i);
		ans++;
	}

	cout << ans;
} 