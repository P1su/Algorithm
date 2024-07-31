#include <iostream>
using namespace std;
int L, C;
char alph[16], temp[16];
bool visited[16] = {0,};

void sort (char* temp){
	for(int i = 0 ; i < C ; i++){
		int j=i;
		for(int k = i+1 ; k < C ;k++){
			if(temp[j]> temp[k])j = k;
		} 
		swap(temp[i], temp[j]);
	}
}

void go(int num, int start){

	if( num == L ){
		int cnt1 = 0, cnt2 =0;
		for(int i = 0 ; i < L ; i++){
			if(alph[i] =='a' || alph[i] =='e' || alph[i] =='i' || alph[i] == 'o' || alph[i] == 'u')cnt1++;
			else cnt2++;
			
		}
		if(cnt1 >=1 &&  cnt2>=2 ){
			for(int i = 0 ; i < L ;i++){
				cout<<alph[i];
			}
			cout<<"\n";
		}
		
		return;
	}
	
	for (int j = start ; j < C; j++){
		if ( visited[j] != true){
			visited[j] = true;
			alph[num] = temp[j];
			go(num + 1, j+1);
			visited[j] = false;
		}
	}
}

int main(){
	cin>>L>>C;
	for(int i = 0 ; i < C ; i++){
		cin>>temp[i];
	}
	sort(temp);
	go(0,0);
}