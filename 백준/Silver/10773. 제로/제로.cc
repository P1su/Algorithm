#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, tmp, ans=0;
	cin>>N;
	stack<int>S;
	
	while(N--){
		cin>>tmp;
		if(tmp == 0)S.pop();
		else S.push(tmp);
	}
	
	while(!S.empty()){
		ans+=S.top();
		S.pop();
	}
	
	cout<<ans;
}