#include <bits/stdc++.h> 
using namespace std;
#define MAX 100002

int N, ans = 0, en = 0;
vector<pair<int, int>> edges[MAX];
bool visited[MAX];

void DFS(int x, int dist) {
	if (visited[x])return;

	//최대값 갱신 후 먼 노드 갱신
	if (ans < dist) {
		ans = dist;
		en = x;
	}

	for (int i = 0; i < edges[x].size(); i++) {
		visited[x] = true;
		DFS(edges[x][i].first, dist + edges[x][i].second);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		//서로 연결된 노드와 그에 따른 가중치 삽입
		edges[a].push_back({ b,c });
		edges[b].push_back({ a,c });
	}

	//루트부터 탐색 시작
	DFS(1, 0);

	//방문 배열 초기화
	memset(visited, false, sizeof(visited));
	//루트에서 가장 먼 노드에서부터 다시 탐색
	DFS(en, 0);

	cout << ans;
} 