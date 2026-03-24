#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
    string answer = "";
    for(auto c: n_str){
        if(answer == "" && c =='0'){
            continue;
        }
        answer += c;
    }
    return answer;
}