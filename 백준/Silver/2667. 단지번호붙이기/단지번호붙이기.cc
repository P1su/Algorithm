#include <bits/stdc++.h> 
using namespace std;

char board[25][25];
bool vis[25][25];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N;
vector<int> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	queue<pair<int,int> > Q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == '1' && vis[i][j] == 0) {
				vis[i][j] = 1;
				
				Q.push({i,j});
				int cnt = 0;

				while (!Q.empty()) {
					pair<int, int> cur = Q.front();
					Q.pop();
					cnt++;

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
						if (board[nx][ny] == '0' || vis[nx][ny] == 1)continue;

						vis[nx][ny] = 1;
						Q.push({ nx, ny });
					}

				}
				ans.push_back(cnt);
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}

} 