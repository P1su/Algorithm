#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    string temp = "";
    
    for(auto c: my_string){
        if(c == ' '){
            answer.push_back(temp);
            temp = "";
        }else{
            temp += c;
        }
        
    }
    
    if(answer.empty()){
        answer.push_back(my_string);
    }else{
        answer.push_back(temp);
    }
    return answer;
}