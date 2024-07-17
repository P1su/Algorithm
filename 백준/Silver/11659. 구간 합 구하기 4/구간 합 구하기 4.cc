#include <bits/stdc++.h> 
using namespace std;

int arr[100001];
int D[100001];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin>>N>>M;
	for(int i = 1 ; i <= N ; i++)cin>>arr[i];
	
	D[1] = arr[1];
	for(int i = 2 ; i <= N ;i++){
		D[i] = D[i-1] + arr[i];
	}
	
	while(M--){
		int i, j;
		cin>>i>>j;
		if(i == 1)cout<<D[j]<<"\n";
		else cout<<D[j]-D[i-1]<<"\n";
		
	}

}