#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	int n;
	while (T--) {
		cin >> n;
		int ans = 1;

		map<string, int> M;
		for (int i = 0; i < n; i++) {
			string x, y;
			cin >> x >> y;
			
			M[y]++;
		}

		for (auto iter : M) {
			ans *= (iter.second + 1);
		}
		cout << ans - 1<<endl;
		M.clear();
	}
} 