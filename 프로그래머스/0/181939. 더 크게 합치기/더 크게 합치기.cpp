#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    string x = to_string(a) + to_string(b);
    string y = to_string(b) + to_string(a);
    
    if(x > y){
        return stoi(x);
    }else{
        return stoi(y);
    }
    
}