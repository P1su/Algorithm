#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp) {
    string answer = "";
    for(auto c: my_string){
        if(c == alp[0]){
            answer += toupper(c);
        }else{
            answer += c;
        }
    }
    return answer;
}