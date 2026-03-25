#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> arr) {
    int answer = 0;
    int len = arr[0].size();
    
    for(int i = 0 ; i < len ; i++){
        bool flag = 0;
        for(int j = 0 ; j < len ; j++){
            if(arr[i][j] != arr[j][i]){
                flag = 1;
            }
        }
        if(flag){
            return 0;
        }
    }
    return 1;
}