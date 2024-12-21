#include <bits/stdc++.h> 
using namespace std;

vector<int> arr[100];
bool isVirus[100];

void Search(int x) {
	for (int i = 0; i < arr[x].size(); i++) {
		int k = arr[x][i];

		if (isVirus[k] == 0) {
			isVirus[k] = 1;
			Search(k);
		}

	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, p, ans = 0;
	cin >> N >> p;
	for(int i = 0; i < p; i++) {
		int x, y;
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	
	isVirus[1] = 1;
	Search(1);

	for (int i = 2; i <= N; i++) {
		ans += isVirus[i];
	}
	cout << ans;
} 