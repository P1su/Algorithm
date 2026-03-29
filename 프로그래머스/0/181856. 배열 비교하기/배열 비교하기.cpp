#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    int answer = 0;
    int size1 = arr1.size();
    int size2 = arr2.size();
    
    if(size1 > size2){
        return 1;
    }else if(size1 < size2){
        return -1;
    }else{
        int sum1 = 0;
        int sum2 = 0;
        
        for(int i=0 ;i<size1 ; i++){
            sum1 += arr1[i];
            sum2 += arr2[i];
        }
        if(sum1 > sum2){
            return 1;
        }else if(sum1 < sum2){
            return -1;
        }else{
            return 0;
        }
    }
}