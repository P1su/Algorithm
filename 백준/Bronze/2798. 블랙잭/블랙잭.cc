#include <iostream>
using namespace std;

int main() {
   int N, M, sum, MAX =0;
   cin>>N>>M;
   int arr[N];
   for(int i = 0 ; i <N ;i++){
      cin>>arr[i];
   }
   
   for(int i = 0 ; i < N-2 ; i++){
      for(int j = i+1 ; j < N-1 ; j++){
         for(int k = j+1 ; k < N ; k++){
         	sum = arr[i] + arr[j] + arr[k];
         	if(sum >= MAX &&  sum <=M)MAX = sum;
         	sum = 0;
		 }
      }
   }
   cout<<MAX;
}