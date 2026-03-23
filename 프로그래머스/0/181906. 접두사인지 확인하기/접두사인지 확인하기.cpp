#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {
    int answer = 0;
    for(int i = 0 ; i < my_string.length() ; i++){
        if(my_string.substr(0, i).compare(is_prefix) == 0){
            answer = 1;
        }
    }
    return answer;
}