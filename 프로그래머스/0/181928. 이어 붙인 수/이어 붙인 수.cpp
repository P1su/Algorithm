#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    string odd;
    string even;
    for(auto x: num_list){
        if(x % 2 == 1){
            odd += to_string(x);
        }else{
            even += to_string(x);
        }
    }
    
    return stoi(odd) + stoi(even);
}