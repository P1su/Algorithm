#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int x = 1;
    int y = 0;
    
    for(int i = 0 ; i < num_list.size() ; i++){
        x *= num_list[i];
        y += num_list[i];
    }
    
    if(x > y*y){
        return 0;
    }else {
        return 1;
    }
}