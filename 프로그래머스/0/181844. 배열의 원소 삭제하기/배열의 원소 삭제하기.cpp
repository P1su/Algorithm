#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;
    
    for(auto target: arr){
        bool flag = 1;
        for(auto delNum: delete_list){
            if(target == delNum){
                flag = 0;
            }
        }
        if(flag){
            answer.push_back(target);
        }
    }
    return answer;
}