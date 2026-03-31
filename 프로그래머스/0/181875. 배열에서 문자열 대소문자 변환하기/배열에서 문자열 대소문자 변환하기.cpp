#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    
    for(int i = 0 ; i < strArr.size() ; i++){
        if(i % 2 == 1){
            for(auto &c: strArr[i]){
                c = toupper(c);
            }
        }else{
            for(auto &c: strArr[i]){
                c = tolower(c);
            }
        }
    }
    return strArr;
}