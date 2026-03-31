#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int size = num_list.size();
    
    if(size > 10){
        for(auto n: num_list){
            answer += n;
        }
    }else{
        answer = 1;
        for(auto n: num_list){
            answer *= n;
        }
    }
    return answer;
}