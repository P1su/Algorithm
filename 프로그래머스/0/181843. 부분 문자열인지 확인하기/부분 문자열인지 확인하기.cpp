#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string target) {
    int answer = 0;
    int len = target.length();
    
    for(int i = 0 ; i < my_string.length() ; i++){
        if(target.compare(my_string.substr(i,len)) == 0){
            answer = 1;
            break;
        }    
    }
    return answer;
}